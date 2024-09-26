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
	
    int max = array[0];
    #pragma omp parallel for
    for( i =1; i<size ; i++){
    		if(array[i]>max){
    			
    			max = array[i];
			}

	}
	printf("\nThe maximum element is : %d", max);
    return 0;
    
    }


