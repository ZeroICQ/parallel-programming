#include <mpi.h>
#include <cstdlib>
#include <iostream>
#include "Game.h"

using namespace std;

//server
//char port_name[MPI_MAX_PORT_NAME];

int main(int argc, char* argv[]) {
    Game game;
    return EXIT_SUCCESS;

//    MPI_Init(&argc, &argv);
//    int rank, n, i;
//
//    MPI_Status status;
//    MPI_Comm_size(MPI_COMM_WORLD, &n);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_File fh;
//    MPI_Comm intercomm;
//    MPI_Open_port(MPI_INFO_NULL, port_name);
//
//    printf("portname: %s\n", port_name);
//    if (rank == 0) {
//        cout << "write to file" << endl;
//        MPI_File_open(MPI_COMM_WORLD, "portname.txt", MPI_MODE_CREATE | MPI_MODE_WRONLY | MPI_MODE_DELETE_ON_CLOSE, MPI_INFO_NULL, &fh);
//        MPI_File_write(fh, &port_name, strlen(port_name), MPI_CHAR, MPI_STATUS_IGNORE);
//    }
//
//    cout << "Waiting for another person..." << endl;
//    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
//
//    bool run_server = true;
//    int count;
//    int can_receive;
//
//    while (run_server) {
//        MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &can_receive, &status);
//
//        if (!can_receive)
//            continue;
//
//        MPI_Get_count(&status, MPI_CHAR, &count);
//        char message[count+1];
//        message[count] = 0;
//        cout << "Got count: " << count << endl;
//        MPI_Recv(&message, count, MPI_CHAR, 0, 0, intercomm, &status);
//        cout << "Client send " << string(message) << endl;
//    }

//    if (rank == 0) {
//        MPI_File_close(&fh);
//    }
//    MPI_Comm_free(&intercomm);
//    MPI_Close_port(port_name);
//
//    MPI_Finalize();
}