#ifndef GRAFO_H
#define GRAFO_H
#define tamanho 20
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct vertice{
	int indice;
	char nome[50];
	int percorido;
	
}vertice;

typedef struct aresta{
     int peso;
     vertice vert1;
      vertice vert2;
     
}aresta;
typedef struct grafo {
	int v;
	int a;
	//struct vertice ve;
	struct vertice *mapa;
	struct aresta *listaAresta;
	long **matriz;
	struct aresta *arvoreGeradoMin;
        int tamanho_arvoreMin;
	 int tamanho_listaAux;
	struct aresta *listaAux[tamanho];
} grafo;





void inicializar (grafo *g);

void imprimir(grafo *g);
void adicionarAresta(grafo *g, char v1, char v2);
void  lerMapa(grafo *g);
grafo* lerVerticeArestaEmapa(grafo *g,char *arquivo);
void imprimirVertice(grafo *g);
void caregarMapa(grafo *g,char *arquivo);
void lerArestas(grafo *g,char *arquivo);
void vizualizarResultado(grafo *g,char *arquivo);
void lerListaAresta(grafo *g);
void ordenarListaAresta(aresta *lista ,int tam);
void calcularPrim(grafo *g);
int verificarCiclo(grafo *g,aresta a);
vertice * procurarVertice(grafo *g,char * nome);
void lerCaminhoMin(grafo *g);
void procurarVerticeAdj(grafo *g,aresta a);
void inserirListaArestaAux(grafo *g,vertice v1,vertice v2);
void imprimirListaAux(grafo *g);
int verificarArestaRepetida(grafo *g,vertice v1,vertice v2);
int verificarArestaArvoreMin(grafo *g,vertice v1,vertice v2);
#endif
