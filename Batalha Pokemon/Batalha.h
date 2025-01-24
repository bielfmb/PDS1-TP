#include <stdio.h>
#include <string.h>
#include "Jogador.h"

int efetividade(char* tipoPokemon1, char* tipoPokemon2) {
    //Verifica se um ataque é super efetivo
    if ((strcmp(tipoPokemon1, "eletrico") == 0 && strcmp(tipoPokemon2, "agua") == 0) ||
        (strcmp(tipoPokemon1, "agua") == 0 && strcmp(tipoPokemon2, "fogo") == 0) ||
        (strcmp(tipoPokemon1, "fogo") == 0 && strcmp(tipoPokemon2, "gelo") == 0) ||
        (strcmp(tipoPokemon1, "gelo") == 0 && strcmp(tipoPokemon2, "pedra") == 0) ||
        (strcmp(tipoPokemon1, "pedra") == 0 && strcmp(tipoPokemon2, "eletrico") == 0) 
        ) {
        return 1;
    }
    
    //Verifica se um ataque não é muito efetivo
    if ((strcmp(tipoPokemon1, "eletrico") == 0 && strcmp(tipoPokemon2, "pedra") == 0) ||
        (strcmp(tipoPokemon1, "agua") == 0 && strcmp(tipoPokemon2, "eletrico") == 0) ||
        (strcmp(tipoPokemon1, "fogo") == 0 && strcmp(tipoPokemon2, "agua") == 0) ||
        (strcmp(tipoPokemon1, "gelo") == 0 && strcmp(tipoPokemon2, "fogo") == 0) ||
        (strcmp(tipoPokemon1, "pedra") == 0 && strcmp(tipoPokemon2, "gelo") == 0) 
        ) {
        return 2;
    }

    //Caso não haja relação de efetividade
    return 0;
}

//Calcula o dano a partir do efeito, retorna 1 caso a defesa seja maior que o ataque
float calcularDano(Pokemon *atacante, Pokemon *defensor, float efeito) {
    float dano = (atacante->ataque * efeito) - defensor->defesa;
    
    if (dano <= 0) return 1;
    return dano;
}

//Realiza uma batalha entre 2 pokemon dos jogadores
void batalhar(Jogador *atacante, Jogador *defensor, int *numAtacante, int *numDefensor) {
    Pokemon *p1 = &atacante->pokemon[*numAtacante];
    Pokemon *p2 = &defensor->pokemon[*numDefensor];

    //Se efetivo, o ataque pode tirar 20% a mais da vida do adversário
    if (efetividade(p1->tipo, p2->tipo) == 1) {
        p2->vida -= calcularDano(p1, p2, 1.2);
    }

    //Se não efetivo, o ataque pode tirar 20% a menos da vida do adversário
    else if (efetividade(p1->tipo, p2->tipo) == 2) {
        p2->vida -= calcularDano(p1, p2, 0.8);
    }

    //Se não há relação, caso o ataque de p1 seja maior que a defesa de p2, esse valor é subtraído da vida de p2. Caso não, p2 perde 1 de vida
    else {
        p2->vida -= calcularDano(p1, p2, 1.0);
    }
}

int verificarFim(Jogador *jogador) {
    return (jogador->quantPokemon <= 0);
}

void simularTurno(Jogador *atacante, Jogador *defensor, int *numAtacante, int *numDefensor) {
    batalhar(atacante, defensor, numAtacante, numDefensor);

    if (defensor->pokemon[*numDefensor].vida <= 0) {
        printf("%s venceu %s.\n", atacante->pokemon[*numAtacante].nome, defensor->pokemon[*numDefensor].nome);
        if (*numDefensor >= defensor->quantPokemon || verificarFim(defensor)) {
            return;
        }
        (*numDefensor)++;
        defensor->quantPokemon--;
    }

    //Se o defensor não tiver mais Pokémons, a batalha termina
    if (verificarFim(defensor)) {
        return;
    }
}

void resultado(Jogador *jogador1, Jogador *jogador2) {
    int p1 = 0, p2 = 0;

    //Loop enquanto os jogadores ainda tiverem Pokémons 
    while (!verificarFim(jogador1) && !jogador2->quantPokemon) {

        // Turno do jogador 1 atacando o jogador 2
        simularTurno(jogador1, jogador2, &p1, &p2);
        if (verificarFim(jogador2)) {
            printf("Jogador 1 venceu!\n");
            break;
        }

        // Turno do jogador 2 atacando o jogador 1
        simularTurno(jogador2, jogador1, &p2, &p1);
        if (verificarFim(jogador1)) {
            printf("Jogador 2 venceu!\n");
            break;
        }
    }
}