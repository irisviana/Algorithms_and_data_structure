#include <stdio.h>
#include <stdlib.h>

void heap_sort(int v[], int tamanho){
    int pai = 0;
    while(tamanho > 0){
        int filho = 2*pai + 1;

        if(filho + 1 < tamanho && v[filho+1] > v[filho]){
            filho = filho + 1;
        }

        if(filho < tamanho && v[filho] > v[pai]){
            printf("filho v[%d](%d) > pai v[%d](%d)\n", filho, v[filho], pai, v[pai]);
            int aux = v[filho];
            v[filho] = v[pai];
            v[pai] = aux;

            pai = (pai - 1)/2;
        } else {
            if(tamanho > 0){
                if(pai == tamanho - 1){
                    printf("trocando raiz v[0](%d) por v[%d](%d)\n", v[0], pai, v[pai]);
                    int aux = v[0];
                    v[0] = v[pai];
                    v[pai] = aux;

                    pai = 0;
                    tamanho = tamanho - 1;
                } else {
                    pai++;
                }
            }
        }
        printf("-----------------\n");
    }
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
    heap_sort(v, 6);
    print_vetor(v, 6);
    return 0;
}


