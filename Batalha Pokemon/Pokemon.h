#include <stdio.h>

#ifndef POKEMON_H
#define POKEMON_H

struct Pokemon {
    char *nome, *tipo;
    float ataque, defesa, vida;
};

typedef struct Pokemon Pokemon;

#endif