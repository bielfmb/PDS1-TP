#include <stdio.h>
#include <string.h>
#include "Jogador.h"
#include "Pokemon.h"

#ifndef BATALHA_H
#define BATALHA_H

int efetividade(char* tipoAtacante, char* tipoDefensor) {
    //Verifica se um ataque é super efetivo
    if ((strcmp(tipoAtacante, "eletrico") == 0) && (strcmp(tipoDefensor, "agua") == 0)) return 1;
    if ((strcmp(tipoAtacante, "agua") == 0) && (strcmp(tipoDefensor, "fogo") == 0)) return 1;
    if ((strcmp(tipoAtacante, "fogo") == 0) && (strcmp(tipoDefensor, "gelo") == 0)) return 1;
    if ((strcmp(tipoAtacante, "gelo") == 0) && (strcmp(tipoDefensor, "pedra") == 0)) return 1;
    if ((strcmp(tipoAtacante, "pedra") == 0) && (strcmp(tipoDefensor, "eletrico") == 0)) return 1;
    
    //Verifica se um ataque não é muito efetivo
    if ((strcmp(tipoAtacante, "eletrico") == 0) && (strcmp(tipoDefensor, "pedra") == 0)) return 2;
    if ((strcmp(tipoAtacante, "agua") == 0) && (strcmp(tipoDefensor, "eletrico") == 0)) return 2;
    if ((strcmp(tipoAtacante, "fogo") == 0) && (strcmp(tipoDefensor, "agua") == 0)) return 2;
    if ((strcmp(tipoAtacante, "gelo") == 0) && (strcmp(tipoDefensor, "fogo") == 0)) return 2;
    if ((strcmp(tipoAtacante, "pedra") == 0) && (strcmp(tipoDefensor, "gelo") == 0)) return 2;

    //Caso não haja relação de efetividade
    return 0;
}

//Calcula o dano a partir do efeito, retorna 1 caso a defesa seja maior que o ataque
float calcularDano(Pokemon *atacante, Pokemon *defensor, float efeito) {
    float dano = (atacante->ataque * efeito) - defensor->defesa;
    
    if (dano <= 0.0) return 1.0;
    return dano;
}

//Realiza uma batalha entre 2 pokemon dos jogadores
void batalhar(Jogador *atacante, Jogador *defensor, int *numAtacante, int *numDefensor) {
    Pokemon *p1 = &atacante->pokemon[*numAtacante];
    Pokemon *p2 = &defensor->pokemon[*numDefensor];

    //Se efetivo, o ataque pode tirar 20% a mais da vida do adversário
    if (efetividade(p1->tipo, p2->tipo) == 1) {
        if ((p2->vida - calcularDano(p1, p2, 1.2)) <= 0.0) p2->vida = 0.0;
        else p2->vida -= calcularDano(p1, p2, 1.2);
    }

    //Se não efetivo, o ataque pode tirar 20% a menos da vida do adversário
    else if (efetividade(p1->tipo, p2->tipo) == 2) {
        if ((p2->vida - calcularDano(p1, p2, 0.8)) <= 0) p2->vida = 0;
        else p2->vida -= calcularDano(p1, p2, 0.8);
    }

    //Se não há relação, caso o ataque de p1 seja maior que a defesa de p2, esse valor é subtraído da vida de p2. Caso não, p2 perde 1 de vida
    else {
        if ((p2->vida - calcularDano(p1, p2, 1.0)) <= 0) p2->vida = 0;
        else p2->vida -= calcularDano(p1, p2, 1.0);
    }
}

int contarPokemonVivos(Jogador *jogador) {
    int vivos = 0;
    for (int i = 0; i < jogador->quantPokemon; i++) {
        if (jogador->pokemon[i].vida > 0) {
            vivos++;
        }
    }
    return vivos;
}

void simularTurno(Jogador *atacante, Jogador *defensor, int *numAtacante, int *numDefensor) {
    batalhar(atacante, defensor, numAtacante, numDefensor);

    if (defensor->pokemon[*numDefensor].vida <= 0) {
        printf("%s venceu %s.\n", atacante->pokemon[*numAtacante].nome, defensor->pokemon[*numDefensor].nome);
        if (contarPokemonVivos(defensor) <= 0) {
            return;
        }
        (*numDefensor)++;

        //Caso o defensor tenha sido derrotado, é a vez do próximo do time defender 
        simularTurno(atacante, defensor, numAtacante, numDefensor);
    }
}

void mostrarResultado(Jogador *jogador1, Jogador *jogador2) {
    int p1 = 0, p2 = 0;

    //Loop enquanto os jogadores ainda tiverem Pokémons 
    while (contarPokemonVivos(jogador1) > 0 && contarPokemonVivos(jogador2) > 0) {

        // Turno do jogador 1 atacando o jogador 2
        simularTurno(jogador1, jogador2, &p1, &p2);
        if (contarPokemonVivos(jogador2) <= 0) {
            printf("Jogador 1 venceu!\n");
            break;
        }

        // Turno do jogador 2 atacando o jogador 1
        simularTurno(jogador2, jogador1, &p2, &p1);
        if (contarPokemonVivos(jogador1) <= 0) {
            printf("Jogador 2 venceu!\n");
            break;
        }
    }
}


void mostrarSobreviventes(Jogador *jogador) {
    for (int i = 0; i < jogador->quantPokemon; i++) {
        if (jogador->pokemon[i].vida > 0) printf("%s\n", jogador->pokemon[i].nome);
    }
}

void mostrarDerrotados(Jogador *jogador) {
    for (int i = 0; i < jogador->quantPokemon; i++) {
        if (jogador->pokemon[i].vida <= 0) printf("%s\n", jogador->pokemon[i].nome);
    }
}


#endif