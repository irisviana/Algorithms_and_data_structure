#include <stdio.h>
#include <stdlib.h>
#include "m_buscaProfundidade.h"
#include <string.h>


void adicionarAresta(grafo *g, char v1, char v2){
   char v11[30];
   char v21[30];
   sprintf(v11,"%c",v1);
   sprintf(v21,"%c",v2);
   

	

	
    for (int j=0;j<g->v;j++){
	if (strcmp(g->mapa[j].nome,v11) == 0){//se for igual
		
		for(int i=0; i<g->v; i++){
    			if (strcmp(g->mapa[i].nome,v21) == 0){
				g->matriz[g->mapa[j].indice][g->mapa[i].indice]=1;
				g->matriz[g->mapa[i].indice][g->mapa[j].indice]=1;
				
				
				g->matriz[g->mapa[j].indice][g->mapa[j].indice]=1;
				g->matriz[g->mapa[i].indice][g->mapa[i].indice]=1;
			
    				
	}
		}

			}

           			}

}


grafo* lerVerticeArestaEmapa(grafo *g,char *arquivo){
 
  int numVertice,numAresta;
 

 FILE *arq = fopen(arquivo, "r");
 if(arq == NULL){
   printf("Erro, nao foi possivel abrir o arquivo\n");
 }else{

fscanf(arq,"%d %d\n",&numVertice,&numAresta);
}
g->v=numVertice;
g->a=numAresta;
fclose(arq);
return g;

}


void lerArestas(grafo *g,char *arquivo){
FILE *arq = fopen(arquivo, "r");
	
	int contador=0;
 if(arq == NULL){
   printf("Erro, nao foi possivel abrir o arquivo\n");
 }else{
char nome[30];
fseek(arq,9,SEEK_SET);
while(contador<g->a){
	fscanf(arq,"%s\n",nome);
	sprintf(nome, "%s",nome);
	adicionarAresta(g,nome[0],nome[1]);
	
	contador++;
	
}
}
fclose(arq);
}
void caregarMapa(grafo *g,char *arquivo){
int parada=0;
FILE *arq = fopen(arquivo, "r");
	
	
 if(arq == NULL){
   printf("Erro, nao foi possivel abrir o arquivo\n");
 }else{
char nome[30];
fseek(arq,g->v,SEEK_SET);

while(parada<g->v){
	struct vertice *ve = malloc(sizeof(struct vertice) * 2);
	fscanf(arq,"%s",nome);
	
	sprintf(ve->nome, "%s",nome);
	

	ve->indice=parada;
	g->mapa[parada]=*ve;//lista de vértices
        
	parada++;
}

}
fclose(arq);

}
void vizualizarResultado(grafo *g,char *arquivo){
	caregarMapa(g,arquivo);
	lerArestas(g,arquivo);
}
void lerMapa(grafo *g){
if(g->mapa!=NULL){
for(int i=0;i<g->v;i++){
	printf("%d %s",(g->mapa[i].indice),g->mapa[i].nome);
	
	printf("\n");
}
}
else{
	printf("Mapa de arestas vazio");
}
}


void inicializar (grafo *g) {
	int i,j;
	
	
        g->mapa = malloc(sizeof(struct vertice) * g->v );
	g->matriz = (long **) malloc(sizeof(long) * g->v );
	g->tempoTerminado=malloc(sizeof(int) * g->v );
	g->tempoDescoberto=malloc(sizeof(int) * g->v );
        g->cor=malloc(sizeof(enum cor) * g->v );
	g->arvore= malloc(sizeof(struct vertice) * g->v );
 
	for(i =0; i < g->v ; i++)
		g->matriz[i] = (long *) malloc(sizeof(long) * g->v );
		
	for(i =0; i < g->v ; i++) {
		for(j=0; j < g->v ; j++) {
					
					g->matriz[i][j] = 0;
				
		}
	}
	
}
void buscaProfundidade_Grafo(grafo *gr){
   struct vertice *ve = malloc(sizeof(struct vertice) * gr->v);
   int tempo=0;
   
   for(int i=0;i<gr->v;i++){
	
        
		gr->cor[i]=BRANCO;//cada cor esta relacionada com o indice de cada vertice
		gr->arvore=ve;
        	
	
   }
    
   for(int i=0;i<gr->v;i++){
	
        
		if(gr->cor[i]=BRANCO){
			buscaProfundidade_visit(gr,tempo,gr->mapa[i]);
		}
		
        	
	
   }
}
void buscaProfundidade_visit(grafo *g,int tempo,vertice u){
    tempo=tempo+1;
    g->cor[u.indice]=CINZA;
    g->tempoDescoberto[u.indice]=tempo;
    for(int j=0; j<g->v; j++){
	    if(g->matriz[u.indice][j] != 0 && u.indice!=j){
            	if(g->cor[g->mapa[j].indice]==BRANCO){
		
		 g->arvore[g->mapa[j].indice]=u;
		 buscaProfundidade_visit(g,tempo,g->mapa[j]);
		
               
            }
	}
     }
        g->cor[u.indice]=PRETO;
	tempo=tempo+1;
	g->tempoTerminado[u.indice]=tempo;
	
        

    
}
    
vertice * procurarVertice(grafo *g,char * nome){
	vertice *ve = malloc(sizeof(struct vertice) * g->v);
	if(g->mapa!=NULL){
		for(int i=0;i<g->v;i++){
			if(strcmp(g->mapa[i].nome,nome)==0){
				*ve=g->mapa[i];
				break;
			}
	}
	}
return ve;

}

void imprimirCaminho_MaisCurto(grafo *g,vertice s,vertice v){

	if(strcmp(s.nome,v.nome) == 0){
		printf("%s",s.nome);
	}
        else if (&g->arvore[v.indice]==NULL){
          printf("nenhum caminho existente");
        }
        else{
		imprimirCaminho_MaisCurto(g,s,g->arvore[v.indice]);
		printf("%s",v.nome);
		
        }
      
	
}
void imprimirResultadoBusca(grafo *g){

}
void imprimir(grafo *g) {
		
		int i,j;

		for(i =0; i < g->v; i++) {
				
				for(j = 0; j < g->v; j++) {
						printf("\t%ld", g->matriz[i][j]);
				}					
				printf("\n");
		}
}



