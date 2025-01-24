#include <stdio.h>
#include "Pokemon.h"

//cria o tipo jogador
struct Jogador {
    int quantPokemon, numero;
    Pokemon *pokemon;
};

typedef struct Jogador Jogador;