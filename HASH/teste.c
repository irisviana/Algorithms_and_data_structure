#include "hash.h"
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {

int opcao;
int isbn;
struct tabela_livro *tabela;
inicializar_tabela(tabela,"dados.txt","indices.txt") ;

    while(1) {
		int opcao;
		scanf("%d", &opcao);

		switch(opcao) {
				
				case 1:
					adicionar_livro(tabela, ler_livro());
					break;
				case 2:
				        imprimirTabela_livros(tabela->tabela_hash);
					break;
				
				case 3:
					printf ("Digite o isbn: ");
					
    					scanf("%d",&isbn);
					remover_indice(tabela->tabela_hash,isbn);
					break;
				case 4:
					printf ("Digite o isbn: ");
					
    					scanf("%d",&isbn);
				       imprimir_livro(ler_livro_arquivo(tabela,isbn)) ;
					//obs:quando edita um livro e tenta imprimir o conteudo não funciona
					break;
				case 5:
					
					editar_livro(tabela);
					break;
				case 6:
					 listarLivros(tabela);
					break;
				case 7:
					salvar_arquivo(tabela,"indices.txt");
					 exit(0);
	}	}
					
    
   


}
