/**
 * @file metodos_ordenacao_raul.c
 * @author Raul Bonfante Magri
 * @version 0.3
 * @date 2023-03-30
 *
 * @copyright Copyright (c) 2023
 *
 *
 * @brief Arquivo template para trabalho de Pesquisa e Ordena��o.
 *
 *      Cada estudante deve implementar as fun��es conforme as assinaturas
 * abaixo e realizar as impress�es dos vetores ap�s a ordena��o. Desta forma,
 * o(a) estudante deve implementar o trecho de c�digo para impress�o dos vetores
 * ordenados dentro da fun��o `main` conforme o exemplo do Bubble Sort abaixo.
 *
 * Se necess�rio, declare e implemente fun��es auxiliares para realizar as
 * ordena��es.
 *
 * Importante:N�o altere as assinaturas dos m�todos de ordena��o!
 *
 * Caso o vetor n�o possa ser ordenado por algum m�todo, imprima uma mensagem de
 * aviso e o vetor original.
 *
 * Aten��o: Antes de entregar, conferir se dos dados de documenta��o no in�cio
 * do arquivo est�o preenchidos corretamente.
 *
 */
#include <stdio.h>

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
void quickSort(int *A, int size);
// void heapSort(int *A, int size);
// void countingSort(int *A, int size);
// void radixSort(int *A, int size);


int main(){

    int i;
    int vetor[] = {1, 22, -10, 38, 5, 7};
    int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);

    printf("\nVetor original: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", vetor[i]);

    printf("\nVetor tamanho = %d\n", tamanhoVetor);

    // bubble sort
    int bubbleVec[tamanhoVetor];
    copia(vetor, bubbleVec, tamanhoVetor);
    bubbleSort(bubbleVec, tamanhoVetor);
    printf("\nBubble sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", bubbleVec[i]);
    printf("\n");

    // selection sort
    int selectionVec[tamanhoVetor];
    copia(vetor, selectionVec, tamanhoVetor);
    selectionSort(selectionVec, tamanhoVetor);
    printf("\nSelection sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", selectionVec[i]);
    printf("\n");

    // insertion sort
    int insertionVec[tamanhoVetor];
    copia(vetor, insertionVec, tamanhoVetor);
    insertionSort(insertionVec, tamanhoVetor);
    printf("\nInsertion sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", insertionVec[i]);
    printf("\n");

    // merge sort
    int mergeVec[tamanhoVetor];
    copia(vetor, mergeVec, tamanhoVetor);
    mergeSort(mergeVec, tamanhoVetor);
    printf("\nMerge sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", mergeVec[i]);
    printf("\n");
    
    // quick sort
    int quickVec[tamanhoVetor];
    copia(vetor, quickVec, tamanhoVetor);
    quickSort(quickVec, tamanhoVetor);
    printf("\nQuick sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", quickVec[i]);
    printf("\n");

    // heap sort

    // counting sort

    // radix sort

    return 0;
}

void copia(int *A, int *V, int size){
    int i;
    for (i = 0 ; i < size ; i++)
        V[i] = A[i];
}

void bubbleSort(int *A, int size){
    int flag; 
	int i, j;
    for(i = size-1 ; i > 0 ; i--){
        flag = 0;
        for(j = 0 ; j < i ; j++){
            if(A[j] > A[j+1]){
                flag = 1;
                //troca
                int aux = A[j+1];
                A[j+1] = A[j];
                A[j] = aux;
            }
        }
       if(flag == 0){
           return;
        }
    }
}

void selectionSort(int *A, int size){
    int menor = 0;
	int i, j;
    for(i = 0 ; i < size-1 ; i++){
        menor = i;
        for(j = i+1 ; j < size ; j++){
            if(A[menor] > A[j]){
                menor = j;
            }
        }
        //troca
        int aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }
}

void insertionSort(int *A, int size){
    int i, j;
    for(i = 1 ; i < size ; i++){
        int p = A[i];
        for(j = i ; j > 0 && p < A[j-1]; j--){
            A[j] = A[j-1];
        }
        A[j] = p;
    }
}

void intercala(int *A, int inicio, int meio, int fim){
    int aux[fim-inicio+1];
    int i = inicio;
    int j = meio+1;
    int k = 0;
    
    while(i <= meio && j <= fim){
        if(A[i] <= A[j]){
            aux[k] = A[i];
            i++;
        }else{
            aux[k] = A[j];
            j++;
        }
        k++;
    }
    
    while(i <= meio){
        aux[k] = A[i];
        k++;
        i++;
    }
    
    while(j <= fim){
        aux[k] = A[i];
        k++;
        j++;
    }
    
    for(k = inicio ; k <= fim ; k++){
        A[k] = aux[k-inicio];
    }
}

void mergeRecursive(int *A, int inicio, int fim){
    int meio;
    
    if(inicio < fim){
        meio = (inicio+fim)%2;
        
        mergeRecursive(A, inicio, meio);
        mergeRecursive(A, meio+1, fim);
        intercala(A, inicio, meio, fim);
    }
}

void mergeSort(int *A, int size){
    mergeRecursive(A, 0, size);
}

int particiona(int *A, int inicio, int fim){
    int posPivo = fim;
    int k = inicio;
    int i;
    
    for(i = inicio ; i < fim ; i++){
        if(A[i] <= A[posPivo]){
                //troca
                int aux = A[i];
                A[i] = A[k];
                A[k] = aux;
                k++;
        }
    }
    if(A[k] > A[posPivo]){
        //troca
        int aux = A[k];
        A[k] = A[posPivo];
        A[posPivo] = aux;
    }
    return posPivo;
}

void quickRecursive(int *A, int inicio, int fim){
    int posPivo;
    if(inicio < fim){
        posPivo = particiona(A, inicio, fim);
        quickRecursive(A, inicio, posPivo-1);
        quickRecursive(A, posPivo+1, fim);
    }
}

void quickSort(int *A, int size){
    quickRecursive(A, 0, size);
}
