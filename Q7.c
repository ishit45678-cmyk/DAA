//Write a C program to rotate an array to the right by K positions without using another array
#include <stdio.h>

int main() {
    int n, k, i, start, end, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate (K): ");
    scanf("%d", &k);

    k = k % n;
    if (k < 0) {
        k = k + n;
    }

    start = 0;
    end = n - 1;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    start = 0;
    end = k - 1;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    start = k;
    end = n - 1;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printf("\nRotated Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}