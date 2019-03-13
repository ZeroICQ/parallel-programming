#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <vector>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

int main(int argc, char* argv[]) {

    printf("%d", atoi(argv[1]));
    return 0;
}