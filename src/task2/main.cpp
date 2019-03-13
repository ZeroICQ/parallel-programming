#include <stdio.h>
#include <omp.h>
#include <iostream>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

int main(int argc, char* argv[]) {
    //4a
    int count = 0;
    #pragma omp parallel reduction (+: count)
    {
        count++;
        printf("Current value of count: %d\n", count);
    }
    printf("Count in serial area: %d\n", count);


    //18a
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

    return 0;
}