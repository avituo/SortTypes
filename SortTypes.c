#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define N 1000000

void merge(int array[], int start, int mid, int end) {
    int *temp, p1, p2, size, j, k;
    int end_o = 0, end_t = 0;

    size = end - start + 1;
    p1 = start;
    p2 = mid + 1;

    temp = (int *) malloc(size*sizeof(int));

    if(temp != NULL) {
        for(int i = 0; i < size; i++) {
            if(!end_o && !end_t) {
                if(array[p1] < array[p2])
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];

                if(p1 > mid)
                    end_o = 1;
                if(p2 > end)
                    end_t = 1;
                } else {
                    if(!end_o)
                        temp[i] = array[p1++];
                    else
                        temp[i] = array[p2++];
                }
        }
        for(j = 0, k = start; j < size; j++, k ++)
            array[k] = temp[j];
    }
    free(temp);
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
        while(left <= end && array[left] <= pivot)
            left++;
        while(right >= 0 && array[right] > pivot)
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
        array[i] = 1 + rand() % 2500;
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
    int smll, aux;

    for(int i = 0; i < N - 1; i++) {
        smll = i;
        for(int j = i + 1; j < N; j++) {
            if(array[smll] > array[j]) {
                smll = j;
            }
            if(i != smll) {
                aux = array[i];
                array[i] = array[smll];
                array[smll] = aux;
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

void shellSort(int array[]) {
    int aux, j;
    int gap = 1;

    while(gap < N/3)
        gap = 3 * gap + 1;

    while(gap > 0) {
        for(int i = gap; i < N; i++) {
            aux = array[i];
            j = i;

            while(j >= gap && aux < array[j - gap]) {
                array[j] = array[j - gap];
                j = j - gap;
            }
            array[j] = aux;
        }
        gap = (gap - 1)/3;
    }

}


int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    clock_t start, end;

    int keyNumber, menu;
    static int array[N];
    static int temp[N];

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
            tempArray(array, temp);
            bubbleSort(array);
            end = clock();
            printf("Tempo de execução(Bubble Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 3:
            tempArray(array, temp);
            start = clock();
            insertionSort(array);
            end = clock();
            printf("Tempo de execução(Insertion Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 4:
            start = clock();
            tempArray(array, temp);
            selectionSort(array);
            end = clock();
            printf("Tempo de execução(Selection Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 5:
            tempArray(array, temp);
            start = clock();
            heapSort(array);
            end = clock();
            printf("Tempo de execução(Heap Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 6:
            tempArray(array, temp);
            start = clock();
            quickSort(array, 0, N-1);
            end = clock();
            printf("Tempo de execução(Quick Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 7:
            tempArray(array, temp);
            start = clock();
            mergeSort(array, 0, N - 1);
            end = clock();
            printf("Tempo de execução(Merge Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 8:
            tempArray(array, temp);
            start = clock();
            shellSort(array);
            end = clock();
            printf("Tempo de execução(Shell Sort): %lf\n", ((double)(end - start)/CLOCKS_PER_SEC));
            break;

        case 9:
            printf("\nArray não ordenado: \n\n");
            printArray(temp);
            printf("\nArray ordenado: \n\n");
            printArray(array);
            break;

        default :
            break;
        }
    } while(menu);

    return 0;
}
