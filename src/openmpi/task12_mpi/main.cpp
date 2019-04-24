#include "mpi.h"
#include <vector>
#include <iostream>

using namespace std;
#define n 1000

void smod5(void *a, void *b, int *l, MPI_Datatype *type) {
    int i;
    for(i = 0; i<*l; i++)
        ((int*)b)[i] = (((int*)a)[i] + ((int*)b)[i])%5;
}

void mymax(void *a, void *b, int *l, MPI_Datatype *type) {
    for (auto i = 0; i < *l; i++) {
        ((int*)b)[i] = max(((int*)a)[i], ((int*)b)[i]);
    }
}


int main(int argc, char **argv) {
    int rank, size;
    int a;
    int myreduce, origreduce;

    MPI_Init(&argc, &argv);
    MPI_Op maxop;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//    printf("process %d ", rank);
    MPI_Op_create(&mymax, 1, &maxop);

    a = rank;
    MPI_Reduce(&a, &myreduce, 1, MPI_INT, maxop, 0, MPI_COMM_WORLD);
    MPI_Reduce(&a, &origreduce, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    MPI_Op_free(&maxop);
    if(rank == 0) {
        cout << "my max val is " << myreduce << endl;
        cout << "mpi max val is " << origreduce << endl;
    }
    MPI_Finalize();

    return EXIT_SUCCESS;
}