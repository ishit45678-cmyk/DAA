//Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.
#include <stdio.h>

int main() {
    char str[200];
    int left = 0, right = 0, isPalindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[right] != '\0') {
        right++;
    }
    right--;

    while (left < right) {
        while (left < right && (str[left] == ' ' || str[left] == '\n' || str[left] == '\t')) {
            left++;
        }

        while (left < right && (str[right] == ' ' || str[right] == '\n' || str[right] == '\t')) {
            right--;
        }

        if (left >= right) {
            break;
        }

        char c1 = str[left];
        char c2 = str[right];

        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 + 32;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 + 32;
        }

        if (c1 != c2) {
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}