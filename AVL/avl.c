#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void inicializar(arvore *raiz) {
	*raiz = NULL;
}

arvore adicionar (int valor, arvore raiz, int *propagaFB) {
	if(raiz == NULL) {
		arvore novo = (arvore) malloc(sizeof(struct no_avl));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->fb = 0;
	        * propagaFB = 1;
		return novo;
	}

	if(valor > raiz->dado) {
		raiz->dir = adicionar(valor, raiz->dir, propagaFB);
	  if(*propagaFB) {
				switch(raiz->fb) {
						case 0:
								raiz->fb = 1;
								*propagaFB=1;
								break;
						case -1:
								raiz->fb = 0;
								*propagaFB = 0;
								break;
						case 1:
								*propagaFB = 0;
								raiz->fb = 2;
								return rotacionar(raiz);
				}
		}

	} else {
		raiz->esq = adicionar(valor, raiz->esq, propagaFB);
	  if(*propagaFB) {
				switch(raiz->fb) {
						case 0:
								raiz->fb = -1;
								*propagaFB = 1;
								break;
						case -1:
								*propagaFB = 0;
								raiz->fb = -2;
								return rotacionar(raiz);

						case 1:
								raiz->fb = 0;
								*propagaFB = 0;
								break;
				}
		}
	}
	return raiz;
}


void pre_order(arvore raiz) {
	if(raiz != NULL) {
		imprimir_elemento(raiz);
		pre_order(raiz->esq);
		pre_order(raiz->dir);
	}
}

void pos_order(arvore raiz) {
	if(raiz != NULL) {
		pos_order(raiz->esq);
		pos_order(raiz->dir);
		imprimir_elemento(raiz);
	}
}

void in_order(arvore raiz) {
	if(raiz != NULL) {
		in_order(raiz->esq);
		imprimir_elemento(raiz);
		in_order(raiz->dir);
	}
}

void imprimir_elemento(arvore raiz) {
	printf("[%d,%d]", raiz->dado, raiz->fb);
}
int maior_elemento(arvore raiz) {
	if(raiz == NULL){
			return -1;
	}
	if(raiz->dir == NULL){
			return raiz->dado;
	}
	else{
			return maior_elemento(raiz->dir);

}
}

int menor_elemento(arvore raiz) {
	if(raiz == NULL){
			return -1;
	}
	if(raiz->esq == NULL){
			return raiz->dado;
	}
	else{
			return menor_elemento(raiz->esq);

}
}

int altura(arvore raiz) {
	if(raiz == NULL) {
		return 0;
	}
	else{ 
		int alturaDir=altura(raiz->dir);
		int alturaEsq=altura(raiz->esq);
		if(alturaDir>alturaEsq){
			return 1+alturaDir;
		}
		else{
			return 1+alturaEsq;
		}
	}
}
	





arvore rotacionar(arvore pivo) {
	if(pivo->fb == -2){
		
		if(pivo->esq->fb == -1) {
		    pivo->fb = 0;
		    pivo->esq->fb = 0;
		    return rotacao_simples_direita(pivo);
		}
		if(pivo->esq->fb == 1){
			 return rotacao_dupla_direita(pivo);
		}
		if(pivo->esq->fb ==0) {
			pivo->fb =-1;				
			pivo->dir->fb =1;
		    return rotacao_simples_direita(pivo);
		}
	} 
	if(pivo->fb ==2){
		
		if(pivo->dir->fb == 1) {
			pivo->fb =0;				
			pivo->dir->fb = 0;
		    return rotacao_simples_esquerda(pivo);
		}
		if(pivo->dir->fb == -1){
			 return rotacao_dupla_esquerda(pivo);
		}
		if(pivo->dir->fb ==0) {
			pivo->fb =1;				
			pivo->dir->fb =-1;
		    return rotacao_simples_esquerda(pivo);
		}
	} 
	
	
}


arvore  rotacao_simples_direita(arvore pivo) {
      	arvore p, u;
	

	p = pivo;
	u = pivo->esq;

	p->esq = u->dir;
	u->dir = p;

	
	return u;
}

arvore rotacao_dupla_direita(arvore pivo) {
	
        arvore v,u;
	u=pivo->esq;
	v=u->dir;
	
	
	if(v->fb==0){
		u->fb=0;
		pivo->fb=0;
	}
	if(v->fb==1){
		u->fb=-1;
		pivo->fb=0;
		v->fb=0;
	}
	if(v->fb==-1){
		u->fb=0;
		pivo->fb=1;
		v->fb=0;
	}
	v=rotacao_simples_esquerda(pivo->esq);
	
	pivo->esq=v;
	return rotacao_simples_direita(pivo);
	
	
        
}

arvore rotacao_dupla_esquerda(arvore pivo) {
	
	arvore v,u;
	u=pivo->dir;
	v=u->esq;
	
	
	if(v->fb==0){
		u->fb=0;
		pivo->fb=0;
	}
	if(v->fb==1){
		u->fb=0;
		pivo->fb=-1;
		v->fb=0;
	}
	if(v->fb==-1){
		u->fb=1;
		pivo->fb=0;
		v->fb=0;
	}
	v=rotacao_simples_direita(pivo->dir);
	
	pivo->dir=v;
	return rotacao_simples_esquerda(pivo);
	
	
       
}


arvore rotacao_simples_esquerda(arvore pivo) {
	arvore p, u;
	

	p = pivo;
	u = pivo->dir;

	p->dir = u->esq;
	u->esq = p;

	
		
       return u;
}


arvore remover(arvore raiz, tipo_dado elemento, int *decresceu) {
	
	if(raiz==NULL){
		*decresceu=0;
		return NULL;
		
	}
	
        else if(raiz->dado==elemento){
			
			if(raiz->esq==NULL && raiz->dir==NULL){
				*decresceu=1;
				 return raiz=NULL;
				 
			}
			else{
				if(raiz->esq == NULL) {
					*decresceu=1;
					return raiz->dir;
				}
			        else if(raiz->dir == NULL) {
				        *decresceu=1;
					return raiz->esq;
				}
			}
			raiz->dado=maior_elemento(raiz->esq);				    
			raiz->esq=remover(raiz->esq,raiz->dado,decresceu);
								
			return raiz;
			}
			
			
	else if(elemento>raiz->dado){
		raiz->dir=remover(raiz->dir,elemento,decresceu);
		
		 if(*decresceu ) {
				switch(raiz->fb) {

				case 0:
				    	*decresceu= 0;
					raiz->fb = -1;
					break;
				case -1:
				        raiz->fb=-2;
					return rotacionar(raiz);
				case 1:
					raiz->fb = 0;
					
					break;
		

				}
		}
	}
	else if(elemento<raiz->dado){
		raiz->esq=remover(raiz->esq,elemento,decresceu);
		if(*decresceu) {
				switch(raiz->fb) {
				case 0:
				       *decresceu = 0;
					raiz->fb = 1;
					break;
				case -1:
				   
					raiz->fb = 0;
					break;
				case 1:
					raiz->fb=2;
					return rotacionar(raiz);
				}
		}
	}
	
	return raiz;
			
		
		
}

    


















