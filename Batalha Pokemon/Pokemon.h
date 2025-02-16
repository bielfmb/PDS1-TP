#include <stdio.h>
#include <string.h>

#ifndef POKEMON_H
#define POKEMON_H

struct Pokemon {
    char *nome, *tipo;
    float ataque, defesa, vida;

    int efetividade(char* tipoDefensor);
    float calcularDano(float defensorDefesa, float efeito);
    void atacar(Pokemon defensor);
};

int Pokemon::efetividade(char* tipoDefensor) {
    //Verifica se um ataque é super efetivo
    if ((strcmp(tipo, "eletrico") == 0) && (strcmp(tipoDefensor, "agua") == 0)) return 1;
    if ((strcmp(tipo, "agua") == 0) && (strcmp(tipoDefensor, "fogo") == 0)) return 1;
    if ((strcmp(tipo, "fogo") == 0) && (strcmp(tipoDefensor, "gelo") == 0)) return 1;
    if ((strcmp(tipo, "gelo") == 0) && (strcmp(tipoDefensor, "pedra") == 0)) return 1;
    if ((strcmp(tipo, "pedra") == 0) && (strcmp(tipoDefensor, "eletrico") == 0)) return 1;
    
    //Verifica se um ataque não é muito efetivo
    if ((strcmp(tipo, "eletrico") == 0) && (strcmp(tipoDefensor, "pedra") == 0)) return 2;
    if ((strcmp(tipo, "agua") == 0) && (strcmp(tipoDefensor, "eletrico") == 0)) return 2;
    if ((strcmp(tipo, "fogo") == 0) && (strcmp(tipoDefensor, "agua") == 0)) return 2;
    if ((strcmp(tipo, "gelo") == 0) && (strcmp(tipoDefensor, "fogo") == 0)) return 2;
    if ((strcmp(tipo, "pedra") == 0) && (strcmp(tipoDefensor, "gelo") == 0)) return 2;

    //Caso não haja relação de efetividade
    return 0;
}

float Pokemon::calcularDano(float defensorDefesa, float efeito) {
    float dano = (ataque * efeito) - defensorDefesa;
    
    if (dano < 1.0) return 1.0; // dano mínimo é 1
    return dano;
}

void Pokemon::atacar(Pokemon defensor) {
    //Se efetivo, o ataque aumenta em 20%
    if (efetividade(defensor.tipo) == 1) {
        if ((defensor.vida - calcularDano(defensor.defesa, 1.2)) <= 0.0) defensor.vida = 0.0;
        else defensor.vida -= calcularDano(defensor.defesa, 1.2);
    }

    //Se não efetivo, o ataque diminui em 20% 
    else if (efetividade(defensor.tipo) == 2) {
        if ((defensor.vida - calcularDano(defensor.defesa, 0.8)) <= 0) defensor.vida = 0;
        else defensor.vida -= calcularDano(defensor.defesa, 0.8);
    }

    //Se não há relação, não há efeito
    else {
        if ((defensor.vida - calcularDano(defensor.defesa, 1.0)) <= 0) defensor.vida = 0;
        else defensor.vida -= calcularDano(defensor.defesa, 1.0);
    }
}

#endif