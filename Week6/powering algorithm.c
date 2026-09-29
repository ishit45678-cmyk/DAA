#include <stdio.h>

int power(int x, int n) {
    int result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result = result * x;
        }
        x = x * x;
        n = n / 2;
    }

    return result;
}

int main() {
    int base = 2;
    int exponent = 10;

    int result = power(base, exponent);

    printf("%d raised to power %d is %d\n", base, exponent, result);

    return 0;
}
