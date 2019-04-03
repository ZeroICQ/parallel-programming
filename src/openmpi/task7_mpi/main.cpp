#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;


int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    double start_time;
    if (rank == 0) {
        start_time = MPI_Wtime();
    }

    if (rank == 0) {
        cout << "Time elapsed: " << MPI_Wtime() - start_time << endl;
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}