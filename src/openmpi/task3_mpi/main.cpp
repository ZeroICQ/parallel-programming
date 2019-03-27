#include <stdio.h>

#include <iostream>
#include <climits>
#include "mpi.h"


using namespace std;

void printTime(double time_start) {
    std::cout << "Time elapsed: " << MPI_Wtime() - time_start << std::endl;
}

int main(int argc, char* argv[]){
    MPI_Init(&argc, &argv);
    int rank, n, i, message;

    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    auto time_start = MPI_Wtime();

    if (rank == 0)
    {
        int minEl = INT_MIN;

        cout << "root process " << rank << "\n";

        for (i=1; i<n; i++)
        {
            MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            cout << "got " << message << endl;
            if (message <= minEl) {
                cout << "Not increasing sequence" << endl;
                printTime(time_start);
                goto end;
            }
            minEl = message;

        }

        cout << "Increasing sequence" << endl;
        printTime(time_start);
    }
    else
    {
        MPI_Request req;
        MPI_Isend(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &req);
    }
end:

    MPI_Finalize();
    return 0;
}