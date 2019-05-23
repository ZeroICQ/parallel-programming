#include "mpi.h"
#include <omp.h>
#include <iostream>
#include <cstring>

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


    omp_set_num_threads(2);
    #pragma omp parallel
    {
        #pragma omp sections
        {

        #pragma omp section
        {
            // input section
            while (execute) {
                getline(cin, mymessage);
                cout << "message accepted" << endl;
                if (mymessage == "exit")
                    execute = false;

                MPI_Send(mymessage.data(), mymessage.size(), MPI_CHAR, 0, 0, intercomm);
                mymessage.clear();
            }
        }

        #pragma omp section
        {
            // network section
            while (execute) {
                MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &status);

                MPI_Get_count(&status, MPI_CHAR, &count);
                char message[count + 1];
                message[count] = 0;
                MPI_Recv(&message, count, MPI_CHAR, 0, 0, intercomm, &status);
                cout << "Client send: " << string(message) << endl;
            }
        }
        }
    }


    MPI_Comm_free(&intercomm);
    MPI_Finalize();
    return EXIT_SUCCESS;
}
