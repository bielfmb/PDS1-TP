#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Jogador.h"
#include "Pokemon.h"
#include "Batalha.h"

int main() {
    std::ifstream dados("dados.txt");
    if (!dados.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    Jogador *j1 = NULL, *j2 = NULL;

    dados >> j1->quantPokemon >> j2->quantPokemon;

    // Leitura dos Pokémons do jogador 1
    for (int i = 0; i < j1->quantPokemon; i++) {
        dados >> j1->pokemon[i].nome 
              >> j1->pokemon[i].ataque 
              >> j1->pokemon[i].defesa 
              >> j1->pokemon[i].vida 
              >> j1->pokemon[i].tipo;
    }

    // Leitura dos Pokémons do jogador 2
    for (int i = 0; i < j2->quantPokemon; i++) {
        dados >> j2->pokemon[i].nome 
              >> j2->pokemon[i].ataque 
              >> j2->pokemon[i].defesa 
              >> j2->pokemon[i].vida 
              >> j2->pokemon[i].tipo;
    }

    // Definição do vencedor
    j1->definirVencedor(j2);

    // Exibição dos resultados
    std::cout << "Pokémon sobreviventes:\n";
    j1->mostrarSobreviventes();
    j2->mostrarSobreviventes();

    std::cout << "Pokémon derrotados:\n";
    j1->mostrarDerrotados();
    j2->mostrarDerrotados();

    dados.close();

    return 0;
}