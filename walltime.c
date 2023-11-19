#include <stdio.h>
#include <omp.h>
#include <time.h>
int main()
{

char name[10][20];

char reg[10][10];
int pay[10];
char org[10][10];
int i;
int tid;
float average;
int cA = 0, cG = 0, cS = 0, cI = 0;

double start; double end; double etime;
printf("Register No: 23MCS1019\n");
printf("Name: THEJAS S\n");

printf("Enter details:\n");
for(i = 0; i < 10; i++){
printf("Name %d: ", i+1);
scanf("%s", &name[i]);
printf("Register No: ");

scanf("%s", &reg[i]);
printf("Organization (Choose 1 A, G, S, I): "); // Amazon,Google, Shell, Intel);
scanf("%s", &org[i]);
printf("Pay grade (in LPA): ");
scanf("%d", &pay[i]);

}

//start = omp_get_wtime();
//end = omp_get_wtime();
//etime = end-start;
//printf("Work took %f seconds\n", etime);
#pragma omp parallel sections
{
//Calculating total number of students in each company

#pragma omp section
{
start = omp_get_wtime();
for(i = 0; i < 10; i++){
if(org[i][0] == 'A') {cA++;}
if(org[i][0] == 'G') {cG++;}
if(org[i][0] == 'S') {cS++;}
if(org[i][0] == 'I') {cI++;}
}
end = omp_get_wtime();
etime = end-start;
printf("Work took %f seconds\n", etime);
}
#pragma omp section
{
start = omp_get_wtime();
printf("Thread ID: %d\n", omp_get_thread_num());

printf("Total Students per company: \n");
printf("Amazon: %d\nGoogle: %d\nShell: %d\nIntel:%d", cA, cG, cS, cI);
end = omp_get_wtime();
etime = end-start;
printf("Work took %f seconds\n", etime);
}

#pragma omp section
{
start = omp_get_wtime();
printf("Thread ID: %d\n", omp_get_thread_num());
printf("Average pay package: \n");
average = 0;
for(i = 0; i < 10; i++){
average += pay[i];
}

average = average/10;
printf("%7.2f LPA\n", average);
end = omp_get_wtime();
etime = end-start;
printf("Work took %f seconds\n", etime);
}
}
return 0;
}
