#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    // Size of the array
    int n = 100000; // Change this value as needed
    int *array = malloc(n * sizeof(int)); // Dynamically allocate the array

    // Check if memory allocation was successful
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array with consecutive values (1 to n)
    for (int i = 0; i < n; i++) {
        array[i] = i + 1; // Fill with consecutive values (1 to n)
    }

    // Set the number of threads to use
    int num_threads = 4; // Change this value as needed
    int start_index=0;
    // Parallel region starts here
    #pragma omp parallel num_threads(num_threads) firstprivate(start_index)
    {
        // Firstprivate variables to avoid data races
        int thread_id = omp_get_thread_num(); // Get the thread ID
        int chunk_size = n / num_threads; // Determine how many elements each thread processes
        start_index = thread_id * chunk_size; // Starting index for each thread
        int end_index = (thread_id == num_threads - 1) ? n : start_index + chunk_size; // Last index for each thread

        // Initialize last_processed variable to capture the last index processed by each thread
        int last_processed;

        // Double each value in the array
        #pragma omp for
        for (int i = start_index; i < end_index; i++) {
            array[i] *= 2; // Double the value
            last_processed = i; // Update last processed index
        }

        // Print the last processed index for each thread
        #pragma omp nowait
        {
            printf("Thread %d processed up to index %d\n", thread_id, last_processed);
        }
    } // End of parallel region

    // Optionally, print the first few elements of the array to verify the result
    for (int i = 0; i < 100; i++) {
        printf("%d ", array[i]); // Print first 10 elements
    }
    printf("\n");

    // Free allocated memory
    free(array);

    return 0;
}
