#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char *argv[]) {
	int arr1[]={9,8,7,6,5};
  int arr[]={2,3,4,5,6};
  int n=5,result[5];
#pragma omp parallel for 
for(int i=0;i<5;i++){
result[i]=arr1[i]-arr[i];
}
  for(int i=0;i<5;i++){
printf("result array is %d\t",arr[i]);
}
	return 0;
}
