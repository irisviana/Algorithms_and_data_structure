#include <stdio.h>
#include <stdlib.h>
#include "m_buscaLargura.h"

int main(int argc, char * argv[]) {
	grafo g;
	int opcao;
	
	
	
	
	inicializar(lerVerticeArestaEmapa(&g,"text.txt"));
	while(1) {
		scanf("%d", &opcao);
		switch(opcao) {
				int valor;
				case 1:	
                                        
					 vizualizarResultado(&g,"text.txt");
					 if(procurarVertice(&g,"a")!=NULL){
						vertice *ve = malloc(sizeof(struct vertice) *4);
						ve=procurarVertice(&g,"a");
						buscaLargura_Grafo(&g,*ve);
					}
					
						
						break;

			
				case 2:         lerMapa(&g);
						break;
				
		                case 3:
					if(procurarVertice(&g,"a")!=NULL && procurarVertice(&g,"e")!=NULL ){
						vertice *ve = malloc(sizeof(struct vertice) *4);
						ve=procurarVertice(&g,"a");
						vertice *va = malloc(sizeof(struct vertice) *4);
						va=procurarVertice(&g,"e");
					        imprimirCaminho_MaisCurto(&g,*ve,*va);
					}
					break;

					
				case 99:
						exit(0);
}
}
	
}
