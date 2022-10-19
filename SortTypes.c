#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

#define N 300

int particiona(int array[], int inicio, int fim) {
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = array[inicio];

    while(esq < dir) {
        while(array[esq] <= pivo)
            esq++;
        while(array[dir] > pivo)
            dir--;

        if(esq < dir) {
            aux = array[esq];
            array[esq] = array[dir];
            array[dir] = aux;
        }
    }
    array[inicio] = array[dir];
    array[dir] = pivo;
    return dir;
}

void createHeap(int array[], int i, int f) {
    int aux = array[i];
    int j = i * 2 + 1;

    while (j <= f) {
        if (j < f) {
            if (array[j] < array[j + 1]) {
                j = j + 1;
            }
        }

        if (aux < array[j]) {
            array[i] = array[j];
            i = j;
            j = 2 * i + 1;
        } else {
            j = f + 1;
        }
    }

    array[i] = aux;
}

void fillArray(int array []) {
    for (int i = 0; i < N; i++) {
        array[i] = 1 + rand() % 300;
    }
}

void printArray(int array []) {
    int aux = N - 101;

    printf("Cem primeiros números: \n\n");

    for (int i = 0; i < 100; i++) {
        printf("INDEX[%d]: %d\n", i, array[i]);
    }

    printf("\nCem últimos números: \n\n");

    for (int i = aux; i < N; i++) {
        printf("INDEX[%d]: %d\n", i, array[i]);
    }
}

void bubbleSort(int array[]) {
    int aux;

     for (int i = 0; i < N - 1; i++)
          for (int j = i + 1; j < N; j++)
               if (array[i] > array[j]) {
                   aux = array[j];
                   array[j] = array[i];
                   array[i] = aux;
               }
}

void insertionSort(int array[]) {
    int aux, j, i;

    for (i = 1; i < N; i++) {
        aux = array[i];
        for (j = i; (j > 0) && (aux < array[j - 1]); j--)
            array[j] = array[j - 1];
        array[j] = aux;
    }
}

void selectionSort(int array[]) {
    int low, aux;

    for (int i = 0; i < N - 1; i++) {
        low = i;
        for (int j = i + 1; j < N; j++) {
            if (array[low] > array[j]) {
                low = j;
            }
            if (i != low) {
                aux = array[i];
                array[i] = array[low];
                array[low] = aux;
            }
        }
    }
}

void heapSort(int array[]) {
    int aux;

    for (int i = (N - 1)/2; i >= 0; i--) {
        createHeap(array, i, N - 1);
    }

    for (int i = N - 1; i >= 1; i--){
        aux = array[0];
        array[0] = array[i];
        array[i] = aux;
        createHeap(array, 0, i - 1);
    }
}

void quickSort(int array[], int inicio, int fim) {
    int pivo;

    if (fim > inicio) {
        pivo = particiona(array, inicio, fim);
        quickSort(array, inicio, pivo-1);
        quickSort(array, pivo+1, fim);
    }

}

void mergeSort() {
}

void shellSort() {
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int array[N], keyNumber, menu;
    bool found;

    do {
        printf("\n(1) Preencher o array com números aleatórios\n(2) Ordenar o array pelo método Bubble Sort\n(3) Ordenar o array pelo método Insertion Sort\n(4) Ordenar o array pelo método Selection Sort\n(5) Ordenar o array pelo método Heap Sort\n(6) Ordenar o array pelo método Quick Sort\n(7) Ordenar o array pelo método Merge Sort\n(8) Ordenar o array pelo método Shell Sort\n(9) Imprimir o array\n\nOpção: ");
        scanf("%d", &menu);
        system("cls || clear");

        switch (menu) {
        case 1:
            fillArray(array);
            break;

        case 2:
            bubbleSort(array);
            break;

        case 3:
            insertionSort(array);
            break;

        case 4:
            selectionSort(array);
            break;

        case 5:
            heapSort(array);
            break;

        case 6:
            quickSort(array, 0, N-1);
            break;

        case 7:
            mergeSort();
            break;

        case 8:
            shellSort();
            break;

        case 9:
            printArray(array);
            break;

        default :
            break;
        }
    } while(menu);

    return 0;
}
