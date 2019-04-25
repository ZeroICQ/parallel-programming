#include "mpi.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char **argv) {
    int rank;
    MPI_Init(&argc, &argv);
    char port_name[MPI_MAX_PORT_NAME];

    MPI_Comm intercomm;
    MPI_File  fh;

    MPI_File_open(MPI_COMM_WORLD, "portname.txt", MPI_MODE_RDONLY , MPI_INFO_NULL, &fh);
    MPI_File_set_view(fh, 0, MPI_CHAR, MPI_CHAR, "native", MPI_INFO_NULL);
    MPI_File_read(fh, port_name, MPI_MAX_PORT_NAME, MPI_CHAR, MPI_STATUS_IGNORE);

//    strcpy(port_name, argv[1]);

    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    rank = 10;
    MPI_Send(&rank, 1, MPI_INT, 0, 0, intercomm);

    MPI_Finalize();
    return EXIT_SUCCESS;
}