#include <stdio.h>
#include "Pokemon.h"

//cria o tipo jogador
typedef struct {
    int quantidadePokemon, numero;
    Pokemon pokemon[100];
} Jogador;
