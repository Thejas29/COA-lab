#include <omp.h>
#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Name: Thejas S\n");
    printf("Reg No: 23MCS1019\n\n");
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Odd series:\n");
    #pragma omp parallel for ordered
    for(i = 1; i < 2*n; i+= 2)
    {

        #pragma omp ordered
        printf("Thread %d No:  %d\n", omp_get_thread_num(), i);
    }
    printf("\n");

    printf("Even series:\n");
    #pragma omp parallel for ordered
    for(i = 0; i < 2*n; i+= 2)
    {

        #pragma omp ordered
        printf("Thread %d No:  %d\n", omp_get_thread_num(), i);
    }

}

//techno vit
#include <stdio.h>
#include <omp.h>
#define MAX_STUDENTS 100

int registered_students[MAX_STUDENTS];
int num_registered = 0;
omp_lock_t lock;
void register_student(int num) 
{
    omp_set_lock(&lock);
    registered_students[num_registered++] = num;
    omp_unset_lock(&lock);
}

void unregister_student(int num)
{
    omp_set_lock(&lock);
    for (int i = 0; i < num_registered; i++) {
        if (registered_students[i] == num) {
            registered_students[i] = registered_students[--num_registered];
            break;
        }
    }
    omp_unset_lock(&lock);
}

void print_students() {
    for (int i = 0; i < num_registered; i++) {
        printf("%d ", registered_students[i]);
    }
    printf("\n");
}

int main() {

    omp_init_lock(&lock);

    int n, m;
    printf("Number of students to register: ");
    scanf("%d", &n);
    int register_ids[n];
    for (int i = 0; i < n; i++) {
        printf("Enter student ID to register: ");
        scanf("%d", &register_ids[i]);
    }
   
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        register_student(register_ids[i]);
    }
   
    printf("Registered students: ");
    print_students();

    printf("Number of students to unregister: ");
    scanf("%d", &m);
    int unregister_ids[m];
    for (int i = 0; i < m; i++) {
        printf("Enter student ID to unregister: ");
        scanf("%d", &unregister_ids[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        unregister_student(unregister_ids[i]);
    }

    printf("Registered students after unregistering: ");
    print_students();

    omp_destroy_lock(&lock);
printf("THEJAS S 23MCS1019");

    return 0;
}
