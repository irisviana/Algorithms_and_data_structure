#include <stdio.h>
#include <stdlib.h>
#include "m_buscaLargura.h"
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
	g->distancia=malloc(sizeof(int) * g->v );
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

void buscaLargura_Grafo(grafo *gr,vertice s){
   struct vertice *ve = malloc(sizeof(struct vertice) * gr->v);
   fila *f =cria_Fila();
   
   for(int i=0;i<gr->v;i++){
	
        
		gr->cor[i]=BRANCO;//cada cor esta relacionada com o indice de cada vertice
		gr->distancia[i]=-1;//-1 vai ser o infinito
        	gr->arvore[i]=*ve;//depos verificar
	
   }
    gr->cor[s.indice]=CINZA;
    gr->distancia[s.indice]=0;
    
    insere_Fila(f, s);
    
    while(!Fila_vazia(f)){
        vertice u=gr->mapa[remove_Fila(f)];//ao remover retorna o indice do vertice removido
        for(int j=0; j<gr->v; j++){
	    if(gr->matriz[u.indice][j] != 0 && u.indice!=j){
            	if(gr->cor[gr->mapa[j].indice]==BRANCO){
		 gr->cor[gr->mapa[j].indice]=CINZA;
		 gr->distancia[gr->mapa[j].indice]=(gr->distancia[s.indice])+1;
		 gr->arvore[gr->mapa[j].indice]=u;
		 insere_Fila(f,gr->mapa[j]);}
               
            }
	}
        gr->cor[u.indice]=PRETO;
        
}
    
    free(f);
   

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
fila* cria_Fila(){
    fila *fi;
    fi = (fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void libera_Fila(fila* fi){
    free(fi);
}
int insere_Fila(fila* fi, vertice vert){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi->dados[fi->final] = vert;
    fi->final = (fi->final+1)%MAX;
  
    return 1;
}
int remove_Fila(fila* fi){
    int indice=-1;
    if(fi == NULL || Fila_vazia(fi))
        return -1;
    indice= fi->inicio;
    fi->inicio = (fi->inicio+1)%MAX;
    return indice;
}
int Fila_cheia(fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->inicio == (fi->final+1)%MAX)
        return 1;
    else
        return 0;
}
int Fila_vazia(fila* fi){
    if(fi == NULL)
        return -1;
    return (fi->inicio == fi->final);
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



