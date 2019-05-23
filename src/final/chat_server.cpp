#include "mpi.h"
#include <omp.h>
#include <iostream>
#include "common.h"
using namespace std;

//server
char port_name[MPI_MAX_PORT_NAME];

int main(int argc, char **argv) {
    int r, rank;
    MPI_Init(&argc, &argv);

    MPI_Comm intercomm;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("portname: %s\n", port_name);

    cout << "Waiting for client..." << endl;
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Client connected..." << endl;

    runChat(intercomm);

    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);

    MPI_Finalize();

    return EXIT_SUCCESS;
}
