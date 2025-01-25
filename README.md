# Batalha Pokemon
## Visão Geral
O objetivo deste trabalho é resolver um problema de programação envolvendo a temática Pokémon. Neste projeto, criado apenas com a linguagem C,é implemnetado um sistema de batalha entre os Pokémon de dois jogadores em uma lógica de turnos, levando em conta os atributos ataque, defesa, vida e tipo dos Pokémon, sendo que há relações de vantagem ou desvantagem a depender dos tipos do atancate e do defensor.

O programa carrega os dados de um arquivo, aplica as regras de batalha e exibe o resultado. 
## Estrutura
O programa foi dividido em módulos a fim de aumentar a organização e legibilidade do código.
### Arquivo `Pokemon.h`
Define o tipo `Pokemon`, o qual possui os seguintes atributos:
- **nome**: Nome do Pokémon;  
- **tipo**: Tipo do Pokémon, pode ser agua, fogo, eletrico, gelo ou pedra;  
- **ataque**: Quantidade de pontos de ataque do Pokémon;  
- **defesa**: Quantidade de pontos de defesa do Pokémon;  
- **vida**: Quantidade de pontos de vida do Pokémon.
```c
struct Pokemon {
    char *nome, *tipo;
    float ataque, defesa, vida;
};
```
### Arquivo `Jogador.h`
Define o tipo `Jogador`, o qual possui os seguintes atributos:
- **quantPokemon**: Quantidade de Pokémon do jogador;  
- **pokemon**: Ponteiro que recebe o(s) Pokèmon do jogador.
```c
struct Jogador {
    int quantPokemon;
    Pokemon *pokemon;
};
```
### Arquivo `Batalha.h`
Aqui está a lógica central das batalhas. Contém as seguintes funções:

- **`efetividade`**:

    Verifica se há uma relação entre os tipos dos Pokémon e retorna `1` caso o ataque seja super efetivo, `2` caso não efetivo e `0` se não há nehuma relação.

- **`calcularDano`**:

    Calcula a quantidade de dano causada por um Pokémon atacante no defensor, levando em consideração a `efetividade`. 

    Retorna o valor do dano causado, sendo `1` a quantidade mínima de dano.

- **`batalhar`**:

    Realiza um turno entre dois Pokémon, atualizando a vida do defensor de acordo com o valor retornado de `calcular dano`.

- **`contarPokemonVivos`**:

    Conta quanto Pokémon ainda possuem mais de 0 pontos de vida no time do jogador.

- **`simularTurno`**:

    Realiza os turnos de ataque entre dois jogadores. Caso o defensor tenha sido derrotado, o próximo de seu time entra na batalha.

- **`mostrarResultado`**:

    Executa os turnos entre os Pokémon até que um dos jogadores não tenha mais nenhum em seu time, exibindo o resultado final: qual foi jogador foi o vencedor.

- **`mostrarSobreviventes`** e **`mostrarDerotados`**:
  
    Essas funções mostram os nomes dos Pokémon com vida maior que zero e menor ou igual a zero, respectivamente, ou seja, exibem os Pokémon sobreviventes e os que foram derrotados.

### Arquivo `main.c`
Esse é o arquivo principal do projeto. Suas responsabilidades são:

- Carregar os dados do arquivo `dados.txt` e armazená-los em suas respectivas variáveis;
- Inicializar os jogadores e seus Pokémon;
- Executar a batalha entre os jogadores usando as funções de `Batalha.h`;
- Alocar espaços na memória e liberá-los quando não forem mais necessários.

## Processo de execução
1. **Leitura de dados:** Todos os atributos necessários para a batalha são lidos do arquivo `dados.txt`, no qual a primeira linha especifica a quantidade de Pokémon no time de cada jogador e as linhas seguintes contêm os atributos de cada Pokémon, seguindo a ordem: nome, ataque, defesa, vida e tipo;
2. **Inicialização dos jogadores:** Os Pokémon são alocados dinamicamente e associados a seus respectivos jogadores;
3. **Simulação e resultado da batalha** Turnos alternados são executados, exibindo os resultados dos duelos até que todos os Pokémons de um dos jogadores sejam derrotados. O jogador vencedor é mostrado, além dos Pokémon sobreviventes e derrotados dos dois times.

