#ifndef GRAFO_H
#define GRAFO_H



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
void ordenarListaAresta(grafo *g);
void calcularKruskal(grafo *g);
int verificarCiclo(grafo *g,aresta a);
vertice * procurarVertice(grafo *g,char * nome);
void lerCaminhoMin(grafo *g);
#endif
