#include <stdio.h>
#include <omp.h>

long factorial(int n) {
    if (n < 0) {
        return -1; 
    }
    long fac = 1;

    #pragma omp parallel for reduction(*:result)
    for (int i = 1; i <= n; i++) {
        fac *= i;
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
        printf("Factorial of %d = %ld\n", number, fac);
    }
    return 0;
}

