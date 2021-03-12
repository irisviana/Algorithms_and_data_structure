#ifndef GRAFO_H
#define GRAFO_H

#define MAX 100
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
	int *distancia;
        enum cor *cor;
	long **matriz;
} grafo;

typedef struct fila{
    int inicio, final;
    struct vertice dados[MAX];
}fila;
void inicializar (grafo *g);

void imprimir(grafo *g);
void adicionarAresta(grafo *g, char v1, char v2);
void  lerMapa(grafo *g);
grafo* lerVerticeArestaEmapa(grafo *g,char *arquivo);
void imprimirVertice(grafo *g);
void caregarMapa(grafo *g,char *arquivo);
void lerArestas(grafo *g,char *arquivo);
void vizualizarResultado(grafo *g,char *arquivo);
void buscaLargura_Grafo(grafo *gr,vertice s);
fila* cria_Fila();
void libera_Fila(fila* fi);
int insere_Fila(fila* fi, struct vertice vert);
int remove_Fila(fila* fi);
int Fila_cheia(fila* fi);
int Fila_vazia(fila* fi);
void imprimirCaminho_MaisCurto(grafo *g,vertice s,vertice v);
vertice * procurarVertice(grafo *g,char *nome);
#endif
