// check whether the given number is the Perfect number using openmp
// perfect numbers 6,28,8128,33550336...
//Sum of the factors = number itself.
#include<omp.h>  
#include<stdio.h>    
int main()  
{  
int num, rem, sum = 0, i;   
printf("Enter a number\n");  
scanf("%d", &num);
#pragma omp parallel for reduction(+:sum)      
for(i = 1; i < num; i++)  
                     {  
    rem = num % i;  
    if (rem == 0)  

   {  
    sum = sum + i;  
   }  
                     }  
if (sum == num)  
    printf(" %d is a Perfect Number",num);  
else  
    printf("\n %d is not a Perfect Number",num);
    return 0;
}
