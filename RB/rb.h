#ifndef RB_H
#define RB_H
#include <string.h>
enum cor { VERMELHO,PRETO,duploNull};

typedef int tipo_dado;
typedef struct no_bst {
	tipo_dado dado;
	enum cor cor;
	struct no_bst *esq, *dir, *pai;
} no_bst;

typedef no_bst *arvore;
void inicializar(arvore *raiz);
void adicionar (int valor, arvore *raiz);
int altura(arvore raiz);
int maior(int a, int b);
int maior_elemento(arvore raiz);
int menor_elemento(arvore raiz);
void pre_order(arvore raiz);
void pos_order(arvore raiz);
void in_order(arvore raiz);
void remover (int valor, arvore *raiz);
void imprimir_elemento(arvore raiz);
void imprimir(arvore raiz);
enum cor cor(arvore elemento);
void ajustar(arvore *raiz, arvore elemento);
void rotacao_simples_direita(arvore *raiz, arvore pivo);
void rotacao_simples_esquerda(arvore *raiz, arvore pivo);
void rotacao_esquerda_direita(arvore *raiz, arvore pivo);
void rotacao_direita_esquerda(arvore *raiz, arvore pivo);
int eh_raiz(arvore elemento);
int eh_filho_esquerdo(arvore elemento);
int eh_filho_direito(arvore elemento);
void removerAjustar(arvore *raiz,arvore aux);
arvore irmao(arvore elemento);
arvore tio(arvore elemento);
int ehNonull(arvore no);
void ajustarCaso5(arvore *raiz,arvore elemento);
void ajustarCaso6(arvore *raiz,arvore elemento);
#endif
