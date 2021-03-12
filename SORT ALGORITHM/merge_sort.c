#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int inicio, int meio, int fim){
    int i = inicio;
    int j = meio + 1;

    int tamAux = fim - inicio;
    int *aux = malloc(sizeof(int)*tamAux);
    int k = 0;
    while(i <= meio || j <= fim){
        if(j > fim){
            printf("segundo subvetor sem elementos, adicionado o v[%d](%d) em aux[%d]\n", i, v[i], k);
            aux[k] = v[i];
            i++;
        } else if (i > meio){
            printf("primeiro subvetor sem elementos, adicionado o v[%d](%d) em aux[%d]\n", j, v[j], k);
            aux[k] = v[j];
            j++;
        } else if (v[i] < v[j]){
            printf("v[%d](%d) < v[%d](%d), adicionado o v[%d] em aux[%d]\n", i, v[i], j, v[j], i, k);
            aux[k] = v[i];
            i++;
        } else {
            printf("v[%d](%d) >= v[%d](%d), adicionado o v[%d] em aux[%d]\n", i, v[i], j, v[j], j, k);
            aux[k] = v[j];
            j++;
        }

        k++;
    }

	// transferindo os valores ordenados do vetor aux para o vetor principal v...
    for(int l = inicio; l <= fim; l++){
        v[l] = aux[l - inicio];
    }

    printf("-----------------------\n");
}

void merge_sort(int v[], int inicio, int fim){
    int meio = (fim + inicio)/2;

    if(inicio < fim){
        merge_sort(v, inicio, meio);
        merge_sort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
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
    int v[] = {15,7,6,4,2,1,8};
    print_vetor(v, 7);
    merge_sort(v, 0, 6);
    print_vetor(v, 7);
    return 0;
}
