#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int size = 1000; 
    int array[size];
    int i;
    int j;

    // Seed the random number generator
    srand(time(0));
      
    #pragma omp parallel for
    
    for ( i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Random number between 0 and 999
    }

    
    #pragma omp parallel for
    for(i =0;i<size;i++){
    	printf("%d\t\t",array[i]);
	}
	int sum =0;
	#pragma omp parallel for reduction(+:sum)
	for(i=0;i<size;i++){
		sum+=array[i];
	}
	printf("\n Sum of the elements is %d", sum);
	return 0;
}
