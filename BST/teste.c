#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char * argv[]) {
	arvore a;
	int opcao;
	inicializar(&a);

	while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				case 1:
					scanf("%d", &valor);
						a = adicionar(valor, a);
						break;
				
				case 2:
					pre_ordem(a);
					printf("\n");
					break;
				case 3:
					in_ordem(a);
					printf("\n");
					break;
				case 4:
					pos_ordem(a);
					printf("\n");
					break;
				case 5: 
					scanf("%d", &valor);
					a= remover( valor,a);
					break;
				case 6:
					printf("[%d]",maior_elemento(a));
					break;
				case 7:
					
					printf("[%d]",menor_elemento(a));
					break;
				case 8:
					
					printf("%d",altura(a));
					break;
				case 9:
					scanf("%d", &valor);
					printf("%d",procurarPaiElemento(valor,a));
					break;
				case 10:
					scanf("%d", &valor);
					
					printf("%d",procurarSucessor(valor,a,a));
					break;
				case 11:
					scanf("%d", &valor);
					printf("%d", procurarAntecessor(valor,a,a));
					break;
				/*
				case 12:
					imprimirArvore(a);
					printf("\n");
					break;
	 			*/
				
		               
					 
				case 999:
					exit(0);	
 			}
	}
}	

