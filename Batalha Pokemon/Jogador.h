#include <stdio.h>
#include "Pokemon.h"

#ifndef JOGADOR_H
#define JOGADOR_H

//cria o tipo jogador
struct Jogador {
    int quantPokemon;
    Pokemon *pokemon;
};

typedef struct Jogador Jogador;

#endif