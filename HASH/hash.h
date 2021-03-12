#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef ARQUIVOHASH_H
#define ARQUIVOHASH_H
#define tamanho 11

typedef struct livro {
    int isbn;
    char *titulo;
    char *autor;
    char *editora;
} livro;

typedef  struct hash {
    int chave;
    int referencia;
    struct hash *prox;
} no_hash;

typedef struct tabela_livro {
   
    no_hash *tabela_hash[tamanho];
    FILE * dados;
    FILE * indice;
}tabela_livros;



void inicializar_tabela(tabela_livros *tabela, char *nome_tabelaDados,char *nome_tabelaIndices) ;
void inicializar_Hash(tabela_livros *tabela);
livro* ler_livro();
char * tirar_enter(char *string);
void adicionar_livro(tabela_livros *tabela, livro *l);
int escrever_livro_arquivo(tabela_livros *tabela, livro * l);
int calcular_posicaoHashing(int isbn);
char* concatenar_informcaoesLivro( livro * l);
void adicionar_indice(int numero,int referencia,no_hash *tabela[]);
void remover_indice(no_hash *tabela[],int isbn);
livro * ler_livro_arquivo(tabela_livros *tabela,int isbn);
char * ler_campo(FILE * fp);
void salvar_arquivo(tabela_livros *tabela,char *nome_tabelaIndices);
void imprimir_livro(livro *l);
void imprimirTabela_livros(no_hash *tabela[]);
int procurar_indice(int isbn,no_hash *tabela[]);
void adicionarTabela_indice(tabela_livros *tabela);
void lerArquivo_indice(tabela_livros *tabela);
void editar_livro(tabela_livros *tabela);
void listarLivros(tabela_livros *tabela);

#endif
