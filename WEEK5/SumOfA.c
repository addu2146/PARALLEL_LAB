#include <stdio.h>
#include <omp.h>
#include <time.h>

void SumArrayParallel(int arr[], int n, int numt) {
    double stime, etime, ptime;
    int Sum = 0;
    stime = omp_get_wtime();
    #pragma omp parallel for reduction(+:Sum)
    for (int i = 0; i < n; i++) {
        Sum += arr[i];
    }
    etime = omp_get_wtime();
    ptime = (etime - stime) * 1000; // Convert to milliseconds
    printf("The Sum of all the elements is : %d\n", Sum);
    printf("Total time taken to execute the loop with %d threads: %f ms\n", numt, ptime);
}

int main() {
    double start;
    double end;
    double ptime;
    int n;

    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 3;
    }

    int choice;
    printf("Press 1 for parallel execution \nPress 2 for serial execution\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int numt;
        printf("Enter the number of threads you want to use\n");
        scanf("%d", &numt);
        omp_set_num_threads(numt);
        printf("Performing the sum with %d threads\n", numt);
       SumArrayParallel(arr, n, numt);
    } else {
        int Sum = 0;
        start = omp_get_wtime(); // Start timing here
        for (int i = 0; i < n; i++) {
            Sum += arr[i];
        }
        end = omp_get_wtime(); // End time here
        ptime = (double)(end - start)* 1000; //  milliseconds
        printf("The sum is: %d\n", Sum);
        printf("The total time taken with serial execution is %f ms\n", ptime);
    }

    return 0;
}
