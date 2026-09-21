#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a C program that accepts a positive integer containing digits from 0 to 9. Exactly one digit is missing, while the remaining nine digits appear exactly once.
void day1() {
    long long n;
    printf("Enter the number: ");
    scanf("%lld", &n);

    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("Missing digit: %d\n", 45 - sum);
}

// Write a program using a while loop that repeatedly asks the user to enter the password and stops only when the correct password is entered. Finally, display "Login successful!".
void day2() {
    char correct[] = "admin123";
    char input[50];

    printf("Enter password: ");
    scanf("%s", input);

    while (strcmp(input, correct) != 0) {
        printf("Wrong password, try again: ");
        scanf("%s", input);
    }
    printf("Login successful!\n");
}

// Given an array of daily temperatures, find the length of the longest consecutive strictly increasing streak.
void day3() {
    int temps[] = {10, 12, 15, 14, 16, 18, 20};
    int n = sizeof(temps) / sizeof(temps[0]);

    int longest = 1, current = 1;
    for (int i = 1; i < n; i++) {
        if (temps[i] > temps[i - 1])
            current++;
        else
            current = 1;

        if (current > longest)
            longest = current;
    }
    printf("Longest increasing streak: %d\n", longest);
}

// Given an integer array arr and a target value target, find the indices of two elements whose sum equals target. Assume exactly one valid pair exists, and the same element cannot be used twice.
void day4() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("[%d, %d]\n", i, j);
                return;
            }
        }
    }
    printf("No pair found\n");
}

// Input a number from the user and print a. Number of 1 and number of 0 in its binary representation. b. Number of consecutive 1 in the binary representation.
void day5() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    int ones = 0, zeros = 0;
    int maxRun = 0, run = 0;

    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (bit == 1) {
            ones++;
            run++;
            if (run > maxRun)
                maxRun = run;
        } else {
            zeros++;
            run = 0;
        }
    }

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Longest consecutive run of 1s: %d\n", maxRun);
}

// Write a generalised code for the following pattern (example is for n=4): A B C D / B C D E / C D E F / D E F G. Works for all values of n.
void day6() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char ch = 'A' + i;
        for (int j = 0; j < n; j++) {
            printf("%c ", ch + j);
        }
        printf("\n");
    }
}

// You are given a sorted array where every element appears exactly twice, except for one element which appears exactly once. Return the single element. O(log n) time, O(1) space.
int findSingle(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (mid % 2 == 1)
            mid--;

        if (arr[mid] == arr[mid + 1])
            low = mid + 2;
        else
            high = mid;
    }
    return arr[low];
}

void day7() {
    int arr1[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int arr2[] = {3, 3, 7, 7, 10, 11, 11};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Single element in arr1: %d\n", findSingle(arr1, n1));
    printf("Single element in arr2: %d\n", findSingle(arr2, n2));
}

// Given an m x n matrix, return all elements of the matrix in spiral order.
void day8() {
    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rows = 3, cols = 4;
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    printf("Spiral order: ");
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            printf("%d ", mat[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            printf("%d ", mat[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", mat[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }
    printf("\n");
}

// Rotate an array to the right by k steps.
void reverseArr(int arr[], int start, int end) {
    while (start < end) {
        int t = arr[start];
        arr[start] = arr[end];
        arr[end] = t;
        start++;
        end--;
    }
}

void day9() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    k = k % n;
    reverseArr(arr, 0, n - 1);
    reverseArr(arr, 0, k - 1);
    reverseArr(arr, k, n - 1);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Print a hollow square pattern of stars, border filled and inside empty (n=5 example: 5x5 box).
void day10() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Square every element of a sorted array and return the result sorted, without sorting again (two-pointer, O(n)).
void day11() {
    int arr[] = {-4, -1, 0, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[100];

    int left = 0, right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        int leftSq = arr[left] * arr[left];
        int rightSq = arr[right] * arr[right];

        if (leftSq > rightSq) {
            result[pos] = leftSq;
            left++;
        } else {
            result[pos] = rightSq;
            right--;
        }
        pos--;
    }

    printf("Squared and sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");
}

// Remove duplicate elements from a sorted array, in place, and return the new length.
void day12() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0) {
        printf("Array is empty\n");
        return;
    }

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    int newLen = j + 1;
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLen; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("New length: %d\n", newLen);
}

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
void day13() {
    int nums1[] = {1, 3, 8};
    int nums2[] = {7, 9, 10, 11};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);

    int merged[100];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] <= nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }
    while (i < m) merged[k++] = nums1[i++];
    while (j < n) merged[k++] = nums2[j++];

    int total = m + n;
    double median;
    if (total % 2 == 0)
        median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    else
        median = merged[total / 2];

    printf("Median: %.2f\n", median);
}

// Given two arrays arr1 and arr2, find the smallest difference between two array elements (one from each array).
void day14() {
    int arr1[] = {1, 3, 15, 11, 2};
    int arr2[] = {23, 127, 235, 19, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < n1; i++) {
        for (int j = i + 1; j < n1; j++) {
            if (arr1[i] > arr1[j]) {
                int t = arr1[i]; arr1[i] = arr1[j]; arr1[j] = t;
            }
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = i + 1; j < n2; j++) {
            if (arr2[i] > arr2[j]) {
                int t = arr2[i]; arr2[i] = arr2[j]; arr2[j] = t;
            }
        }
    }

    int i = 0, j = 0;
    int minDiff = abs(arr1[0] - arr2[0]);
    while (i < n1 && j < n2) {
        int diff = abs(arr1[i] - arr2[j]);
        if (diff < minDiff)
            minDiff = diff;

        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    printf("Smallest difference: %d\n", minDiff);
}

// Write a program to detect a cycle in a linked list. Do the complexity analysis also.
struct Node {
    int data;
    struct Node *next;
};

void day15() {
    // building a small list manually and forcing a cycle for testing
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    struct Node *fourth = malloc(sizeof(struct Node));

    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = second; // cycle back to second

    struct Node *slow = head, *fast = head;
    int cycleFound = 0;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycleFound = 1;
            break;
        }
    }

    if (cycleFound)
        printf("Cycle detected in the linked list\n");
    else
        printf("No cycle in the linked list\n");

    // Complexity: Floyd's cycle detection uses two pointers, slow and fast.
    // Time complexity is O(n) because fast catches up to slow within n steps if a cycle exists.
    // Space complexity is O(1) since no extra data structure is used, just two pointers.
}

int main() {
    int choice;
    printf("Enter day number to run: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: day1(); break;
        case 2: day2(); break;
        case 3: day3(); break;
        case 4: day4(); break;
        case 5: day5(); break;
        case 6: day6(); break;
        case 7: day7(); break;
        case 8: day8(); break;
        case 9: day9(); break;
        case 10: day10(); break;
        case 11: day11(); break;
        case 12: day12(); break;
        case 13: day13(); break;
        case 14: day14(); break;
        case 15: day15(); break;
        default: printf("That day isn't in here.\n");
    }

    return 0;
}
