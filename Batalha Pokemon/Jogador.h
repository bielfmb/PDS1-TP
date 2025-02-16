#include <stdio.h>
#include "Pokemon.h"

#ifndef JOGADOR_H
#define JOGADOR_H

struct Jogador {
    int quantPokemon;
    Pokemon *pokemon;

    int contarPokemonVivos();
    void executarTurno(Jogador *defensor, int *numAtacante, int *numDefensor);
    void definirVencedor(Jogador *jogador2);
    void mostrarSobreviventes();
    void mostrarDerrotados();
};

int Jogador::contarPokemonVivos() {
    int vivos = 0;
    for (int i = 0; i < quantPokemon; i++) {
        if (pokemon[i].vida > 0) {
            vivos++;
        }
    }
    return vivos;
}

void Jogador::executarTurno(Jogador *defensor, int *numAtacante, int *numDefensor) {
    pokemon[*numAtacante].atacar(defensor->pokemon[*numDefensor]);
    
    if (defensor->pokemon[*numDefensor].vida <= 0) {
        printf("%s venceu %s.\n", pokemon[*numAtacante].nome, defensor->pokemon[*numDefensor].nome);
        if (defensor->contarPokemonVivos() <= 0) {
            return;
        }
        (*numDefensor)++;
    }
}

void Jogador::definirVencedor(Jogador *jogador2) {
    int p1 = 0, p2 = 0;

    //Loop enquanto os jogadores ainda tiverem Pokemon   
    while (contarPokemonVivos() > 0 && jogador2->contarPokemonVivos() > 0) {

        // Turno do jogador 1 atacando o jogador 2
        executarTurno(jogador2, &p1, &p2);
        if (jogador2->contarPokemonVivos() <= 0) {
            printf("Jogador 1 venceu!\n");
            break;
        }

        // Turno do jogador 2 atacando o jogador 1
        executarTurno(this, &p2, &p1);
        if (contarPokemonVivos() <= 0) {
            printf("Jogador 2 venceu!\n");
            break;
        }
    }
}

void Jogador::mostrarSobreviventes() {
    for (int i = 0; i < quantPokemon; i++) {
        if (pokemon[i].vida > 0) printf("%s\n", pokemon[i].nome);
    }
}

void Jogador::mostrarDerrotados() {
    for (int i = 0; i < quantPokemon; i++) {
        if (pokemon[i].vida <= 0) printf("%s\n", pokemon[i].nome);
    }
}

#endif