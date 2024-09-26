#include<stdio.h>
#include<omp.h>
void fact(int n){
	if (n<0){
		printf("Negative number doesnt have a factorial");
	}
	else{
		int i;
		int fact =1;
		if(n==0){
			printf("The factorial of 0 is : 1");
		}
		else{

		#pragma omp parallel for reduction(*:fact)
		for(i=1;i<=n;i++){
			fact = fact*i;
		}
	}
	      printf("The factorial of %d is : %d",n,fact);
 }
}
int main(){
	int n = 10;
	fact(n);
}
