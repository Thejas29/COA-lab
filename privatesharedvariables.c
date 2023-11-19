#include <stdio.h>
#include <stdbool.h>
#include <omp.h>

bool isPrimeNumber(int num) {
if (num <= 1) {
return false;
}
for (int i = 2; i * i <= num; i++) {
if (num % i == 0) {
return false;
}
}
return true;
}

bool isRationalNumber(int num) {
return num % 2 == 0;
}

bool isPerfectNumber(int num) {
if (num <= 1) {
return false;
}
int sum = 1;
for (int i = 2; i * i <= num; i++) {
if (num % i == 0) {
sum += i;
if (i != num / i) {
sum += num / i;
}
}
}
return sum == num;
}

int main() {
int num;
printf("Name: Thejas S\n Reg No: 23MCS1019\n");
printf("Enter an integer: ");
scanf("%d", &num);

#pragma omp parallel num_threads(3) private(isRational) lastpri-vate(isPerfect) firstprivate(isPrime)
{
#pragma omp sections
{
#pragma omp section
{
if (isRationalNumber(num)) {
#pragma omp critical
printf("%d is a rational number.\n", num);
}
}
#pragma omp section
{
if (isPerfectNumber(num)) {
#pragma omp critical
printf("%d is a perfect number.\n", num);
}
}
#pragma omp section
{
if (isPrimeNumber(num)) {
#pragma omp critical
printf("%d is a prime number.\n", num);
}
}
}
}
return 0;
}
