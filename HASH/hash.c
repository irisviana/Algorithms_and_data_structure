#include "hash.h"
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


livro* ler_livro() {//FUNCIONANDO
    livro * novo = (livro *) malloc(sizeof(livro));
    char * buffer = (char *) malloc(sizeof(char) * 256);
    printf ("Digite o isbn: ");
    scanf("%d", &novo->isbn);
	getchar() ;
    printf ("Digite o titulo: ");
    fgets(buffer, 256, stdin);
    novo->titulo = strdup(tirar_enter(buffer));

    printf ("Digite o autor: ");
    fgets(buffer, 256, stdin);
    novo->autor = strdup(tirar_enter(buffer));

    printf ("Digite o editora: ");
    fgets(buffer, 256, stdin);
    novo->editora = strdup(tirar_enter(buffer));

    free(buffer);
  
return novo;


}
char * tirar_enter(char *string) {//FUNCIONANDO
	string[strlen(string) -1] = '\0';
    return string;
}


void inicializar_tabela(tabela_livros *tabela, char *nome_tabelaDados,char *nome_tabelaIndices) {//FUNCIONANDO

    
    tabela->dados= fopen(nome_tabelaDados,"a");
    tabela->indice= fopen(nome_tabelaIndices,"a");
    if(tabela->dados && tabela->indice == NULL) {
        exit(1);
    }
    
    inicializar_Hash(tabela);

}
void inicializar_Hash(tabela_livros *tabela){//FUNCIONANDO
   
    for(int i=0;i<tamanho;i++){
	tabela->tabela_hash[i]=NULL;
	}
	lerArquivo_indice(tabela);

   	
}

void adicionar_livro(tabela_livros *tabela, livro *l) {//FUNCIONANDO
	if( procurar_indice(l->isbn,tabela->tabela_hash)==-1){
     		int referencia=escrever_livro_arquivo(tabela,l);
     
     		adicionar_indice(l->isbn,referencia, tabela->tabela_hash);
	}
	else{
		printf("Livro já adicionado");
		
        }
}

void editar_livro(tabela_livros *tabela){//FUNCIONANDO
	livro *l=ler_livro();
	remover_indice(tabela->tabela_hash,l->isbn);
	adicionar_livro(tabela,l );


}
void adicionarTabela_indice(tabela_livros *tabela){//FUNCIONANDO
	tabela->indice= fopen("indices.txt","w");
	 if(tabela->indice!=NULL){
		fseek(tabela->indice, 0, SEEK_END);
		for(int i=0;i<tamanho;i++){
			if(tabela->tabela_hash[i]!=NULL){
				no_hash *aux=tabela->tabela_hash[i];
				while(aux!=NULL){
					  
						fprintf(tabela->indice, "%d|",tabela->tabela_hash[i]->chave);
						fprintf(tabela->indice, "%d|",tabela->tabela_hash[i]->referencia);
						fputs("\n",tabela->indice);
						aux=aux->prox;
						
					}
					}
				
		}
	}
	fclose(tabela->indice);
}

int escrever_livro_arquivo(tabela_livros *tabela, livro * l) {//FUNCIONANDO
   
    int fim;
    fseek(tabela->dados, 0, SEEK_END);
    fim = ftell(tabela->dados);

    fprintf(tabela->dados, "%d|",l->isbn);
    fprintf(tabela->dados, "%s|", l->titulo);
    fprintf(tabela->dados, "%s|", l->autor);
    fprintf(tabela->dados, "%s|", l->editora);
    fputs("\n",tabela->dados);
     fclose(tabela->dados);
    return fim;

}

int calcular_posicaoHashing(int isbn){//FUNCIONANDO
	int posicao=isbn%tamanho;
	return posicao;

}

void salvar_arquivo(tabela_livros *tabela,char *nome_tabelaIndices){//FUNCIONANDO
	//fclose(tabela->dados);
	 adicionarTabela_indice(tabela);
	
}
void adicionar_indice(int chave,int referencia,no_hash *tabela[]){//FUNCIONANDO
	
		int posicao=calcular_posicaoHashing(chave);
		
			no_hash *novo=(no_hash *) malloc(sizeof(no_hash));
			novo->referencia=referencia;
			novo->chave=chave;
			novo->prox=tabela[posicao];
			tabela[posicao]=novo;
		
		
		
}

void lerArquivo_indice(tabela_livros *tabela){//FUNCIONANDO
	
	FILE *fp=fopen("indices.txt","r");
	if(fp!=NULL && tabela->indice!=NULL){
		
       		
	 	while(fp!=NULL){
	 		int chave = atoi(ler_campo(fp));
    	 		int referencia= atoi(ler_campo(fp));
			
			if(chave ==0 && referencia==0){
				break;
			}
			else{
				adicionar_indice(chave,referencia,tabela->tabela_hash);
				
			}
			
                        
	
		}
	}
}
int procurar_indice(int isbn,no_hash *tabela[]){
        int retorno=-1;
	int posicao=calcular_posicaoHashing(isbn);
	 if(tabela!=NULL){
	
		no_hash *aux=tabela[posicao];
		while(aux!=NULL){
			if(aux->chave==isbn){
				retorno=aux->referencia;
				break;
						
		        }
						
			aux=aux->prox;
						
			}
				
		}
		
	return retorno;
		
		

	}
	

void remover_indice(no_hash *tabela[],int isbn){//FUNCIONANDO
	int posicao=calcular_posicaoHashing(isbn);
	no_hash *aux;
	if(tabela[posicao]!=NULL){
		if(tabela[posicao]->chave==isbn){
			aux=tabela[posicao];
			tabela[posicao]=tabela[posicao]->prox;
			free(aux);
		}
		else{
			aux=tabela[posicao]->prox;
			no_hash *ant=tabela[posicao];
			while(aux!=NULL && (aux->chave!=isbn)){
				ant=aux;
				aux=aux->prox;
				
			}
			if(aux!=NULL){
				ant->prox=aux->prox;
				free(aux);
			}
			else{
				printf("isbn não existe na tabela de indice");
			}
		}
	}
	else{
		printf("isbn não existe na tabela de indice");
	}
}


livro * ler_livro_arquivo(tabela_livros *tabela,int isbn) {//FUNCIONANDO
     livro *novo=NULL;
	int a;
     int referencia=procurar_indice(isbn,tabela->tabela_hash);
     if(referencia!=-1){
	FILE *fp=fopen("dados.txt","r");
	fseek(fp,referencia,SEEK_SET);
        novo = (livro *) malloc(sizeof(livro));
	
    	 int isbn=atoi(ler_campo(fp));
	 char *titulo= strdup(ler_campo(fp));
	 char *autor= strdup(ler_campo(fp));
	 char *editora=strdup(ler_campo(fp));
	 
	 novo->isbn =isbn;
    	 novo->titulo = titulo;
    	 novo->autor =autor;
    	 novo->editora = editora;
	 

	}

       return novo;
}

char * ler_campo(FILE * fp) {//FUNCIONANDO

   
    char * buffer = (char *) malloc(sizeof(char) * 256);
    for(int i = 0; i < 256; i++) {
        buffer[i] = fgetc(fp);
        if(buffer[i] =='|') {
            buffer[i] = '\0';
            break;
        }
    }
    return buffer;

}

void imprimir_livro(livro *l) {//FUNCIONANDO
    if(l!=NULL){
    printf("ISBN: %d\n", l->isbn);
    printf("TITULO: %s\n", l->titulo);
    printf("AUTOR: %s\n", l->autor);
    printf("EDITORA: %s\n", l->editora);
	}

}
void listarLivros(tabela_livros *tabela){//FUNCIONANDO
	if(tabela->tabela_hash!=NULL){
	
		for(int i=0;i<tamanho;i++){
			if(tabela->tabela_hash[i]!=NULL){
				
				
			        no_hash *aux=tabela->tabela_hash[i];
				while(aux!=NULL){
					 imprimir_livro(ler_livro_arquivo(tabela,aux->chave));
					
					aux=aux->prox;
				}
				
				}
	
			

    			
		}

	}

}
void imprimirTabela_livros(no_hash *tabela[]){//FUNCIONANDO
	if(tabela!=NULL){
	
		for(int i=0;i<tamanho;i++){
			
			if(tabela[i]!=NULL){
				printf("posicao na tabela:[%d] ISBN: %d\n",i, tabela[i]->chave);
				printf("posicao na tabela:[%d] Referencia: %d\n",i,tabela[i]->referencia);
			        no_hash *aux=tabela[i]->prox;
				while(aux!=NULL){
					printf("posicao na tabela:[%d] ISBN: %d\n",i, aux->chave);
					printf("posicao na tabela:[%d] Referencia: %d\n",i,aux->referencia);
					aux=aux->prox;
				}
				
				}
	
			

    			
		}

	}
}

