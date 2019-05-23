#include "mpi.h"
#include <omp.h>
#include <iostream>
#include <cstring>
#include <common.h>

using namespace std;

char port_name[MPI_MAX_PORT_NAME];

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    MPI_Comm intercomm;
    MPI_Status status;
    string message;
    cout << "portname: " <<  endl;
    cin >> port_name;

    bool execute = true;

    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);

    string mymessage;
    int count;


    runChat(intercomm);


    MPI_Comm_free(&intercomm);
    MPI_Finalize();
    return EXIT_SUCCESS;
}
