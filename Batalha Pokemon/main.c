#include <stdio.h>
#include <string.h>
#include "Batalha.h"

int main() {
    FILE* dados = fopen("dados.txt", "r+t");
    if (dados == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    
    struct Jogador jogador1, jogador2;
    int pokemon1 = fscanf(dados, "%d", &jogador1.quantPokemon),
        pokemon2 = fscanf(dados, "%d", &jogador2.quantPokemon);

    for (int i = 0; i < pokemon1 - 1; i++) {
        fscanf(dados, "%s", jogador1.pokemon[i].nome);
        fscanf(dados, "%d", &jogador1.pokemon[i].ataque);
        fscanf(dados, "%d", &jogador1.pokemon[i].defesa);
        fscanf(dados, "%d", &jogador1.pokemon[i].vida);
        fscanf(dados, "%s", jogador1.pokemon[i].tipo);
    }

    for (int i = 0; i < pokemon2 - 1; i++) {
        fscanf(dados, "%s", jogador2.pokemon[i].nome);
        fscanf(dados, "%d", &jogador2.pokemon[i].ataque);
        fscanf(dados, "%d", &jogador2.pokemon[i].defesa);
        fscanf(dados, "%d", &jogador2.pokemon[i].vida);
        fscanf(dados, "%s", jogador2.pokemon[i].tipo);
    }

    resultado(jogador1, jogador2);

    return 0;
}
