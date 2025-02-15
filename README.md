# Batalha Pokémon
## Visão Geral
O objetivo deste projeto é resolver um problema de programação envolvendo a temática Pokémon. Neste programa, criado apenas com a linguagem C, é implementado um sistema de batalha entre os Pokémon de dois jogadores em uma lógica de turnos, levando em conta os atributos ataque, defesa, vida e tipo dos Pokémon, sendo que há relações de vantagem ou desvantagem a depender dos tipos do atacante e do defensor.

O *software* carrega os dados de um arquivo, aplica as regras de batalha e exibe o resultado. 
## Estrutura
O programa foi dividido em módulos a fim de aumentar a organização e legibilidade do código.
### Arquivo `Pokemon.h`
Define o tipo `Pokemon`, o qual possui os seguintes atributos:
- **nome**: Nome do Pokémon;  
- **tipo**: Tipo do Pokémon, que pode ser agua, fogo, eletrico, gelo ou pedra;  
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
- **pokemon**: Ponteiro que recebe o(s) Pokémon do jogador.
```c
struct Jogador {
    int quantPokemon;
    Pokemon *pokemon;
};
```
### Arquivo `Batalha.h`
Aqui está a lógica central das batalhas. Contém as seguintes funções:

- **`efetividade`**:

    Verifica se há uma relação entre os tipos dos Pokémon e retorna `1` caso o ataque seja super efetivo, `2` caso não efetivo e `0` se não há uma relação. Nesse sentido, a função recebe como parâmetros os ponteiros do tipo *char* `tipoAtacante` e `tipoDefensor`, para aplicar a lógica de efetividade.

- **`calcularDano`**:

    Recebe os Pokémon atacante e defensor, além de um possível efeito de ataque como parâmetros, então calcula a quantidade de dano causada pelo atacante, levando em consideração a `efetividade`. 

    Por fim, retorna o valor do dano causado, sendo `1` a quantidade mínima.

- **`atacar`**:

    Realiza um turno de ataque entre dois Pokémon, atualizando a vida do defensor de acordo com o valor retornado de `calcularDano`. Para isso, em seus parâmetros são esperados os dois Pokémon e seus numeros indexados, a fim de encontrar as criaturas em seus respectivos *arrays* — ou melhor, times.  

- **`contarPokemonVivos`**:

    Conta quantos Pokémon ainda possuem mais de zero pontos de vida no time do jogador. Recebe apenas o jogador em que se quer realizar tal processo.

- **`executarTurno`**:

    Realiza os turnos de ataque entre dois jogadores. Caso o defensor tenha sido derrotado, o próximo de seu time entra na batalha. Além disso, seus parâmetros são os mesmos da função `atacar`.

- **`definirVencedor`**:

    Recebe os dois jogadores como parâmetro e executa os turnos entre seus Pokémon até que um dos contestantes não tenha mais nenhuma criatura em seu time, exibindo o resultado final: qual jogador foi o vencedor.

- **`mostrarSobreviventes`** e **`mostrarDerotados`**:
  
    Essas funções recebem um jogador e mostram os nomes de seus Pokémon com vida maior que zero e menor ou igual a zero, respectivamente, ou seja, exibem os Pokémon sobreviventes e os que foram derrotados no time.

### Arquivo `main.c`
Este é o arquivo principal do projeto. Suas responsabilidades são:

- Carregar os dados do arquivo `dados.txt` e armazená-los em suas respectivas variáveis;
- Inicializar os jogadores e seus Pokémon;
- Executar a batalha entre os jogadores usando as funções de `Batalha.h`;
- Alocar espaços na memória e liberá-los quando não forem mais necessários.

## Processo de execução
1. **Leitura de dados:** Todos os atributos necessários para a batalha são lidos do arquivo `dados.txt`, no qual a primeira linha especifica a quantidade de Pokémon no time de cada jogador e as linhas seguintes contêm os atributos de cada Pokémon, seguindo a ordem: nome, ataque, defesa, vida e tipo;

2. **Inicialização dos jogadores:** Os Pokémon são alocados dinamicamente e associados a seus respectivos jogadores;

3. **Simulação e resultado da batalha:** Turnos alternados são executados, exibindo os resultados dos duelos até que todos os Pokémons de um dos jogadores sejam derrotados. O jogador vencedor é mostrado, além dos Pokémon sobreviventes e derrotados dos dois times.

## Exemplos de entrada e saída de dados
### Entrada
```
3 2
Squirtle 10 15 15 agua
Vulpix 15 15 15 fogo
Onix 5 20 20 pedra
Golem 20 5 10 pedra
Charmander 20 15 12 fogo
```
* *O jogador 1 possui os Pokémon Squirtle, Vulpix e Onix, e o jogador 2 possui o Golem e o Charmander*.
### Saída
```
Squirtle venceu Golem.
Charmander venceu Squirtle.
Vulpix venceu Charmander.
Jogador 1 venceu!
Pokemon sobreviventes:
Vulpix
Onix
Pokemon derrotados:
Squirtle
Golem
Charmander
```