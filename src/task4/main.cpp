#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <climits>
#include <vector>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

using intvector = std::vector<int>;

void find_max(const intvector& vec) {
    auto max_threads = omp_get_max_threads();
    for (auto threads_number = 1; threads_number <= max_threads; threads_number++) {
        int max_elem = INT_MIN;
        omp_set_num_threads(threads_number);
        auto start = omp_get_wtime();

        #pragma omp parallel for reduction(max: max_elem)
        for (int i = 0; i < vec.size(); i++) {
            max_elem = std::max(max_elem, vec[i]);
        }
        auto end = omp_get_wtime();

        printf("Elapsed time is %.17lf.maximum is %d. %d threads.\n", end-start, max_elem, threads_number);
    }

}

int main(int argc, char* argv[]) {
    auto vector_size = atoi(argv[1]);

    std::vector<int> vec(vector_size);
    for (auto i = 0; i < vec.size(); i++) {
        vec[i] = i*i;
    }

    find_max(vec);

    return 0;
}