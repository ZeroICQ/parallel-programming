#include "mpi.h"
#include <iostream>

int main(int argc, char **argv) {
    int rank, size;
    MPI_Comm intercomm;
    MPI_Init(&argc, &argv);
    // returns the parent intercommunicator of the current process
    MPI_Comm_get_parent(&intercomm);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(intercomm, &size);

    if (rank == 2)
        MPI_Send(&size, 1, MPI_INT, 0, rank, intercomm);
    else
        MPI_Send(&rank, 1, MPI_INT, 0, rank, intercomm);

    MPI_Finalize();
    return EXIT_SUCCESS;
}