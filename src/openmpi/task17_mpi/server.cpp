#include "mpi.h"
#include <iostream>

using namespace std;

//server
int main(int argc, char **argv) {
    int r, rank;
    MPI_Init(&argc, &argv);

    char port_name[MPI_MAX_PORT_NAME];

    MPI_Status status;
    MPI_Comm intercomm;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_File fh;

    printf("portname: %s\n", port_name);
    if (rank == 0) {
        cout << "write to file" << endl;
        MPI_File_open(MPI_COMM_WORLD, "portname.txt", MPI_MODE_CREATE | MPI_MODE_WRONLY | MPI_MODE_DELETE_ON_CLOSE, MPI_INFO_NULL, &fh);
        MPI_File_write(fh, &port_name, strlen(port_name), MPI_CHAR, MPI_STATUS_IGNORE);
    }
    cout << "Waiting for client..." << endl;

    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Client connected.." << endl;

    MPI_Recv(&r, 1, MPI_INT, 0, 0, intercomm, &status);

    if (rank == 0) {
        MPI_File_close(&fh);
    }
    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);

    printf("Client send %d\n", r);
    MPI_Finalize();

    return EXIT_SUCCESS;
}