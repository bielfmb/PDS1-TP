#include <stdio.h>
#include "Pokemon.h"

//cria o tipo jogador
struct Jogador {
    int quantPokemon, numero;
    struct Pokemon pokemon[100];
};

typedef struct Jogador Jogador;