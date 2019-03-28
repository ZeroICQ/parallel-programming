#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

void bandwidth(int length, int rank) {
    auto message = new char[length];
    auto N = 100;
    double elapsed_time = 0;

    for (auto i = 0; i < N; i++) {
        auto start_time = MPI_Wtime();

        if (rank == 0) {
            MPI_Send(message, length, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
            MPI_Recv(message, length, MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else if (rank == 1) {
            MPI_Recv(message, length, MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Send(message, length, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        }
    }

    delete[] message;
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);





    MPI_Finalize();
    return EXIT_SUCCESS;
}