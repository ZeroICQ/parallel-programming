#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <cmath>

#ifdef _WIN32
#define _OPENMP _OMP_H
#endif


int main(int argc, char *argv[])
{
    int count = 0;
#pragma omp parallel
    {
#pragma omp atomic
        count++;
    }
    printf("counter: %d\n", count);
    return 0;
}