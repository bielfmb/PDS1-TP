#include <stdio.h>

//cria o tipo pokemon
struct Pokemon {
    char nome[10], tipo[10];
    int ataque, defesa, vida;
};

typedef struct Pokemon Pokemon;
