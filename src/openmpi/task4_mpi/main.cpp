#include <iostream>

#include "mpi.h"

#define NTIMES 100

using namespace std;

int main(int argc, char **argv)
{
    double time_start, time_finish;
    int rank, i, n;
    int len;
    char *name = new char;
    int buf;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Get_processor_name(name, &len);
    time_start = MPI_Wtime();

    for (i = 0; i < NTIMES; i++)
        time_finish = MPI_Wtime();

    // wait
    if (rank != 0)
        MPI_Recv(&buf, 1, MPI_INT, rank - 1, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // print average time of one iteration
    cout << "processor " << name << ", process " << rank << ", time = " << (time_finish-time_start)/NTIMES << endl;
    if (rank != n-1)
        MPI_Send(&buf, 1, MPI_INT, rank + 1, 1, MPI_COMM_WORLD);

    MPI_Finalize();
}