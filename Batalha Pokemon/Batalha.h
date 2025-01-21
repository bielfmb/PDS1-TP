#include <stdio.h>
#include <string.h>
#include "Pokemon.h"
#include "Jogador.h"

void defJogador1(Jogador jogador1, FILE* dados) {

}

int efetividade(char* tipoPokemon1, char* tipoPokemon2) {
    //Verifica se um ataque é super efetivo
    if ((strcmp(tipoPokemon1, "eletrico") && strcmp(tipoPokemon2, "agua")) ||
        (strcmp(tipoPokemon1, "agua") && strcmp(tipoPokemon2, "fogo")) ||
        (strcmp(tipoPokemon1, "fogo") && strcmp(tipoPokemon2, "gelo")) ||
        (strcmp(tipoPokemon1, "gelo") && strcmp(tipoPokemon2, "pedra")) ||
        (strcmp(tipoPokemon1, "pedra") && strcmp(tipoPokemon2, "eletrico")) 
        ) {
        return 1;
    }
    
    //Verifica se um ataque não é muito efetivo
    else if ((strcmp(tipoPokemon1, "eletrico") && strcmp(tipoPokemon2, "pedra")) ||
        (strcmp(tipoPokemon1, "agua") && strcmp(tipoPokemon2, "eletrico")) ||
        (strcmp(tipoPokemon1, "fogo") && strcmp(tipoPokemon2, "agua")) ||
        (strcmp(tipoPokemon1, "gelo") && strcmp(tipoPokemon2, "fogo")) ||
        (strcmp(tipoPokemon1, "pedra") && strcmp(tipoPokemon2, "gelo")) 
        ) {
        return 2;
    }

    //Caso não haja relação de efetividade
    return 3;
    
}

float calcularDano(Pokemon* atacante, Pokemon* defensor) {
    
}

//Realiza uma batalha entre 2 pokemon dos jogadores
void batalha(Jogador* atacante, Jogador* defensor, int numeroPokemon1, int numeroPokemon2) {
    Pokemon* p1 = &atacante->pokemon[numeroPokemon1];
    Pokemon* p2 = &defensor->pokemon[numeroPokemon2];

    switch (efetividade(p1->tipo, p2->tipo)) {
        //Se efetivo, o ataque pode tirar 20% a mais da vida do adversário
        case 1:
            if ((p1->ataque * 1.2) > p2->defesa) {
                p2->vida -= (p1->ataque * 1.2) - (p2->defesa);
            }
            else p2->vida -= 1;
            break;

        //Se não efetivo, o ataque pode tirar 20% a menos da vida do adversário
        case 2:
            if ((p1->ataque * 0.8) > p2->defesa) {
                p2->vida -= (p1->ataque * 0.8) - (p2->defesa);
            }
            else p2->vida -= 1;

        //Se não há relação, caso o ataque de p1 seja maior que a defesa de p2, esse valor é subtraído da vida de p2. Caso não, p2 perde 1 de vida
        default:
            if (p1->ataque > p2->defesa) {
                p2->vida -= p1->ataque;
            }
            else p2->vida -= 1;
            break;
    }
}

void resultado(Jogador* jogador1, Jogador* jogador2) {
    int i = 0, p1 = 0, p2 = 0;
    while (1) {
        batalha(jogador1, jogador2, p1, p2);
        if (jogador2->pokemon[p2].vida <= 0) {
            printf("%s venceu %s.", jogador1->pokemon[p1].nome, jogador2->pokemon[p2].nome);
            p2++;
            jogador2->quantidadePokemon--;
        }

        if (jogador1->quantidadePokemon <= 0) {
            printf("Jogador 2 venceu!");
            break;
        }
        
        batalha(jogador2, jogador1, p2, p1);
        if (jogador1->pokemon[p1].vida <= 0) {
            printf("%s venceu %s.", jogador2->pokemon[p2].nome, jogador1->pokemon[p1].nome);
            p1++;
            jogador1->quantidadePokemon--;
        }

        if (jogador2->quantidadePokemon <= 0) {
            printf("Jogador 1 venceu!");
            break;
        }
    }

    printf("Pokemon sobreviventes: ");
    for (int i = 0; i < jogador1->quantidadePokemon + jogador2->quantidadePokemon; i++) {
        if (jogador1->pokemon[i].vida <= 0) printf("%s\n", jogador1->pokemon[i].nome);
        else if (jogador2->pokemon[i].vida <= 0) printf("%s\n", jogador2->pokemon[i].nome);
        else printf("%s\n%s\n", jogador1->pokemon[i].nome, jogador2->pokemon[i].nome);
    }
}