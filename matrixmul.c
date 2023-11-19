#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#define N 100
int A[N][N];
int B[N];
int C[N];
int main()
{
printf("Thejas S - 23MCS1019\n\n");
 int i,j,k=0;
 struct timeval tv1, tv2;
 struct timezone tz;
double elapsed;
 omp_set_num_threads(omp_get_num_procs());
 for (i= 0; i< 3; i++)
 {
  B[i] = 5;
 for (j= 0; j< 3; j++)
{
 A[i][j] = 2;
}
}
printf("Matrix A :\n");
for (i = 0; i < 3; ++i) {
 for (j = 0; j < 3; ++j) {
   printf("%d \t",A[i][j]);
 }
 printf("\n");
}
printf("Vector B :\n");
for (i = 0; i < 3; ++i)
 printf("%d\n",B[i]);
 gettimeofday(&tv1, &tz);
#pragma omp parallel for private(i,j,k) shared(A,B,C)
 for (i = 0; i < 3; ++i) {
 for (j = 0; j < 3; ++j) {
 C[k++] += A[i][j] * B[j];
 
 }
 }
 gettimeofday(&tv2, &tz);
 elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double)
(tv2.tv_usec-tv1.tv_usec) * 1.e-6;

printf("elapsed time = %f seconds.\n", elapsed);
for (i= 0; i< 3; i++)
 {
 printf("%d\n",C[i]);
 }

}
