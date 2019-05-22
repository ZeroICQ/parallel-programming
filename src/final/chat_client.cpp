#include "mpi.h"
#include <iostream>
#include <cstring>

using namespace std;

char port_name[MPI_MAX_PORT_NAME];

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    MPI_Comm intercomm;
    string message;
    cout << "portname: " <<  endl;
    cin >> port_name;

    bool execute = true;

    MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);

    while (execute) {
        auto c = getchar();
        if (c != EOF && c != '\n')
            message += c;

        if (c == '\n') {
            if (message == "exit") {
                execute = false;
                break;
            }
            MPI_Send(message.data(), message.size(), MPI_CHAR, 0, 0, intercomm);
            message.clear();
        }

    }

    MPI_Finalize();
    return EXIT_SUCCESS;
}