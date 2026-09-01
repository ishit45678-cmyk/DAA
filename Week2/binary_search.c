#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compareInts(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int n, int key, long *comparisons) {
    int low = 0, high = n - 1;
    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = 1000;
    int arr[1000];

    srand(42);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    qsort(arr, n, sizeof(int), compareInts);

    printf("Generated and sorted %d random numbers.\n", n);
    printf("First 10 elements after sorting: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int keysToFind[5];
    for (int i = 0; i < 5; i++) {
        keysToFind[i] = arr[(i * n) / 5];
    }
    int missingKey = -999;

    double totalTime = 0.0;
    long totalComparisons = 0;

    for (int i = 0; i < 5; i++) {
        long comparisons = 0;
        clock_t start = clock();
        int index = binarySearch(arr, n, keysToFind[i], &comparisons);
        clock_t end = clock();
        double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;

        printf("Search %d: key = %d, found at index = %d, comparisons = %ld, time = %.6f ms\n",
               i + 1, keysToFind[i], index, comparisons, timeTaken);

        totalTime += timeTaken;
        totalComparisons += comparisons;
    }

    long comparisons = 0;
    clock_t start = clock();
    int index = binarySearch(arr, n, missingKey, &comparisons);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;

    printf("Search 6 (missing key): key = %d, found at index = %d, comparisons = %ld, time = %.6f ms\n",
           missingKey, index, comparisons, timeTaken);

    totalTime += timeTaken;
    totalComparisons += comparisons;

    printf("\nAverage comparisons per search: %.2f\n", (double)totalComparisons / 6.0);
    printf("Average time per search: %.6f ms\n", totalTime / 6.0);

    int repeats = 100000;
    long dummyComparisons = 0;
    clock_t benchStart = clock();
    for (int r = 0; r < repeats; r++) {
        binarySearch(arr, n, missingKey, &dummyComparisons);
    }
    clock_t benchEnd = clock();
    double benchTime = ((double)(benchEnd - benchStart)) / CLOCKS_PER_SEC * 1000.0;
    printf("\nBenchmark: %d worst-case searches took %.3f ms total, %.6f ms per search\n",
           repeats, benchTime, benchTime / repeats);

    return 0;
}
