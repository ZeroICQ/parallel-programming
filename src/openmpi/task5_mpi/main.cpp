#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv)
{
    int rank, size, ibuf;
    MPI_Status status;
    float rbuf;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    ibuf = rank;
    rbuf = 1.0 * rank;

    const int INT_TAG = 5;
    const int REAL_TAG = 50;


    if(rank == 1) MPI_Send(&ibuf, 1, MPI_INT, 0, INT_TAG, MPI_COMM_WORLD);
    if(rank == 2) MPI_Send(&rbuf, 1, MPI_FLOAT, 0, REAL_TAG, MPI_COMM_WORLD);
    if(rank == 0) {
        // wait until can receive message
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

        if(status.MPI_TAG == INT_TAG) {
            MPI_Recv(&ibuf, 1, MPI_INT, MPI_ANY_SOURCE, INT_TAG, MPI_COMM_WORLD, &status);
            MPI_Recv(&rbuf, 1, MPI_FLOAT, MPI_ANY_SOURCE, REAL_TAG, MPI_COMM_WORLD, &status);
            cout << "Process 0 recv " << ibuf << " from process 1, " << rbuf << " from process 2\n";
        }
        else if(status.MPI_TAG == REAL_TAG){
            MPI_Recv(&rbuf, 1, MPI_FLOAT, MPI_ANY_SOURCE, REAL_TAG, MPI_COMM_WORLD, &status);
            MPI_Recv(&ibuf, 1, MPI_INT, MPI_ANY_SOURCE, INT_TAG, MPI_COMM_WORLD, &status);
            cout << "Process 0 recv " << rbuf << " from process 2, " << ibuf << " from process 1\n";
        }
    }
    MPI_Finalize();
}