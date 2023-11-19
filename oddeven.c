#include<stdio.h>
#include<omp.h>
int main(){
	int num[10],n,i,even[10],odd[10],ecount=0,ocount=0,evensum=0,oddsum=0;
	printf("Enter the number of elements to be inserted(maximum 10): ");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for((i=0;i<n;i++)
		scanf("%d",&num[i]);
	#pragma omp parallel for
	for(i=0;i<n;i++){
		if(num[i]%2==0){
			even[ecount++]=num[i];
			evensum+=num[i];
		}
		else{
			odd[ocount++]=num[i];
			oddsum+=num[i];
		}
		printf("\nThread Number: %d",omp_get_thread_num());
	}
	printf("\nEven numbers are: \n",n);
	for(i=0;i<ecount;i++)
		printf("%d",even[i]);
	printf("\nOdd numbers are: \n",n);
	for(i=0;i<ocount;i++)
		printf("%d",odd[i]);
	printf("\nSum of even numbers: %d\nSum of odd numbers: %d\n",evensum,oddsum);
	printf("Number of processors:%d\n",omp_get_num_procs());
	printf("\n");
}