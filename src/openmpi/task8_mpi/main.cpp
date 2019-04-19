#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

void vecSum(int rank, int commSize, const vector<int>& vec) {
    auto leftChild  = 2*rank + 1;
    auto rightChild = 2*rank + 2;

    if (rank == 0) {
        auto vecPointer = vec.data();
        auto leftSize = vec.size() / 2;
        auto rightSize = vec.size() - leftSize;

        auto start_time = MPI_Wtime();

        MPI_Send(vecPointer, leftSize, MPI_INT, leftChild, 0, MPI_COMM_WORLD);
        MPI_Send(vecPointer + leftSize, rightSize, MPI_INT, rightChild, 0, MPI_COMM_WORLD);

        int sumL, sumR;
        MPI_Recv(&sumL, 1, MPI_INT, leftChild,  MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&sumR, 1, MPI_INT, rightChild, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "size time elapsed: " << MPI_Wtime() - start_time << " for size " << vec.size() << endl;
        cout << sumL + sumR << endl;
    }
    else {
        MPI_Status status;
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

        int count;
        MPI_Get_count(&status, MPI_INT, &count);
        auto arr = new int[count];

        MPI_Recv(arr, count, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

        auto leftSize = count / 2;
        auto rightSize = count - leftSize;

        auto hasLeftChild = leftChild < commSize;
        auto hasRightChild = rightChild < commSize;

        int sumL = 0, sumR = 0;

        if (hasLeftChild) {
            MPI_Send(arr, leftSize, MPI_INT, leftChild, 0, MPI_COMM_WORLD);
            MPI_Recv(&sumL, 1, MPI_INT, leftChild,  MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else {
            for (int i = 0; i < leftSize; i++) {
                sumL += arr[i];
            }
        }

        if (hasRightChild) {
            MPI_Send(arr+ leftSize, rightSize, MPI_INT, rightChild, 0, MPI_COMM_WORLD);
            MPI_Recv(&sumR, 1, MPI_INT, rightChild, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else {
            for (int i = leftSize; i < count; i++) {
                sumR += arr[i];
            }
        }

        auto sum = sumL + sumR;

        MPI_Send(&sum, 1, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);

        delete[] arr;
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
