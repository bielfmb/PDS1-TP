#include <stdio.h>

//cria o tipo pokemon
struct Pokemon {
    char *nome, *tipo;
    int ataque, defesa, vida;
};

typedef struct Pokemon Pokemon;
