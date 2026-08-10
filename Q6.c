//Write a C program to find all pairs of elements in an array whose sum is equal to a given target
//value  Each pair should be displayed only once
#include <stdio.h>

int main() {
    int n, target, i, j, k, l, count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("\nPairs with sum %d:\n", target);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                int isDuplicate = 0;

                for (k = 0; k <= i; k++) {
                    for (l = k + 1; l < n; l++) {
                        if (k == i && l >= j) {
                            break;
                        }
                        if (arr[k] + arr[l] == target) {
                            if ((arr[k] == arr[i] && arr[l] == arr[j]) || (arr[k] == arr[j] && arr[l] == arr[i])) {
                                isDuplicate = 1;
                                break;
                            }
                        }
                    }
                    if (isDuplicate) {
                        break;
                    }
                }

                if (!isDuplicate) {
                    printf("(%d, %d)\n", arr[i], arr[j]);
                    count++;
                }
            }
        }
    }

    if (count == 0) {
        printf("No pairs found.\n");
    }

    return 0;
}