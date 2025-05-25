#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 1000;

    clock_t start = clock();
    mergeSort(arr, 0, N - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\nTime taken: %.5f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
