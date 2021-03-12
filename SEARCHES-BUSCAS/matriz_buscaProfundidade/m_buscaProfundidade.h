#ifndef GRAFO_H
#define GRAFO_H


enum cor { BRANCO,CINZA,PRETO};

typedef struct vertice{
	int indice;
	char nome[50];
	
}vertice;


typedef struct grafo {
	int v;
	int a;
	struct vertice *arvore;
	struct vertice *mapa;
	int *tempoDescoberto;
	int *tempoTerminado;
        enum cor *cor;
	long **matriz;
        
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
void buscaProfundidade_visit(grafo *g,int tempo,vertice u);
vertice * procurarVertice(grafo *g,char *nome);
void buscaProfundidade_Grafo(grafo *gr);
void imprimirResultadoBusca(grafo *g);
void imprimirCaminho_MaisCurto(grafo *g,vertice s,vertice v);
#endif
