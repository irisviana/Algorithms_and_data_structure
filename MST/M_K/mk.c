#include <stdio.h>
#include <stdlib.h>
#include "mk.h"
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
int peso;
char v1[30];
char v2[30];
fseek(arq,(g->v*2)+3,SEEK_SET);
while(contador<g->a){
       struct aresta *ar = malloc(sizeof(struct aresta) * 3);
	fscanf(arq,"%s %d\n",nome,&peso);
	sprintf(nome, "%s",nome);
        
        sprintf(v1,"%c",nome[0]);
	sprintf(v2,"%c",nome[1]);
	ar->vert1=*procurarVertice(g,v1);
	ar->vert2=*procurarVertice(g,v2);
	procurarVertice(g,v2);
        ar->peso=peso;
       
        g->listaAresta[contador]=*ar;
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
	ve->percorido=0;//ainda não foi percorido
	g->mapa[parada]=*ve;//lista de vértices
        
	parada++;
}

}
fclose(arq);

}

void vizualizarResultado(grafo *g,char *arquivo){
	caregarMapa(g,arquivo);
	lerArestas(g,arquivo);
	ordenarListaAresta(g);
	 calcularKruskal(g);
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

void lerListaAresta(grafo *g){
if(g->listaAresta!=NULL){
for(int i=0;i<g->a;i++){
	printf("%d %s %s",(g->listaAresta[i].peso),g->listaAresta[i].vert1.nome,g->listaAresta[i].vert2.nome);
	
	printf("\n");
}
}
else{
	printf("lista de arestas vazio");
}
}
void lerCaminhoMin(grafo *g){
if(g->arvoreGeradoMin!=NULL){
for(int i=0;i<g->tamanho_arvoreMin;i++){
	printf("%d %s %s",(g->arvoreGeradoMin[i].peso),g->arvoreGeradoMin[i].vert1.nome,g->arvoreGeradoMin[i].vert2.nome);
	
	printf("\n");
}
}
else{
	printf("lista de arestas vazio");
}
}


void inicializar (grafo *g) {
	int i,j;
	
	
        g->mapa = malloc(sizeof(struct vertice) * g->v );
	g->matriz = (long **) malloc(sizeof(long) * g->v );
        g->listaAresta=malloc(sizeof(struct aresta) * g->a );
        g->arvoreGeradoMin=malloc(sizeof(struct aresta) * g->a );
	g->tamanho_arvoreMin=0;
	for(i =0; i < g->v ; i++)
		g->matriz[i] = (long *) malloc(sizeof(long) * g->v );
		
	for(i =0; i < g->v ; i++) {
		for(j=0; j < g->v ; j++) {
					
					g->matriz[i][j] = 0;
				
		}
	}
	
}

void ordenarListaAresta(grafo *g){
        aresta *ar =malloc(sizeof(struct aresta));
	for (int i = 1; i <g->a; i++) {
        for (int j = 0; j < i; j++) {
        if (g->listaAresta[i].peso<g->listaAresta[j].peso) {
             *ar=g->listaAresta[i];
             g->listaAresta[i] = g->listaAresta[j];
             g->listaAresta[j] = *ar;
        }
    }
}
}

void calcularKruskal(grafo *g){
	
        for(int i=0;i<g->a;i++){
		if(g->tamanho_arvoreMin==0){
			g->arvoreGeradoMin[i]=g->listaAresta[i];
			g->tamanho_arvoreMin=g->tamanho_arvoreMin+1;
        	}
		else{
			if(g->tamanho_arvoreMin!=((g->v)-1)){
				if(verificarCiclo(g,g->listaAresta[i])==0){//verfica se existe ciclo ou se todos os vertices foram percoridos
				g->arvoreGeradoMin[i]=g->listaAresta[i];
				g->tamanho_arvoreMin=g->tamanho_arvoreMin+1;
			       }
			}
			
		}

        }
	
}
/*
int verificarVerticesPercorido(grafo *g,aresta ar){//retorna 1 se nem todos os vertices foram achados
	
	if (procurarVertice(grafo *g,char * nome){
		vertice *ve = malloc(sizeof(struct vertice) * g->v);
		if(ve->percorido==1){
		}
	}
	

}
*/

int verificarCiclo(grafo *g,aresta a){//retorna 1 se não há ciclo
		
		int haCiclo=0;
		
                for(int j=0;j<g->tamanho_arvoreMin;j++){
			

			if(((strcmp(g->arvoreGeradoMin[j].vert1.nome,a.vert1.nome)==0) && (strcmp(g->arvoreGeradoMin[j].vert2.nome,a.vert1.nome)==0)) ||
			((strcmp(g->arvoreGeradoMin[j].vert1.nome,a.vert2.nome)==0) && (strcmp(g->arvoreGeradoMin[j].vert2.nome,a.vert2.nome)==0))){
  
			
				
				haCiclo=1;
			
		}
}

  
return haCiclo;
}
	
/*
	int extreminade1=0;
        int extremidade2=0;
        int haCiclo=0;
        for(int i=0;i,g->tamanho_arvoreMin;i++){

		for(int j=0;j,g->tamanho_arvoreMin;j++){

			if((strcmp(g->arvoreGeradoMin[i].ex1,g->arvoreGeradoMin[j].ex1) == 0 && strcmp(a.ex1,g->arvoreGeradoMin[j].ex2) == 0) || 
				(strcmp(a.ex1,g->arvoreGeradoMin[j].ex1) == 0 && strcmp(g->arvoreGeradoMin[i].ex1,g->arvoreGeradoMin[j].ex2) == 0 )){
				extreminade1=1;
			}
			
			if((strcmp(g->arvoreGeradoMin[i].ex2,g->arvoreGeradoMin[j].ex1) == 0 && strcmp(a.ex2,g->arvoreGeradoMin[j].ex2) == 0) || 
				(strcmp(a.ex2,g->arvoreGeradoMin[j].ex1) == 0 && strcmp(g->arvoreGeradoMin[i].ex2,g->arvoreGeradoMin[j].ex2) == 0 )){
				extremidade2=1;
			}
			
		}
		
	}
	if((extreminade1==1 ) && (extremidade2=1)){
		haCiclo=1;
	}
	return haCiclo;
        */


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

void imprimir(grafo *g) {
		
		int i,j;

		for(i =0; i < g->v; i++) {
				
				for(j = 0; j < g->v; j++) {
						printf("\t%ld", g->matriz[i][j]);
				}					
				printf("\n");
		}
}




