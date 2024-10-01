#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[]) {
    #pragma omp parallel for ordered
    for(int i = 1; i < 11; i++) {
    	#pragma omp ordered
    	{
	
            printf("%d\n", i);
}
	}
    return 0;
}
//#pragma omp for 
