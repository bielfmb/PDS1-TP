#include <stdio.h>
#include <string.h>
#include "Jogador.h"

int efetividade(char tipoPokemon1[], char tipoPokemon2[]) {
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
    else if ((strcmp(tipoPokemon1, "eletrico") == 0 && strcmp(tipoPokemon2, "pedra") == 0) ||
        (strcmp(tipoPokemon1, "agua") == 0 && strcmp(tipoPokemon2, "eletrico") == 0) ||
        (strcmp(tipoPokemon1, "fogo") == 0 && strcmp(tipoPokemon2, "agua") == 0) ||
        (strcmp(tipoPokemon1, "gelo") == 0 && strcmp(tipoPokemon2, "fogo") == 0) ||
        (strcmp(tipoPokemon1, "pedra") == 0 && strcmp(tipoPokemon2, "gelo") == 0) 
        ) {
        return 2;
    }

    //Caso não haja relação de efetividade
    return 3;
    
}

float calcularDano(struct Pokemon atacante, struct Pokemon defensor, float efeito) {
    float dano = atacante.ataque - defensor.defesa;
    
    if (dano <= 0) return 1;
    return dano;
}

//Realiza uma batalha entre 2 pokemon dos jogadores
void batalhar(struct Jogador atacante, struct Jogador defensor, int quantPokemon1, int quantPokemon2) {
    struct Pokemon p1 = atacante.pokemon[quantPokemon1];
    struct Pokemon p2 = defensor.pokemon[quantPokemon2];

    float efeito;
    switch (efetividade(p1.tipo, p2.tipo)) {
        //Se efetivo, o ataque pode tirar 20% a mais da vida do adversário
        case 1:
            efeito = 1.2;
            break;

        //Se não efetivo, o ataque pode tirar 20% a menos da vida do adversário
        case 2:
            efeito = 0.8;

        //Se não há relação, caso o ataque de p1 seja maior que a defesa de p2, esse valor é subtraído da vida de p2. Caso não, p2 perde 1 de vida
        default:
            efeito = 1.0;
            break;
    }
}

void resultado(struct Jogador jogador1, struct Jogador jogador2) {
    int i = 0, p1 = 0, p2 = 0;
    while (1) {
        batalhar(jogador1, jogador2, p1, p2);
        if (jogador2.pokemon[p2].vida <= 0) {
            printf("%s venceu %s.", jogador1.pokemon[p1].nome, jogador2.pokemon[p2].nome);
            p2++;
            jogador2.quantPokemon--;
        }

        if (jogador1.quantPokemon <= 0) {
            printf("Jogador 2 venceu!");
            break;
        }
        
        batalhar(jogador2, jogador1, p2, p1);
        if (jogador1.pokemon[p1].vida <= 0) {
            printf("%s venceu %s.", jogador2.pokemon[p2].nome, jogador1.pokemon[p1].nome);
            p1++;
            jogador1.quantPokemon--;
        }

        if (jogador2.quantPokemon <= 0) {
            printf("Jogador 1 venceu!");
            break;
        }
    }

    printf("Pokemon sobreviventes: ");
    for (int i = 0; i < jogador1.quantPokemon + jogador2.quantPokemon; i++) {
        if (jogador1.pokemon[i].vida <= 0) printf("%s\n", jogador1.pokemon[i].nome);
        else if (jogador2.pokemon[i].vida <= 0) printf("%s\n", jogador2.pokemon[i].nome);
        else printf("%s\n%s\n", jogador1.pokemon[i].nome, jogador2.pokemon[i].nome);
    }
}