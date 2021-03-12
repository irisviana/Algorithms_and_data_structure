#include <stdio.h>
#include <stdlib.h>
#include "M_P.h"

int main(int argc, char * argv[]) {
	grafo g;
	int opcao;
	
	
	
	inicializar(lerVerticeArestaEmapa(&g,"text.txt"));
	while(1) {
		scanf("%d", &opcao);
		switch(opcao) {
				int valor;
				case 1:	//printf("Digite o nome do arquivo que deseja abrir,(ex:nome.txt)");
					//char *arq=(char*)malloc(50*sizeof(char));
					//scanf("%s",arq);
                                        
					 vizualizarResultado(&g,"text.txt");
					imprimirListaAux(&g);
					 //imprimir(&g);
					//lerListaAresta(&g);
					//printf("\n");
					//lerCaminhoMin(&g);
					
						
						break;

			
				case 2:        // lerMapa(&g);
						break;

					
				case 99:
						exit(0);
}
}
	
}
