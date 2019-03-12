#include <stdio.h>
#include <clocale>
#include <cstdlib>
#include <omp.h>

#define _OPENMP _OMP_H

int main(int argc, char *argv[])
{
    printf("posl 1\n");
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        printf("parall\n");
    }
    printf("posl 2\n");
}