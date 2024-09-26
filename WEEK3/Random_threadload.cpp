#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 4

int main() {
    omp_set_num_threads(NUM_THREADS);
    srand(time(NULL));

    // Generate a random number of turns between 10 and 50
    int Turns = rand() % 41 + 10; // (rand() % (max - min + 1)) + min

    #pragma omp parallel
    {
        for (int i = 0; i < Turns; i++) {
            int tid = rand() % NUM_THREADS; // Random thread ID
            if (omp_get_thread_num() == tid) {
                printf("Hello World from thread : %d!\n", tid);
            }
        }
    }

    return 0;
}

