#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char * argv[]) {
	arvore a;
	int opcao;
	int controleFB;
	inicializar(&a);

	while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				
				case 1:
						scanf("%d", &valor);
						a = adicionar(valor, a, &controleFB);
						break;
				
				case 2:
						pre_order(a);
						printf("\n");
						break;
				
				case 3:
						scanf("%d", &valor);
						a = remover(a, valor,&controleFB);
						break;
				
				case 999:
						exit(0);
		}
	}
}

