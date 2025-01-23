#include <stdio.h>
#include <string.h>
#include "Batalha.h"

int main() {
    FILE* dados = fopen("dados.txt", "r+t");
    if (dados == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    
    Jogador jogador1, jogador2;
    Jogador *j1 = &jogador1, *j2 = &jogador2;
    int pokemon1 = fscanf(dados, "%d", &j1->quantPokemon),
        pokemon2 = fscanf(dados, "%d", &j2->quantPokemon);

    for (int i = 0; i < pokemon1 - 1; i++) {
        fscanf(dados, "%s", j1->pokemon[i].nome);
        fscanf(dados, "%d", &j1->pokemon[i].ataque);
        fscanf(dados, "%d", &j1->pokemon[i].defesa);
        fscanf(dados, "%d", &j1->pokemon[i].vida);
        fscanf(dados, "%s", j1->pokemon[i].tipo);
    }

    for (int i = 0; i < pokemon2 - 1; i++) {
        fscanf(dados, "%s", j2->pokemon[i].nome);
        fscanf(dados, "%d", &j2->pokemon[i].ataque);
        fscanf(dados, "%d", &j2->pokemon[i].defesa);
        fscanf(dados, "%d", &j2->pokemon[i].vida);
        fscanf(dados, "%s", j2->pokemon[i].tipo);
    }

    resultado(j1, j2);

    printf("Pokemon derrotados: ");
    for (int i = 0; i < j1->quantPokemon + j2->quantPokemon; i++) {
        if (j1->pokemon[i].vida <= 0) printf("%s\n", j1->pokemon[i].nome);
        else if (j2->pokemon[i].vida <= 0) printf("%s\n", j2->pokemon[i].nome);
        else printf("%s\n%s\n", j1->pokemon[i].nome, j2->pokemon[i].nome);
    }

    printf("Pokemon sobreviventes: ");
    for (int i = 0; i < j1->quantPokemon + j2->quantPokemon; i++) {
        if (j1->pokemon[i].vida > 0) printf("%s\n", j1->pokemon[i].nome);
        else if (j2->pokemon[i].vida > 0) printf("%s\n", j2->pokemon[i].nome);
        else printf("%s\n%s\n", j1->pokemon[i].nome, j2->pokemon[i].nome);
    }

    return 0;
}
