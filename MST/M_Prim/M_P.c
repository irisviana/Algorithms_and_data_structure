#include <stdio.h>
#include <stdlib.h>
#include "M_P.h"
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
	ordenarListaAresta(g->listaAresta,g->a);
	 calcularPrim(g);
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
	g->tamanho_listaAux=0;
        //g->listaAux=malloc(sizeof(struct aresta) * g->a );
	for(i =0; i < g->v ; i++)
		g->matriz[i] = (long *) malloc(sizeof(long) * g->v );
		
	for(i =0; i < g->v ; i++) {
		for(j=0; j < g->v ; j++) {
					
					g->matriz[i][j] = 0;
				
		}
	}
	for(j=0; j <tamanho ; j++) {
					
					g->listaAux[j] = NULL;
				
		}
	
}

void ordenarListaAresta(aresta *lista,int tam){
       aresta *ar=malloc(sizeof(struct aresta) *tam);
	aresta *vazia=malloc(sizeof(struct aresta) *tam);
	for (int i = 1; i <tam; i++) {
        for (int j = 0; j < i; j++) {
       
        if (lista[i].peso<lista[j].peso) {
             *ar=lista[i];
             lista[i] =lista[j];
             lista[j] = *ar;     
}
    
}
}
}

void calcularPrim(grafo *g){
	 
       int i=0;
       int j=0;
		
		if(g->tamanho_arvoreMin==0){
			g->arvoreGeradoMin[i]=g->listaAresta[i];
			g->tamanho_arvoreMin=g->tamanho_arvoreMin+1;
			procurarVerticeAdj(g,g->arvoreGeradoMin[i]);
			ordenarListaAresta(*g->listaAux,g->tamanho_listaAux);
			
			i++;
			}
		
		while(g->listaAux!=NULL || g->tamanho_arvoreMin!=((g->v)-1) ){
				
			if(verificarCiclo(g,*g->listaAux[j])==0){
					g->arvoreGeradoMin[i]=*g->listaAux[j];
					g->tamanho_arvoreMin=g->tamanho_arvoreMin+1;
					g->listaAux[j]=NULL;
					procurarVerticeAdj(g,g->arvoreGeradoMin[i]);
					ordenarListaAresta(*g->listaAux,g->tamanho_listaAux);
					
					i++;
				}
				else{
					g->listaAux[j]=NULL;
					
					j++;
				}
			}

        
	
}
void imprimirListaAux(grafo *g){
for(int i=0;i<g->tamanho_listaAux;i++){
				 if(g->listaAux[i]!=NULL){
			        printf("%s,%s",g->listaAux[i]->vert1.nome,g->listaAux[i]->vert2.nome);
				printf("\n");
                      }      }
        	
}
void procurarVerticeAdj(grafo *g,aresta a){
	
	
	 for(int j=0; j<g->v; j++){
	   
	    if(g->matriz[a.vert1.indice][j] != 0 && a.vert1.indice!=j){
				if(g->mapa[j].indice!=a.vert2.indice){

			         if(verificarArestaRepetida(g,g->mapa[j],g->mapa[a.vert1.indice])==0 ){
					if(verificarArestaArvoreMin(g,g->mapa[j],g->mapa[a.vert1.indice])==0){
					inserirListaArestaAux(g,g->mapa[j],g->mapa[a.vert1.indice]);
				       }
				}
			        }
			
	    }
	    if(g->matriz[a.vert2.indice][j] != 0 && a.vert2.indice!=j && (g->matriz[a.vert1.indice][a.vert2.indice]!=0)){
			if(g->mapa[j].indice!=a.vert1.indice){
			if (verificarArestaRepetida(g,g->mapa[j],g->mapa[a.vert2.indice])==0){
				if(verificarArestaArvoreMin(g,g->mapa[j],g->mapa[a.vert1.indice])==0)
				inserirListaArestaAux(g,g->mapa[j],g->mapa[a.vert2.indice]);
				}
			}
			}
	    }
	}



int verificarArestaRepetida(grafo *g,vertice v1,vertice v2){
	int existe=0;
	aresta *ar =malloc(sizeof(struct aresta));
  for(int i=0;i<g->tamanho_listaAux;i++){
			if(g->listaAux[i]!=NULL){
				if(g->listaAux[i]->vert1.indice == v1.indice && g->listaAux[i]->vert2.indice == v2.indice){
					existe=1;
					break;
				}
				if(g->listaAux[i]->vert1.indice==v2.indice && g->listaAux[i]->vert2.indice == v1.indice){
					existe=1;
					break;
		}
}}
        return existe;   
     
}

int verificarArestaArvoreMin(grafo *g,vertice v1,vertice v2){
	int existe=0;
	aresta *ar =malloc(sizeof(struct aresta));
  for(int i=0;i<g->tamanho_arvoreMin;i++){
			
				if(g->arvoreGeradoMin[i].vert1.indice == v1.indice && g->arvoreGeradoMin[i].vert2.indice == v2.indice){
					existe=1;
					break;
				}
				if(g->arvoreGeradoMin[i].vert1.indice==v2.indice && g->arvoreGeradoMin[i].vert2.indice == v1.indice){
					existe=1;
					break;
		}
}
        return existe;   
     
}
void inserirListaArestaAux(grafo *g,vertice v1,vertice v2){
	
	
	for(int i=0;i<g->a;i++){
		if(g->listaAresta[i].vert1.indice==v1.indice && g->listaAresta[i].vert2.indice==v2.indice){
			g->listaAux[g->tamanho_listaAux]=&g->listaAresta[i];
			g->tamanho_listaAux++;
		}
		if(g->listaAresta[i].vert1.indice==v2.indice && g->listaAresta[i].vert2.indice==v1.indice){
			g->listaAux[g->tamanho_listaAux]=&g->listaAresta[i];
			g->tamanho_listaAux++;
		}
	}
}


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




