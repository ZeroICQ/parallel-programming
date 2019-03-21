#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <climits>
#include <vector>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

using matrix = std::vector<std::vector<int>>;

void multiply_matrices(const matrix& matrix_a, const matrix& matrix_b) {
    auto n = matrix_a.size();
    matrix result;

    for (auto i = 0; i < n; i++) {
        result.emplace_back();
        for (auto j = 0; j < n; j++) {
            result[i].push_back(0);
        }
    }

    // start computation
    auto max_threads = omp_get_max_threads();
    for (auto threads_number = 1; threads_number <= max_threads; threads_number++) {

        auto start = omp_get_wtime();
        #pragma omp parallel for num_threads(threads_number)
        for (auto i = 0; i < n; i++) {
            #pragma omp parallel for num_threads(threads_number)
            for (auto j = 0; j < n; j++) {
                for (auto k = 0; k < n; k++) {
                    result[i][j] = matrix_a[i][k] * matrix_b[k][j];
                }
            }
        }

        auto end = omp_get_wtime();
        printf("Elapsed time %.17lf. Threads number %d\n", end-start, threads_number);
    }
}

int main(int argc, char* argv[]) {
    matrix matrix_a, matrix_b;
    int matrix_size = atoi(argv[1]);

    for (auto i = 0; i < matrix_size; i++) {
        matrix_a.emplace_back();
        matrix_b.emplace_back();

        for (auto j = 0; j < matrix_size; j++) {
            matrix_a[i].push_back(2);
            matrix_b[i].push_back(2);
        }
    }

    multiply_matrices(matrix_a, matrix_b);
    return 0;
}