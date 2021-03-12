#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void inicializar(arvore *raiz){
	*raiz=NULL;

}

arvore adicionar(int key,arvore raiz){
	if(raiz==NULL){
		arvore novo=(arvore)malloc(sizeof(NO));
		novo->key=key;
		novo->esq=NULL;
		novo->dir=NULL;
	return novo;
	}
	else{
		if(key>raiz->key){
			raiz->dir=adicionar(key,raiz->dir);
		}
		else {
			raiz->esq=adicionar(key,raiz->esq);
		}
	return raiz;
		}
	

}

void imprimirConteudo(arvore raiz){
	printf("[%d]",raiz->key);//seria necessario imprimir o conteudo da raiz em varios lugares,por isso 
				//a função foi criada(reuso de código)

}
/*
void imprimirArvore(arvore raiz){
       printf("[]");
	if(raiz!=NULL){
	        imprimirConteudo(raiz);
		imprimirArvore(raiz->esq);
		imprimirArvore(raiz->dir);
        }
	 printf("[]");

}
*/

void pre_ordem(arvore raiz){
	if(raiz!=NULL){
		imprimirConteudo(raiz);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}


}

void in_ordem(arvore raiz){
	if(raiz!=NULL){
	    in_ordem(raiz->esq);
	    imprimirConteudo(raiz);
	    in_ordem(raiz->dir);
		}


}
void pos_ordem(arvore raiz){


	if(raiz!=NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		imprimirConteudo(raiz);
	}

	}

int maior_elemento(arvore raiz) {
	if(raiz == NULL){
			return -1;
	}
	if(raiz->dir == NULL){
			return raiz->key;
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
			return raiz->key;
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
	



arvore remover(int valor,arvore raiz){
	if(raiz==NULL){
		return NULL;
	}
	
        else if(raiz->key==valor){
			if(raiz->esq==NULL && raiz->dir==NULL){
				 return raiz=NULL;
			}
			else{
				if(raiz->esq == NULL) {
					return raiz->dir;//irar percorrer na subarvore a direita
				}
			        else if(raiz->dir == NULL) {
					return raiz->esq;//irar percorrer na subarvore a esquerda
				}
			}
			raiz->key=maior_elemento(raiz->esq);//irar receber o maior elemento da subarvore a esquerda
							    //nesse caso o valor na chave da raiz irar ser igual ao maior elemento da subarvore a esquerda
			raiz->esq=remover(raiz->key,raiz->esq);//irar deletar o valor da subarvore a esquerda que é igual ao da raiz,por isso pasar raiz->key
								//pois o valor da raiz ja foi subistituido,nesse caso tornando a subarvore como raiz
			return raiz;
			}
	else if(valor>raiz->key){
		raiz->dir=remover(valor,raiz->dir);
	}
	else{
		raiz->esq=remover(valor,raiz->esq);
	}
	return raiz;
			
		
		}

int procurarPaiElemento(int elemento,arvore raiz){
	if(raiz==NULL||elemento==raiz->key){
		return -1;
	}

	
	else if(elemento==procurarElemento(raiz->dir)||elemento==procurarElemento(raiz->esq)){
		
		return raiz->key;
		
	}
	
        else if(elemento>raiz->key){
			int o=procurarPaiElemento(elemento,raiz->dir);
                       
			return o;
			
		}

        else if(elemento<raiz->key){
			int o=procurarPaiElemento(elemento,raiz->esq);
			return o;
			
		}
		
	else{
		return -1;//caso o elemento não estiver contido na arvore
	}

	
	


}


int procurarElemento(arvore raiz){//evita usar ponteiro para ponteiro
	if(raiz==NULL){
		return -1;
	}
	else{
		return raiz->key;
	}
}

int procurarSucessor(int elemento,arvore raiz,arvore aux){
	
	if(raiz==NULL){
		return -1;
	}
	
	else if(raiz->key==elemento){
		if(raiz->dir!=NULL){
			return menor_elemento(raiz->dir);
		}
		
		else{
			int pai=procurarPaiElemento(elemento,aux);
			while(pai<elemento && pai!=-1){
				
				 pai=procurarPaiElemento(pai,aux);
				
			}
			return pai;
		}
		
	}
	
	else if(elemento>raiz->key){
			
			int succ=procurarSucessor(elemento,raiz->dir,aux);
			return succ;
		}
	else if(elemento<raiz->key){
			
			int succ=procurarSucessor(elemento,raiz->esq,aux);
			return succ;
		}
	else{
		return -1;
	}


}

int procurarAntecessor(int elemento,arvore raiz,arvore aux){
	if(raiz==NULL){
		return -1;
	}
	
	else if(raiz->key==elemento){
		if(raiz->esq!=NULL){
			return maior_elemento(raiz->esq);
		}
		
		else{
			int pai=procurarPaiElemento(elemento,aux);//aqui
			while(pai>elemento && pai!=-1 ){
				
				 pai=procurarPaiElemento(pai,aux);
				
				
			}
			return pai;
		}
		
	}
	
	else if(elemento>raiz->key){
			
			int ant=procurarAntecessor(elemento,raiz->dir,aux);
			return ant;
		}
	else if(elemento<raiz->key){
			
			int ant=procurarAntecessor(elemento,raiz->esq,aux);
			return ant;
		}
	else{
		return -1;
	}
		
	


}



	

			
	

		






































