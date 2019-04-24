#include "mpi.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int rank, size, rank1;
    MPI_Init(&argc, &argv);

    MPI_Comm comm_revs;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//    MPI_Comm_split(MPI_COMM_WORLD, 1, size-rank, &comm_revs);
//    MPI_Comm_split(MPI_COMM_WORLD, rank % 2, size-rank, &comm_revs);
//    MPI_Comm_split(MPI_COMM_WORLD, rank % 3, size-rank, &comm_revs);
    MPI_Comm_split(MPI_COMM_WORLD, rank % 5, size-rank, &comm_revs);
    MPI_Comm_rank(comm_revs, &rank1);

    //Вывести на экран rank и rank1
    cout << "rank= " << rank << " rank1= " << rank1 << endl;

    MPI_Comm_free(&comm_revs);
    MPI_Finalize();

    return EXIT_SUCCESS;
}