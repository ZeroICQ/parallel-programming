#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <vector>

#ifdef _WIN32
#define _OPENMP _OMP_H
#endif

using intvector = std::vector<int>;

void dot_production(const intvector& vector_a, const intvector& vector_b) {
    long long dot_production = 0;
    auto start = omp_get_wtime();
    #pragma omp parallel num_threads(2)
    {
        long long local_dot_production = 0;
        #pragma omp for
        for (auto i = 0; i < vector_a.size(); i++) {
            local_dot_production += vector_a[i] * vector_b[i];
        }
        #pragma omp atomic
        dot_production += local_dot_production;

    }
    auto end = omp_get_wtime();
    printf("Dot production is %lld. Elapsed time %.17lf. Size is %llu . \n", dot_production, end-start, vector_a.size());
}

int main(int argc, char* argv[]) {
    for (auto vector_size = 100000000; vector_size >= 10000000; vector_size /= 2) {
        std::vector<int> vector_a(vector_size, 1);
        std::vector<int> vector_b(vector_size, 1);
        dot_production(vector_a, vector_b);
    }

    return 0;
}