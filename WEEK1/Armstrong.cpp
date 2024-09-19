#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include<omp.h>

// Function to check if a number is an Armstrong number
bool IfArmstrong(int num) {
    int temp = num;
    int count = 0;

    // Count the number of digits
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    temp = num; // Reset temp to original number
    int rem = 0; 

    // Calculate the sum of the powers of the digits
    while (temp != 0) {
        rem += (int)pow(temp % 10, count);
        temp /= 10;
    }

    // Check if the original number is equal to the calculated sum
    return num == rem;
}

int main() {
    int num[]= {1,2,3,4,5,6,7,8,9,370,153,371,1634,354,291,56,78,90,20,22};
    int i;
    #pragma omp for
    for(i=0;i<20;i++){
	   if (IfArmstrong(num[i])) {
        printf("%d is an Armstrong number.\n", num[i]);
    }   else {
        printf("%d is not an Armstrong number.\n", num[i]);
    }
}

    return 0;
}

