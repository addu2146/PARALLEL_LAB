#include<stdio.h>
#include<conio.h>
#include<math.h>
//Leibniz Formula
//p/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
//Or, p = 4 ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - ... )

int main()
{
 long long i, n;
 double sum=0.0, term, pi;
 
 printf("Enter number of terms: ");
 scanf("%ld", &n);

//  Applying Leibniz Formula 
 for(i=0;i< n;i++)
 {
  term = pow(-1, i) / (2*i+1);
  sum += term;
 }
 pi = 4 * sum;

 printf("\nPI = %.10lf", pi);
 
 return 0;
}
