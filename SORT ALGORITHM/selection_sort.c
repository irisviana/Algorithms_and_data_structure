#include <stdio.h>
#include <stdlib.h>

void selection_sort(int v[], int tamanho){
    int iteracoes = 0;
    for(int i = 0; i < tamanho; i++){
        int min = v[i];
        int indice_min = i;

        printf("i=%d,v[i]=%d\n", i, v[i]);
        for(int j = i; j < tamanho; j++){
            if(v[j] < min){
                printf("j=%d, v[j]=%d menor que %d - TROCAR!\n", j, v[j], min);
                min = v[j];
                indice_min = j;
            }
            iteracoes++;
        }

        int aux = v[i];
        v[i] = min;
        v[indice_min] = aux;
        printf("---------------\n");
    }

    printf("iteracoes no total: %d\n", iteracoes);
}

void print_vetor(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int v[] = {3,2,5,1,7,4}; // nao ordenado;
    //int v[] = {5,5,4,3,2,1}; // numero repetido
    //int v[] = {7,5,4,3,2,1}; // ordem inversa
    //int v[] = {1,2,3,4,5,7}; // ja ordenado
    print_vetor(v, 6);
    selection_sort(v, 6);
    print_vetor(v, 6);
    return 0;
}
