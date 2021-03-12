#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("i=%d, v[i]=%d\n", i, v[i]);

        int valor = v[i];
        int j = i - 1;

        while(j >= 0 && valor < v[j]){
            printf("passa adiante %d, pois eh menor que %d\n", valor, v[j]);
            v[j+1] = v[j];

            j--;
        }

        v[j+1] = valor;

        printf("coloca %d em v[%d]\n------------------\n", valor, j+1);

        print_vetor(v, tamanho);
    }
}

void print_vetor(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");
}

int main()
{
    int v[] = {15,7,6,4,2,1};
    print_vetor(v, 6);
    insertion_sort(v, 6);
    print_vetor(v, 6);
    return 0;
}
