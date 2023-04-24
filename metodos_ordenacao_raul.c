/**
 * @file metodos_ordenacao_raul.c
 * @author Raul Bonfante Magri
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 *
 * @brief Arquivo template para trabalho de Pesquisa e Ordenação.
 *
 *      Cada estudante deve implementar as funções conforme as assinaturas
 * abaixo e realizar as impressões dos vetores após a ordenação. Desta forma,
 * o(a) estudante deve implementar o trecho de código para impressão dos vetores
 * ordenados dentro da função `main` conforme o exemplo do Bubble Sort abaixo.
 *
 * Se necessário, declare e implemente funções auxiliares para realizar as
 * ordenações.
 *
 * Importante:Não altere as assinaturas dos métodos de ordenação!
 *
 * Caso o vetor não possa ser ordenado por algum método, imprima uma mensagem de
 * aviso e o vetor original.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>

void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
void quickSort(int *A, int size);
void heapSort(int *A, int size);
void countingSort(int *A, int size);
void radixSort(int *A, int size);


int main(){

    int i;
    int vetor[] = {1, 22, -10, 38, 5, 7}; //vetor padrão
    //int vetor[] = {9, 0, -15, 60, 99, 3, -3, 1, 42, 17, 21, 2}; //vetor grandao
    //int vetor[] = {0, 13, 5, 8, 69, 1}; //vetor sem negativo
    //int vetor[] = {0, 13, 5, 8, 69, 1, 73, 12, 3, 6, 34, 29, 3}; //vetor sem negativo e grandao
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
    int heapVec[tamanhoVetor];
    copia(vetor, heapVec, tamanhoVetor);
    heapSort(heapVec, tamanhoVetor);
    printf("\nHeap sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", heapVec[i]);
    printf("\n");

    // counting sort
    int countingVec[tamanhoVetor];
    copia(vetor, countingVec, tamanhoVetor);
    countingSort(countingVec, tamanhoVetor);
    printf("\nCounting sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", countingVec[i]);
    printf("\n");

    // radix sort
    int radixVec[tamanhoVetor];
    copia(vetor, radixVec, tamanhoVetor);
    radixSort(radixVec, tamanhoVetor);
    printf("\nRadix sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", radixVec[i]);
    printf("\n");
    return 0;
}

void copia(int *A, int *V, int size){
    int i;
    for (i = 0 ; i < size ; i++)
        V[i] = A[i];
}

int buscaMaior(int *A, int size){
    int maior = A[0];
    int i;
    
    for(i = 1 ; i < size ; i++){
        if(A[i] > maior){
            maior = A[i];
        }
    }
    
    return maior;
}

int testaNegativo(int *A, int size){
    int negativo = 0;
    int i;
    
    for(i = 0 ; i < size ; i++){
        if(A[i] < 0){
            negativo = 1;
        }
    }
    
    return negativo;
}

//--------------bubbleSort--------------//

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

//--------------selectionSort--------------//

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

//--------------insertionSort--------------//

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

//--------------mergeSort--------------//

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
        aux[k] = A[j];
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
        meio = (inicio+fim)/2;
        
        mergeRecursive(A, inicio, meio);
        mergeRecursive(A, meio+1, fim);
        intercala(A, inicio, meio, fim);
    }
}

void mergeSort(int *A, int size){
    mergeRecursive(A, 0, size-1);
}

//--------------quickSort--------------//

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
        posPivo = k;
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
    quickRecursive(A, 0, size-1);
}

//--------------heapSort--------------//

void criaheap(int *A, int i, int size){
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;
    
    if(esquerda < size && A[esquerda] > A[maior]){
        maior = esquerda;
    }
    
    if(direita < size && A[direita] > A[maior]){
        maior = direita;
    }
    
    if(maior != i){
        //troca
        int aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        criaheap(A, maior, size);
    }
}

void heapSort(int *A, int size){
    int k;
    
    for(k = size/2-1 ; k >= 0 ; k--){
        criaheap(A, k, size);
    }
    
    for(k = size-1 ; k >= 1 ; k--){
        //troca
        int aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        criaheap(A, 0, k);
    }
}

//--------------countingSort--------------//

void countingSort(int *A, int size){
    int n = testaNegativo(A, size);
    if(n == 1){
        printf("\nO vetor é impossivel de ser ordenado por Counting Sort, possui numeros negativos.");
        return;
    }
    
    int k = buscaMaior(A, size);
    int count[k+1], aux[size];
    int i;
    
    for(i = 0 ; i <= k ; i++){
        count[i] = 0;
    }
    
    for(i = 0 ; i < size ; i++){
        count[A[i]]++;
    }
    
    for(i = 1 ; i <= k ; i++){
        count[i] += count[i-1];
    }
    
    for(i = size-1 ; i >= 0 ; i--){
        count[A[i]]--;
        aux[count[A[i]]] = A[i];
    }
    
    for(i = 0 ; i < size ; i++){
        A[i] = aux[i];
    }
}

//--------------radixSort--------------//

void counting(int *A, int size, int pos){
    int aux[size];
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, digito;
    
    for(i = 0 ; i < size ; i++){
        digito = (A[i]/pos)%10;
        count[digito]++;
    }
    
    for(i = 1 ; i < 10 ; i++){
        count[i] = count[i] + count[i-1];
    }
    
    for(i = size-1 ; i >= 0 ; i--){
        digito = (A[i]/pos)%10;
        count[digito]--;
        aux[count[digito]] = A[i];
    }
    
    for(i = 0 ; i < size ; i++){
        A[i] = aux[i];
    }
}

void radixSort(int *A, int size){
    int n = testaNegativo(A, size);
    if(n == 1){
        printf("\nO vetor é impossivel de ser ordenado por Radix Sort, possui numeros negativos.");
        return;
    }
    
    int max = buscaMaior(A, size);
    int pos;
    
    for(pos = 1 ; max/pos > 0 ; pos*=10){
        counting(A, size, pos);
    }
}
