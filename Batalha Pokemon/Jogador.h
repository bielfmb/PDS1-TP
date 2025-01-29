#include <stdio.h>
#include "Pokemon.h"

#ifndef JOGADOR_H
#define JOGADOR_H

struct Jogador {
    int quantPokemon;
    Pokemon *pokemon;
};

typedef struct Jogador Jogador;

#endif