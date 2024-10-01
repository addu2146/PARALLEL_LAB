#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char *argv[]) {
  int arr[1000],sum=0;
  for(int i=0;i<1000;i++){
scanf("%d",&arr[i]);
}
#pragma omp parallel for reduction(+:sum) 
for(int i=0;i<1000;i++){
sum+=arr[i];
}
printf("The sum of array is %d",sum);
	return 0;
}
