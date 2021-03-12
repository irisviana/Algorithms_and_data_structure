#ifndef BST_H
#define BST_H



typedef struct no{
	int key;
	struct no *esq,*dir;

}NO;

typedef NO *arvore;


arvore adicionar(int key,arvore raiz);
void pre_ordem(arvore raiz);
void in_ordem(arvore raiz);
void pos_ordem(arvore raiz);
arvore remover(int valor,arvore raiz);
int maior_elemento(arvore raiz);
int menor_elemento(arvore raiz);
int altura(arvore raiz);
int procurarPaiElemento(int elemento,arvore raiz);
int procurarSucessor(int elemento,arvore raiz,arvore aux);
int procurarAntecessor(int elemento,arvore raiz,arvore aux);
void inicializar(arvore *raiz);
int procurarElemento(arvore raiz);
void imprimirConteudo(arvore raiz);
//void imprimirArvore(arvore raiz);
#endif
