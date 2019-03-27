#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;
using intvector = std::vector<int>;

void dot_production(const intvector& vector_a, const intvector& vector_b, int rank, int processors)
{
    auto vec_size = vector_a.size();
    auto chunk_size = vector_a.size() / processors;
    auto last_chunk_size = vec_size - (processors - 1)*chunk_size;

    auto start_index = rank * chunk_size;
    auto after_last_index = start_index + chunk_size;
    auto local_sum = 0;

    if (rank != processors - 1) {
        for (auto i = start_index; i < after_last_index; i++) {
            local_sum += vector_a[i] * vector_b[i];
        }
    }
    else {
        for (auto i = start_index; i < start_index + last_chunk_size; i++) {
            local_sum += vector_a[i] * vector_b[i];
        }
    }

    int result = 0;
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&local_sum, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
        cout << result << endl;

}


int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int vector_size = 20000000;

    std::vector<int>vector_a(vector_size, 1);
    std::vector<int>vector_b(vector_size, 1);


    double start_time;
    if (rank == 0) {
        start_time = MPI_Wtime();
    }

    dot_production(vector_a, vector_b, rank, size);
    if (rank == 0) {
        cout << "Time elapsed: " << MPI_Wtime() - start_time << endl;
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}