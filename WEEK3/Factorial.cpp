#include <stdio.h>

long factorial(int n) {
    if (n < 0) {
        return -1; 
    }
    long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    long result = factorial(number);
    if (result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d = %ld\n", number, result);
    }
    return 0;
}

