#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

void vecSum(int rank, int commSize, const vector<int>& vec) {
    auto leftChild  = 2*rank + 1;
    auto rightChild = 2*rank + 2;

    int* arr;

    if (rank == 0) {
        auto vecPointer = vec.data();
        auto leftSize = vec.size() / 2;
        auto rightSize = vec.size() - leftSize;

        MPI_Send(vecPointer, leftSize, MPI_INT, leftChild, 0, MPI_COMM_WORLD);
        MPI_Send(vecPointer + leftSize, rightSize, MPI_INT, rightChild, 0, MPI_COMM_WORLD);

        int sumL, sumR;
        MPI_Recv(&sumL, 1, MPI_INT, leftChild,  MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sumR, 1, MPI_INT, rightChild, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << sumL + sumR << end;
    }
    else {
        MPI_Recv()
    }

    if (leftChild < commSize) {

    }
    else {

    }

    if (rightChild < commSize) {

    }
    else {

    }
}

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int vector_size = 10000;

    vector<int>vec/(vector_size, 1);

//    double start_time;
//    if (rank == 0) {
//        start_time = MPI_Wtime();
//    }

    vecSum(vector_a, vector_b, rank, size);
//    if (rank == 0) {
//        cout << "Time elapsed: " << MPI_Wtime() - start_time << endl;
//    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}
