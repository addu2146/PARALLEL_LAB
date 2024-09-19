#include<stdio.h>
#include<omp.h>
int main(){
	int i;
	int Integers[20];
	for(i=0;i<20;i++){
		Integers[i]=i+1;
	}
	omp_set_num_threads(20);
	#pragma omp parallel for 
	for(i=0; i<20; i++){
		if(Integers[i]%2==0){
			printf("%d is even \t",Integers[i]);
		}
		else
		printf("%d is odd  \t",Integers[i]);
	}
	return 0;
}


