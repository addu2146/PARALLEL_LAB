#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char *argv[]) {
  int arr[]={2,3,4,5,6};
#pragma omp parallel for 
for(int i=0;i<5;i++){
int temp=arr[i];
arr[i]=temp*temp;
}
  for(int i=0;i<5;i++){
printf("After squaring array is %d\t",arr[i]);
}
	return 0;
}
