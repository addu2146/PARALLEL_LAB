#include <stdio.h>
#include <omp.h>

int main() {
    int numt = 30;

    #pragma omp parallel num_threads(numt)
    {
        int tid = omp_get_thread_num();
        printf("Hello world from thread: %d\n", tid);
    }

    return 0;
}

