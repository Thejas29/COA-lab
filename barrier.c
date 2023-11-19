#include <stdio.h>
#include <omp.h>

int main() {
    int N = 10; // Number of terms in the series
    double sum = 0.0;
    printf("Enter the Number of series to Add: ");
    scanf("%d",&N);
    double last_value = 1.0 / (1 << N); // Calculate the last value in the series

    // Set the number of threads
    omp_set_num_threads(12);

    // Open the file for writing the output
    FILE *file = fopen("C:\\Users\\student\\Desktop\\23MCS1019\\Thejas.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        double local_sum = 0.0;

        // Parallel loop with static scheduling
        #pragma omp for ordered schedule(static,10)
        for (int i = 1; i <= N; i++) {
            double term = 1.0 / (1 << i);
            local_sum += term;

            // Ordered construct to print the sum and last value
            #pragma omp ordered
            {
                fprintf(file, "Thread %d: Sum = %.10f, Last Value = %.10f\n", thread_id, local_sum, last_value);
            }
        }

        // Reduction to calculate the total sum
        #pragma omp critical
        {
            sum += local_sum;
        }

        // Barrier to synchronize all threads before writing the final sum
        #pragma omp barrier

        // Only the master thread (thread ID 0) writes the final sum
        #pragma omp master
        {
            fprintf(file, "Final Sum = %.10f\n", sum);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
