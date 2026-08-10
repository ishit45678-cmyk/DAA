//Write a C program to find the second-largest distinct element in an array without sorting it.
#include <stdio.h>

int main() {
    int n, i, first, second, temp = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There is no second-largest distinct element.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    first = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > first) {
            first = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < first) {
            if (temp == 0 || arr[i] > second) {
                second = arr[i];
                temp = 1;
            }
        }
    }

    if (temp) {
        printf("The second-largest distinct element is %d\n", second);
    } else {
        printf("There is no second-largest distinct element.\n");
    }

    return 0;
}