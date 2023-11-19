#include <stdio.h>
#include <omp.h>
int main() {
int counter = 0;
printf("Name : THEJAS S \n");
printf("Reg.No: 23MCS1019 \n");
printf("Static scheduling\n");
#pragma omp parallel for num_threads(4) schedule(static, 64) lastprivate(counter)
for (int i = 0; i < 256; i++) {
counter++;
if (counter >= 256) {
// Transfer toys to dispatching unit
counter = 0;
}
printf("Thread number : %d, counter value : %d Iteration :%d\n",omp_get_thread_num(),counter,i);
}
printf("\n\nDynamic scheduling\n");

#pragma omp parallel for num_threads(4) schedule(dynamic, 64) lastprivate(counter)
for (int i = 0; i < 256; i++) {
counter++;
if (counter >= 256) {
// Transfer toys to dispatching unit
counter = 0;
}
printf("Thread number : %d, counter value : %d Iteration :%d\n",omp_get_thread_num(),counter,i);
}

printf("\n\nGuided scheduling\n");
#pragma omp parallel for num_threads(4) schedule(guided, 64) lastprivate(counter)
for (int i = 0; i < 256; i++) {
counter++;
if (counter >= 256) {
// Transfer toys to dispatching unit
counter = 0;
}
printf("Thread number : %d, counter value : %d Iteration :%d\n",omp_get_thread_num(),counter,i);
}
return 0;
}
