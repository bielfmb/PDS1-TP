#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogador.h"
#include "Pokemon.h"
#include "Batalha.h"

int main() {
    FILE* dados = fopen("dados.txt", "r+t");
    if (dados == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    
    Jogador *j1 = malloc(sizeof(Jogador));
    Jogador *j2 = malloc(sizeof(Jogador));

    fscanf(dados, "%d", &j1->quantPokemon);
    fscanf(dados, "%d", &j2->quantPokemon);

    j1->pokemon = malloc(j1->quantPokemon*sizeof(Pokemon));
    j2->pokemon = malloc(j2->quantPokemon*sizeof(Pokemon));

    if (j1 == NULL || j2 == NULL || j1->pokemon == NULL || j2->pokemon == NULL) {
        printf("Falha ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < j1->quantPokemon; i++) {
        j1->pokemon[i].nome = malloc(50*sizeof(char));
        j1->pokemon[i].tipo = malloc(10*sizeof(char));
        fscanf(dados, "%s %f %f %f %s", j1->pokemon[i].nome, 
            &j1->pokemon[i].ataque, 
            &j1->pokemon[i].defesa, 
            &j1->pokemon[i].vida, 
            j1->pokemon[i].tipo);
    }

    for (int i = 0; i < j2->quantPokemon; i++) {
        j2->pokemon[i].nome = malloc(50*sizeof(char));
        j2->pokemon[i].tipo = malloc(10*sizeof(char));
        fscanf(dados, "%s %f %f %f %s", j2->pokemon[i].nome, 
            &j2->pokemon[i].ataque, 
            &j2->pokemon[i].defesa, 
            &j2->pokemon[i].vida, 
            j2->pokemon[i].tipo);
    }

    mostrarResultado(j1, j2);

    printf("Pokemon sobreviventes: \n");
    mostrarSobreviventes(j1);
    mostrarSobreviventes(j2);
    
    printf("Pokemon derrotados: \n");
    mostrarDerrotados(j1);
    mostrarDerrotados(j2);

    for (int i = 0; i < j1->quantPokemon; i++) {
        free(j1->pokemon[i].nome);
        free(j1->pokemon[i].tipo);
    }

    for (int i = 0; i < j2->quantPokemon; i++) {
        free(j2->pokemon[i].nome);
        free(j2->pokemon[i].tipo);
    }

    free(j1->pokemon);
    free(j2->pokemon);

    fclose(dados);
    free(j1);
    free(j2);
    return 0;
}
