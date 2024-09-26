#include<stdio.h>
#include<omp.h>
void fib(int n){
	int fib[n];
	int i;
	fib[0]=0;
	fib[1]=1;
	#pragma omp for
	for(i=2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(i =0;i<n;i++){
		printf("%d\t",fib[i]);
	}
	
}
	
int main(){
	int n;
	printf("enter how many fibonacci numbers you want to print\n");
	scanf("%d",&n);
	fib(n);
	return 0;	
}
