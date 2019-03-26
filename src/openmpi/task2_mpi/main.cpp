#include <stdio.h>
#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int rank, n, i, message;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    const int MY_VARIANT = 5;

    if (rank == MY_VARIANT)
    {
        std::cout << "root process is " << rank << "\n";
        for (i=0; i<n; i++){
            if (i == MY_VARIANT)
                continue;

            MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            std::cout << "Hello from process " << (message + rank) << std::endl;
        }
    }
    else
        MPI_Send(&rank,1,MPI_INT,MY_VARIANT,0,MPI_COMM_WORLD);

    MPI_Finalize();
    return 0;
}