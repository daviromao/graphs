# AB2 - Teoria dos Grafos
### Alunos: Davi da Silva Romão e Gabriel Gomes de Oliveira
### Curso: Ciência da Computação

Esse repositório contem as implementações de algoritmos solicitados para integrar a nota da AB2 da disciplina de Teoria dos Grafos do curso de Ciência da Computação.
Algoritmos implementados: Kosaraju, Kruskal, Dijkstra, Prim e adicionalmente o algoritmo de Ford-Fulkerson.

### instruções de como rodar:

Para compilar todos os binários de uma vez e copiar para a pasta bat basta usar o comando *sh gerar_bins.sh*

```
sh gerar_bins.sh
```
Esse comando vai gerar todos os binários, jogar na pasta bin e apresentar a opção de rodar o bat logo em seguida,como demonstrado a seguir:

![image](https://github.com/daviromao/graphs/assets/86529029/321a49b0-6a93-4bbb-97be-ddfd09c29026)

![image](https://github.com/daviromao/graphs/assets/86529029/69f1106e-68b2-40a1-9084-c61cf4615a65)

#### Alternativamente:
Para compilar os algoritmos individualmente, deve-se entrar na pasta de cada um e usar o comando *make all* o comando é o mesmo para compilar individualmente cada algoritmo como ilustrado a seguir:

```
cd kosaraju
make all

cd kruskal
make all

cd dijkstra
make all

cd prim
make all
```

#### *O comando para executar cada algoritmo segue as especificações feitas pelo professor no documento que enuncia o projeto.*

> [!IMPORTANT]
> Sobre o a entrada do Ford-Fulkerson:
> Entrada recebe n e m, o número de vértices e arestas do grafo, respectivamente.
> Em seguida, m linhas com 3 inteiros u, v e c, indicando que há uma aresta de u para v com capacidade.
> Por fim, dois inteiros s e t, indicando a fonte e o target do grafo.

> [!NOTE]
> Adicionamos o ford-fulkerson no bat1.
Dentro da pasta do ford-fulkerson há um "mini" bat para testar ele!
