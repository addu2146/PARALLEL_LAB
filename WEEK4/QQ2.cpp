#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char *argv[]) {
int fact=1,num;
#pragma omp parallel num_threads(10)
{
num=omp_get_thread_num();
	fact*=(num+1);
}
printf("Factorial of 10 is %d",fact);
}
