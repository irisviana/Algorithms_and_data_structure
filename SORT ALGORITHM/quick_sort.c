#include <stdio.h>
#include <stdlib.h>

void quick_sort(int v[], int inicio, int fim){
    int indice_pivo = inicio;
    int pivo = v[indice_pivo];

    int i = inicio;
    int j = fim;

    while(i <= j){
        while(v[i] < pivo){
            printf("v[%d](%d) < %d - vida que segue...\n", i, v[i], pivo);
            i++;
        }

        while(v[j] > pivo){
            printf("v[%d](%d) > %d - vida que segue...\n", j, v[j], pivo);
            j--;
        }

        if(i <= j){
            printf("v[%d] > pivo e v[%d] < pivo - trocar eles de posicao...\n", i, j);
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;

            i++;
            j--;
        }
    }

    printf("--------------------\n");

    if(j > inicio){
        quick_sort(v, inicio, j);
    }

    if(i < fim){
        quick_sort(v, i, fim);
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
    int v[] = {6,4,15,2,1,7};
    print_vetor(v, 6);
    quick_sort(v, 0, 5);
    print_vetor(v, 6);
    return 0;
}
