#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    double ticket = 100;
    double start, end, etime;
    int i, tid;
    double discount = 0.0f;
    double servicecost;
    printf("Name: THEJAS S\n");
    printf("Reg No: 23MCS1019\n");

    printf("Let us assume the original ticket cost is 100 each.\n");
    omp_set_num_threads(4);
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            start = omp_get_wtime();
            printf("Calculating for passenger 1 to 20 (Thread no: %d)\n", tid = omp_get_thread_num());
            if(tid == 0) printf("Master thread detected from 1 to 20\n");
            for(i = 1; i <= 100; i++)
            {
                if( i <= 20 )
                    discount = discount + 0.4;
            }
            end = omp_get_wtime();
            etime = end-start;
            printf("Execution time: %f (1 to 20)\n", etime);

        }

        #pragma omp section
        {
            start = omp_get_wtime();

            printf("Calculating for passenger 21 to 40 (Thread no: %d)\n", tid = omp_get_thread_num());
            if(tid == 0) printf("Master thread detected from 21 to 40\n");
            for(i = 1; i <= 100; i++)
            {
                if( i >= 21 && i <= 40)
                    discount = discount + 0.3;

            }
            end = omp_get_wtime();
            etime = end-start;
            printf("Execution time: %f (21 to 40)\n", etime);

        }

         #pragma omp section
        {
            start = omp_get_wtime();
            printf("Calculating for passenger 41 to 70 (Thread no: %d)\n", tid = omp_get_thread_num());
            if(tid == 0) printf("Master thread detected from 41 to 70\n");
            for(i = 1; i <= 100; i++)
            {
                if (i >= 41 && i <= 70)
                    discount = discount + 0.25;
            }
            end = omp_get_wtime();
            etime = end-start;
            printf("Execution time: %f (41 to 70)\n", etime);

        }

         #pragma omp section
        {
            start = omp_get_wtime();
            printf("Calculating for passenger 71 to 100 (Thread no: %d)\n", tid = omp_get_thread_num());
            if(tid == 0) printf("Master thread detected from 71 to 100\n");
            for(i = 1; i <= 100; i++)
            {
                if (i >= 71 && i <= 100)
                    discount = discount + 0.1;
            }
            end = omp_get_wtime();
            etime = end-start;
            printf("Execution time: %f (71 to 100)\n", etime);

        }
    }
    servicecost = (ticket*100)- ((ticket)*discount);
    printf("\nEach service earning for 100 passengers: %.2f Rs\n", servicecost);
    printf("\n3 service earning for 100 passengers: %.2f Rs\n", servicecost * 3);
    printf("\nMonthly earning for 100 passengers (30 days): %.2f Rs\n", servicecost * 3 * 30);
    printf("\nProcessor count: %d", omp_get_num_procs());
    return 0;
}
