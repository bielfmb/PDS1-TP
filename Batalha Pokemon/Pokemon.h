#include <stdio.h>

#ifndef POKEMON_H
#define POKEMON_H

//cria o tipo pokemon
struct Pokemon {
    char *nome, *tipo;
    float ataque, defesa, vida;
};

typedef struct Pokemon Pokemon;

#endif