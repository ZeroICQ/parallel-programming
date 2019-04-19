#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

void vecSum(int rank, int commSize, const vector<int>& vec) {
    int size;
    if (rank == commSize -1) {
        size = vec.size() - (commSize - 1) * (vec.size() / commSize);
    }
    else {
        size = vec.size() / commSize;
    }

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += vec[ rank * (vec.size() / commSize) + i];
    }
    int result;
    auto start = MPI_Wtime();

    MPI_Reduce(&sum, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        cout << "time elapsed: " << MPI_Wtime() - start << " for size " << vec.size() << endl;
        cout << result << endl;
    }
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int vector_size = 100000000;

    vector<int>vec(vector_size, 1);

    vecSum(rank, size, vec);

    MPI_Finalize();

    return EXIT_SUCCESS;
}
