#include<stdio.h>
#include<omp.h>
int main(){
int i,age[20],n;
printf("Enter the number of persons:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter the age of the %d person:",i);
scanf("%d",&age[i]);
printf("\n");
}
#pragma omp parallel sections
{
#pragma omp section
for(i=0;i<n;i++){
if(age[i]>=16 && age[i]<18){
printf("Thread %d: Eligible person ,age %d\n",omp_get_thread_num(),age[i]);
}
else{
printf("Thread %d:Ineligible person, age %d\n",omp_get_thread_num(),age[i]);
}
}
}
}

//Eligible candidates

#include <stdio.h>
#include <omp.h>

#define NUM_PEOPLE 10

int main() {
    int n = NUM_PEOPLE;
    int ages[NUM_PEOPLE];
    int i;
    int eligibleCount = 0;
    int nonEligibleCount = 0;
    printf("23MCS1019 - Thejas\n");
    for (i = 0; i < n; i++) {
        printf("Enter the age of %dth person: ", i + 1);
        scanf("%d", &ages[i]);
        printf("\n");
    }
   
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for (i = 0; i < n; i++) {
                if (ages[i] >= 16 && ages[i] < 18) {
                    eligibleCount++;
                }
            }
            printf("Thread is %d and Total number of eligible candidates: %d\n", omp_get_thread_num(),eligibleCount);
        }
       
        #pragma omp section
        {
            for (i = 0; i < n; i++) {
                if (!(ages[i] >= 16 && ages[i] < 18)) {
                    nonEligibleCount++;
                }
            }
            printf("Thread is %d and Total number of non-eligible candidates: %d\n",omp_get_thread_num(),nonEligibleCount);
        }
    }
    return 0;
}
