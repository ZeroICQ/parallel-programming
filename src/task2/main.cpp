#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <vector>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

void sum_array(int size, int initial_value) {
    std::vector<int> array_to_sum(size, initial_value);
    int sum = 0;
    printf("Sum without reduction\n");
    // result is inconsistent because of race conditions
    #pragma omp parallel for shared(sum)
    for (int i = 0; i < array_to_sum.size(); i++)
//        atomic operator fixes problem
//        #pragma omp atomic
        sum += array_to_sum[i];

    printf("Sum of array without with size %d initialized with %d is %d\n", size, initial_value,sum);

    printf("Sum with reduction\n");
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < array_to_sum.size(); i++)
        sum += array_to_sum[i];

    printf("Sum of array with size %d initialized with %d is %d\n", size, initial_value,sum);
}

int main(int argc, char* argv[]) {
    // 4a
    int count = 0;
    #pragma omp parallel reduction (+: count)
    {
        count++;
        printf("Current value of count: %d\n", count);
    }
    printf("Count in serial area: %d\n", count);


    // 18a
    int A[10], B[10], C[10], i, n;
    /* Заполним исходные массивы */
    for (i = 0; i < 10; i++){
        A[i] = i;
        B[i] = 2 * i;
        C[i] = 0;
    }

    #pragma omp parallel shared(A, B, C) private(i, n)
    {
        /* Получим номер текущей нити */
        n = omp_get_thread_num();
        #pragma omp for
        for (i = 0; i < 10; i++) {
            C[i] = A[i] + B[i];
            printf("Thread %d put elements with number %d\n", n, i);
        }
    }

    sum_array(100000 , 1);

    return 0;
}