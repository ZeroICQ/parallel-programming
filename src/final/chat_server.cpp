#include "mpi.h"
#include <iostream>

using namespace std;

//server
char port_name[MPI_MAX_PORT_NAME];

int main(int argc, char **argv) {
    int r, rank;
    MPI_Init(&argc, &argv);

    MPI_Status status;
    MPI_Comm intercomm;
    MPI_Open_port(MPI_INFO_NULL, port_name);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_File fh;

    printf("portname: %s\n", port_name);

    cout << "Waiting for client..." << endl;
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
    cout << "Client connected..." << endl;

    int count;
    bool execute = true;
    string mymessage;

    while (execute) {
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &status);
        MPI_Get_count(&status, MPI_CHAR, &count);

        char message[count + 1];
        message[count] = 0;

        MPI_Recv(&message, count, MPI_CHAR, 0, 0, intercomm, &status);


        cout << "Client send: " << string(message) << endl;


    }

    while (execute) {
        aut

    }

    MPI_Comm_free(&intercomm);
    MPI_Close_port(port_name);

    MPI_Finalize();

    return EXIT_SUCCESS;
}