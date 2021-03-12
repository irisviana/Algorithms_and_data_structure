#include <stdio.h>
#include <stdlib.h>
#include "m_buscaProfundidade.h"

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
					if(procurarVertice(&g,"a")!=NULL){
						vertice *ve = malloc(sizeof(struct vertice) *4);
						ve=procurarVertice(&g,"a");
						buscaProfundidade_Grafo(&g);
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
					
					
					
					
					break;	
						
		                

					
				case 99:
						exit(0);
}
}
	
}
