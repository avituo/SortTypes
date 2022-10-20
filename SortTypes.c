#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define N 90000

void merge(int array[], int start, int mid, int end) {
    int *temp, p1, p2, i, j, k;
    int end_o = 0, end_t = 0;


}

void tempArray(int array[], int temp[]) {
    for(int i = 0; i < N; i++) {
        array[i] = temp[i];
    }
}

int partition(int array[], int start, int end) {
    int left, right, pivot, aux;

    left = start;
    right = end;
    pivot = array[start];

    while(left < right) {
        while(array[left] <= pivot)
            left++;
        while(array[right] > pivot)
            right--;

        if(left < right) {
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }
    array[start] = array[right];
    array[right] = pivot;
    return right;
}

void createHeap(int array[], int i, int f) {
    int aux = array[i];
    int j = i * 2 + 1;

    while(j <= f) {
        if(j < f) {
            if(array[j] < array[j + 1]) {
                j = j + 1;
            }
        }

        if(aux < array[j]) {
            array[i] = array[j];
            i = j;
            j = 2 * i + 1;
        }else {
            j = f + 1;
        }
    }

    array[i] = aux;
}

void fillArray(int array []) {
    for(int i = 0; i < N; i++) {
        array[i] = 1 + rand() % 300;
    }
}

void printArray(int array []) {
    int aux = N - 101;

    printf("Cem primeiros números: \n\n");

    for(int i = 0; i < 100; i++) {
        printf("INDEX[%d]: %d\n", i, array[i]);
    }

    printf("\nCem últimos números: \n\n");

    for(int i = aux; i < N; i++) {
        printf("INDEX[%d]: %d\n", i, array[i]);
    }
}

void bubbleSort(int array[]) {
    int aux;

     for(int i = 0; i < N - 1; i++)
          for(int j = i + 1; j < N; j++)
               if(array[i] > array[j]) {
                   aux = array[j];
                   array[j] = array[i];
                   array[i] = aux;
               }
}

void insertionSort(int array[]) {
    int aux, j, i;

    for(i = 1; i < N; i++) {
        aux = array[i];
        for(j = i; (j > 0) && (aux < array[j - 1]); j--)
            array[j] = array[j - 1];
        array[j] = aux;
    }
}

void selectionSort(int array[]) {
    int low, aux;

    for(int i = 0; i < N - 1; i++) {
        low = i;
        for(int j = i + 1; j < N; j++) {
            if(array[low] > array[j]) {
                low = j;
            }
            if(i != low) {
                aux = array[i];
                array[i] = array[low];
                array[low] = aux;
            }
        }
    }
}

void heapSort(int array[]) {
    int aux;

    for(int i = (N - 1)/2; i >= 0; i--) {
        createHeap(array, i, N - 1);
    }

    for (int i = N - 1; i >= 1; i--){
        aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        createHeap(array, 0, i - 1);
    }
}

void quickSort(int array[], int start, int end) {
    int pivot;

    if(end > start) {
        pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }

}

void mergeSort(int array[], int start, int end) {
    int mid;

    if(start < end) {
        mid = floor((start+end)/2);
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void shellSort() {
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    clock_t start, end;

    int array[N], keyNumber, menu, temp[N];
    bool found;

    do{
        printf("\n(1) Preencher o array com números aleatórios\n(2) Ordenar o array pelo método Bubble Sort\n(3) Ordenar o array pelo método Insertion Sort\n(4) Ordenar o array pelo método Selection Sort\n(5) Ordenar o array pelo método Heap Sort\n(6) Ordenar o array pelo método Quick Sort\n(7) Ordenar o array pelo método Merge Sort\n(8) Ordenar o array pelo método Shell Sort\n(9) Imprimir o array\n\nOpção: ");
        scanf("%d", &menu);
        system("cls || clear");

        switch (menu) {
        case 1:
            fillArray(array);
            for (int i = 0; i < N; i++) {
                temp[i] = array[i];
            }
            break;

        case 2:
            start = clock();
            bubbleSort(array);
            end = clock();
            break;

        case 3:
            tempArray(array, temp);
            start = clock();
            insertionSort(array);
            end = clock();
            printf("Tempo de execução: %lf", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 4:
            tempArray(array, temp);
            start = clock();
            selectionSort(array);
            end = clock();
            break;

        case 5:
            tempArray(array, temp);
            start = clock();
            heapSort(array);
            end = clock();
            break;

        case 6:
            tempArray(array, temp);
            start = clock();
            quickSort(array, 0, N-1);
            end = clock();
            tempArray(array, temp);
            break;

        case 7:
            tempArray(array, temp);
            start = clock();
            mergeSort(array, 0, N - 1);
            end = clock();
            break;

        case 8:
            tempArray(array, temp);
            start = clock();
            shellSort();
            end = clock();
            break;

        case 9:
            printArray(array);
            printArray(temp);
            break;

        case 10:
            printf("%lf", ((double)(end - start)/CLOCKS_PER_SEC));

        default :
            break;
        }
    } while(menu);

    return 0;
}
