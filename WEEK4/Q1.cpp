//#include <stdio.h>
//#include <stdlib.h>
//#include <omp.h>
//int main(int argc, char *argv[]) {
//  int n,a=0,b=1,c,i;
//  printf("Enter the number\n");
//  scanf("%d",&n);
//    if (n >= 1) printf("%d\t", a);
//    if (n >= 2) printf("%d\t", b);
//#pragma omp parallel for private(i,a,b,c)
//for(i=2;i<n;i++){
//          c=a+b;
//            printf("%d\t", c);
//         a=b;
//         b=c;
//}
//	return 0;
//}
//or
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char *argv[]) {
  int n,a=0,b=1,c;
  printf("Enter the number\n");
  scanf("%d",&n);
    if (n >= 1) printf("%d\t", a);
    if (n >= 2) printf("%d\t", b);
#pragma omp parallel for 
for(int i=2;i<n;i++){
   #pragma omp critical
        {
          c=a+b;
            printf("%d\t", c);
        }
         a=b;
         b=c;
}
	return 0;
}
