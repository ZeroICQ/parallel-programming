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

    auto start = omp_get_wtime();
    #pragma omp parallel for num_threads(8)
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) {
            for (auto k = 0; k < n; k++) {
                result[i][j] = matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    auto end = omp_get_wtime();
    printf("Elapsed time %.17lf. Size %d\n", end-start, n);
}

int main(int argc, char* argv[]) {
    for (auto matrix_size = 400; matrix_size >= 10; matrix_size/=2) {
        matrix matrix_a, matrix_b;

        for (auto i = 0; i < matrix_size; i++) {
            matrix_a.emplace_back();
            matrix_b.emplace_back();

            for (auto j = 0; j < matrix_size; j++) {
                matrix_a[i].push_back(2);
                matrix_b[i].push_back(2);
            }
        }

        multiply_matrices(matrix_a, matrix_b);
    }

    return 0;
}