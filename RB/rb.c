
#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

void inicializar(arvore *raiz) {
	*raiz = NULL;
}
void adicionar (int valor, arvore *raiz) {
	arvore posicao, pai, novo;
	posicao = *raiz;
	pai = NULL;
	
	/*navega na árvore até encontrar a posição vaga apropriada para o elemento,
		nesta "descida" é necessário manter o ponteiro para o pai, pois após encontrar 
		a posição vaga (NULL) não será possível encontrar o pai com o ponteiro posicao->pai */
	while(posicao != NULL) {
			pai = posicao;
			if(valor > posicao->dado) {
					posicao = posicao->dir;}
			else {
					posicao = posicao->esq;}
	}
	novo = (arvore) malloc(sizeof(struct no_bst));
	novo->dado = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->pai = pai;
	novo->cor = VERMELHO;
	if(eh_raiz(novo)){	
			*raiz = novo;
	}
	else {
		if(valor > pai->dado){
			pai->dir = novo;}
		else{
			pai->esq = novo;}
	}
	ajustar(raiz, novo);
}

void ajustar(arvore *raiz, arvore elemento){
	while(cor(elemento->pai) == VERMELHO) {
		
			//caso 1: Cor do tio é vermelha, desce o preto do avô
			if(cor(tio(elemento)) == VERMELHO) {
				tio(elemento)->cor = PRETO;
				elemento->pai->cor = PRETO;
				elemento->pai->pai->cor = VERMELHO;
				//Continua a verificação a partir do avô, que mudou para vermelho e pode ter 
				//gerado uma sequência vermelho-vermelho				
				elemento = elemento->pai->pai;
				
				
					

			}
			//caso 2: Cor do tio é preto
			else if( cor(tio(elemento)) == PRETO){

				if (eh_filho_esquerdo(elemento)){
					//rotacao simple a direita
					if(eh_filho_esquerdo(elemento->pai)){
						
						elemento->pai->pai->cor= VERMELHO;
						elemento->pai->pai->esq->cor= PRETO;
						rotacao_simples_direita(raiz, elemento->pai->pai);//verificar
						
					}
					//rotacao dupla a esquerda
					else if(!eh_filho_esquerdo(elemento->pai)){

						arvore avo=elemento->pai->pai;
						rotacao_simples_direita(raiz,elemento->pai);
						avo->cor=VERMELHO;
						avo->dir->cor=PRETO;
       				       		rotacao_simples_esquerda(raiz,avo);
					}	
				} 
				 else if (!eh_filho_esquerdo(elemento)){
					//rotacao simple a esquerda
					if(!eh_filho_esquerdo(elemento->pai)){
						
						elemento->pai->pai->cor=VERMELHO;
						elemento->pai->pai->dir->cor= PRETO;
						rotacao_simples_esquerda(raiz,elemento->pai->pai);//verificar
						
					}
					//rotacao dupla a direita
					else if(eh_filho_esquerdo(elemento->pai)){

						

						arvore avo=elemento->pai->pai;
						rotacao_simples_esquerda(raiz,elemento->pai);
						avo->cor=VERMELHO;
						avo->esq->cor=PRETO;
       				       		rotacao_simples_direita(raiz,avo);
						
					}
				 }
					
					
					
			}
		}
			
	(*raiz)->cor = PRETO;
}

void rotacao_simples_direita(arvore *raiz, arvore pivo){
			
			//o pivo é o v
			//o fe é o u
			arvore fe;
			fe = pivo->esq;
			int posicao_pivo_esq = eh_filho_esquerdo(pivo);
			
			//Atualização dos ponteiros
			pivo->esq = fe->dir;//recebe null
			fe->dir = pivo;
			fe->pai = pivo->pai;
			pivo->pai = fe;
			if(pivo->esq != NULL){
				pivo->esq->pai = pivo;}
			
			if(eh_raiz(fe)){//perguntar ao professor
				*raiz = fe;
			}
			else {
					if(posicao_pivo_esq){
							fe->pai->esq = fe;}
					else{
							fe->pai->dir = fe;}
			}//ligar o resto da arvore que não participou da rotação
}

void  rotacao_simples_esquerda(arvore *raiz,arvore pivo){
					
			arvore u;
			u=pivo->dir;
			
			int posicao_pivo_dir= eh_filho_direito(pivo);
						

			pivo->dir=u->esq;
			u->esq=pivo;

			u->pai=pivo->pai;
			pivo->pai=u;
			
			if(pivo->dir != NULL){
				pivo->dir->pai = pivo;
			}
			
			if(eh_raiz(u)){//perguntar ao professor
				*raiz = u;
			}
			else {
					if(posicao_pivo_dir){
							u->pai->dir = u;}
					else{
						 u->pai->esq =u;}
			}
			
}


enum cor cor(arvore elemento) {
	enum cor c;
	
	if(elemento==NULL || elemento->cor == PRETO){
		c = PRETO;}
	else{
		c = VERMELHO;}
	
	return c;
}

int eh_raiz(arvore elemento) {
	return (elemento->pai == NULL);
}
int eh_filho_esquerdo(arvore elemento) {//retorna 1
	return (elemento->pai != NULL && elemento == elemento->pai->esq);
}
int eh_filho_direito(arvore elemento) {//perguntar se retorna 0
	return (elemento->pai != NULL && elemento == elemento->pai->dir);
}
arvore tio(arvore elemento) {
	return irmao(elemento->pai);
}
arvore irmao(arvore elemento) {
	if(eh_filho_esquerdo(elemento)){
		return elemento->pai->dir;}
	else{
		return elemento->pai->esq;}
}
void imprimir(arvore raiz) {
	
	if(raiz != NULL) {
		imprimir_elemento(raiz);
		imprimir(raiz->esq);
		imprimir(raiz->dir);
	}
	
}
int altura(arvore raiz) {
	if(raiz == NULL) {
		return 0;
	}
	return 1 + maior(altura(raiz->dir), altura(raiz->esq));
}
int maior(int a, int b) {
	if(a > b){
		return a;}
	else{
		return b;}
}
int maior_elemento(arvore raiz) {
	if(raiz == NULL){
			return -1;}
	if(raiz->dir == NULL){
			return raiz->dado;}
	else{
			return maior_elemento(raiz->dir);}
}
int menor_elemento(arvore raiz) {
	if(raiz == NULL){
			return -1;}
	if(raiz->esq == NULL){
			return raiz->dado;}
	else{
			return maior_elemento(raiz->esq);}
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
	if(raiz!=NULL){
		if(raiz->cor== PRETO){
			printf("\x1b[30m[%d]\x1b[0m", raiz->dado);}
		else if(raiz->cor== VERMELHO){
			printf("\x1b[31m[%d]\x1b[0m", raiz->dado);}
		else if(raiz->cor==duploNull){
			printf("\e[0;37m[%d]\x1b[0m",raiz->dado);}
	}
	
}
int ehNonull(arvore no){
	return (no->cor==duploNull && no->dir==NULL && no->esq==NULL);
	
}
void ajustarCaso5(arvore *raiz,arvore elemento){
	if(eh_filho_esquerdo(elemento)){
						
						elemento->pai->dir->esq->cor=PRETO;
						elemento->pai->dir->cor=VERMELHO;
						rotacao_simples_direita(raiz,elemento->pai->dir);
						removerAjustar(raiz,elemento);
				 		
					}
					else{
						
						elemento->pai->esq->esq->cor=PRETO;
						elemento->pai->esq->cor=VERMELHO;
						rotacao_simples_direita(raiz,elemento->pai->esq);
						removerAjustar(raiz,elemento);
				 		
					}
}
void ajustarCaso6(arvore *raiz,arvore elemento){
	if(eh_filho_esquerdo(elemento)){
						elemento->pai->dir->dir->cor=PRETO;
						arvore pai=elemento->pai;
						pai->esq=NULL;
						free(elemento);
						rotacao_simples_esquerda(raiz,pai);
						
						
				 		
					}
					else{
						elemento->pai->esq->esq->cor=PRETO;
						arvore pai=elemento->pai;
						pai->dir=NULL;
						free(elemento);
						rotacao_simples_direita(raiz,pai);
						
				 	
					}
}
void removerAjustar(arvore *raiz,arvore elemento){
	

	//caso 1(correto)
	if(eh_raiz(elemento)){
		if(ehNonull(elemento)){
		
		//free(elemento);
		*raiz=NULL;	
		}
		else{
		   elemento->cor=PRETO;
		}
	return;
	}
	
	else if(cor(elemento->pai)==PRETO){
		//CASO 2(correto)
		if( cor(irmao(elemento)) == VERMELHO &&  cor(irmao(elemento)->dir)==PRETO && cor(irmao(elemento)->esq)==PRETO){
			if(eh_filho_esquerdo(irmao(elemento))){

				 elemento->pai->cor=VERMELHO;
				 elemento->pai->esq->cor=PRETO;

				 rotacao_simples_direita(raiz,elemento->pai);
				
				 removerAjustar(raiz,elemento);
				 return;
				 
				 
				 
				 
			}
			else{
				  elemento->pai->cor=VERMELHO;
				  elemento->pai->dir->cor=PRETO;
				  rotacao_simples_esquerda(raiz,elemento->pai);
				  
				
				  removerAjustar(raiz,elemento);
				  return;
				  
				  
			}
		}
		
		
		

		//CASO 3
		else if( cor(irmao(elemento)) ==PRETO &&  cor(irmao(elemento)->dir)==PRETO && cor(irmao(elemento)->esq)==PRETO){
			if(eh_filho_esquerdo(elemento)){
				elemento->pai->cor=duploNull;
				irmao(elemento)->cor=VERMELHO;
				elemento->pai->esq=NULL;
				arvore pai=elemento->pai;
				free(elemento);
				removerAjustar(raiz,pai);
				
				
			}
			else{
				elemento->pai->cor=PRETO;
				irmao(elemento)->cor=VERMELHO;
				elemento->pai->dir=NULL;
				free(elemento);
			}
			return;
			
		}
		//caso 5(correto)
		else if(cor(irmao(elemento))==PRETO && cor(irmao(elemento)->esq)==VERMELHO ){
			ajustarCaso5(raiz,elemento);
			return;
			
		}
		//caso 6(correto)
		else if (cor(irmao(elemento))==PRETO && cor(irmao(elemento)->dir)==VERMELHO){
			ajustarCaso6(raiz,elemento);
			return ;
		}
		
	
        }

	//CASO 4(correto)
	else if(cor(elemento->pai)==VERMELHO){
		
		if( cor(irmao(elemento)) == PRETO &&  cor(irmao(elemento)->dir)==PRETO && cor(irmao(elemento)->esq)==PRETO){
			elemento->pai->cor=PRETO;
			irmao(elemento)->cor=VERMELHO;
			if(eh_filho_esquerdo(elemento)){
						elemento->pai->esq=NULL;
				 		free(elemento);
						
						
					}
					else{
						elemento->pai->dir=NULL;
						free(elemento);
					        
					}
			return;
			
		}
		//caso 5(correto)
		else if(cor(irmao(elemento))==PRETO && cor(irmao(elemento)->esq)==VERMELHO ){
			ajustarCaso5(raiz,elemento);
			
			return;
		}
		//caso 6(correto)
		else if (cor(irmao(elemento))==PRETO && cor(irmao(elemento)->dir)==VERMELHO){
			ajustarCaso6(raiz,elemento);
			return;
		}
		
		
		
	}
	
	
	
	
}
/*
void remover (int valor, arvore *raiz){
	arvore aux=*raiz;

	if(aux==NULL){
		return;
	} 
	else if(valor!=aux->dado){
		while(aux->dado!=valor){
			
			if(valor>aux->dado){
				aux =aux->dir;
				if(aux==NULL){
					break;
				}
			}
			else if(valor<aux->dado){
				aux =aux->esq;
				if(aux==NULL){
					break;
				}
			}
			
			
		}
		remover(valor,&aux);		
	}
	

	else if (aux->dado==valor){
			
		//Nó não tem filhos
		if(aux->esq==NULL && aux->dir==NULL){
				
			//Nó vermelho
			if(cor(aux)==VERMELHO){
					if(eh_filho_esquerdo(aux)){
						aux->pai->esq=NULL;
				 		aux=NULL;
					}
					else{
						aux->pai->dir=NULL;
						aux=NULL;
					}
					
					
			}
			//Nó preto
			else{
				
				aux->cor=duploNull;
		       		aux->dado=-1;
				
			        removerAjustar(raiz,aux);
				
				return;
				
				
				  
			}
		}
		
		//Nó removido tem um filho		
		else if(aux->dir==NULL) {
			aux->dado =aux->esq->dado;
	        	remover(aux->dado, &aux->esq);
			
				
			
		}
		else if(aux->esq==NULL) {
			aux->dado =aux->dir->dado;
	        	remover(aux->dado, &aux->dir);
			
		}
		//Nó tem dois filhos
		else{
		
		aux->dado =aux->dir->dado;
	        remover(aux->dado, &aux->dir);
		}
		
	}
imprimir(*raiz);
//quando chega aqui ja perde parte da arvore
	 
	
}
*/
void remover (int valor,arvore *raiz) {
    arvore temp, pai, novo;
    temp = *raiz;
    pai = NULL;
    

    //Percorre a arvore até achar o elemento ou null
    while(temp != NULL && temp->dado != valor) {
        pai = temp;
        if(valor > temp->dado) {
            temp = temp->dir;
        } else {
            temp = temp->esq;
        }
    }
    
    //Se o elemento não existe encerra a função
    if(temp == NULL){
	return;
    }
          

    //O elemento a ser removido tem dois filhos
    if(temp->esq != NULL && temp->dir != NULL) {
        temp->dado = maior_elemento(temp->esq);
        remover(temp->dado,&temp->esq);
        return ;
    }
    
    //Tem somente o filho esquerdo
    if(temp->esq != NULL && temp->dir == NULL) {
       *raiz = temp->esq;
        temp->cor = PRETO;
        return ;
    }
    
    if(temp->dir != NULL && temp->esq == NULL) {
       *raiz = temp->dir;
        temp->cor = PRETO;
        return ;
    }

    //Não tem filhos e é vermelho
    if(temp->cor == VERMELHO) {
        if(eh_filho_esquerdo(temp)) {
            temp->pai->esq = NULL;
        } else {
            temp->pai->dir = NULL;  
        }
        return ;          
    }
				
   else{		        
    //Nao tem filhos e é preto - pode ser declarado e inicializado como global. Daqui ...
	/*
    arvore no_null =(arvore) malloc(sizeof(struct no_bst));
    no_null->cor =duploNull;
    no_null->esq = NULL;
    no_null->dir = NULL;
    //... Até aqui 
    */
    temp->dado=0;
    temp->cor=duploNull;
    //no_null->pai =temp->pai;
      
    removerAjustar(raiz,temp);
    }
}


