#include <stdio.h>
#include <omp.h>
#include <iostream>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

int main(int argc, char* argv[]) {

    #ifdef _OPENMP
        printf("OpenMP is supported!\n");
    #endif

    printf("Serial area 1\n");

    int last_thread_number = omp_get_max_threads() - 1;
    #pragma omp parallel
    {
//        printf("Parallel area\n");
//        printf("I am thread numeber %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
        while (last_thread_number != omp_get_thread_num())
            ;

        printf("I am thread numeber %d out of %d\n", omp_get_thread_num() + 1, omp_get_num_threads());
        #pragma omp atomic
        last_thread_number--;

    }
    printf("Serial area 2\n");

    omp_set_num_threads(3);
    #pragma omp parallel
    {
        printf("Parallel area 1\n");
    }

    #pragma omp barrier

    #pragma omp single
    printf("\n");

    #pragma omp parallel num_threads(10)
    {
        printf("Parallel area 2\n");
    }
}