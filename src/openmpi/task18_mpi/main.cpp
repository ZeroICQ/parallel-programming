#include "mpi.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define BUFSIZE 100

void create_file() {
    ofstream myfile;
    myfile.open ("file.txt");
    for (int i = 0; i < BUFSIZE*10; i++) {
        myfile << 'a';
    }
    myfile.close();
}

int main(int argc, char **argv) {
    create_file();
    int bufsize, num, sum;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_File fh;
    char buf[BUFSIZE];

    MPI_File_open(MPI_COMM_WORLD, "file.txt", MPI_MODE_RDONLY, MPI_INFO_NULL, &fh);
    //https://www.opennet.ru/docs/RUS/mpi-2/node175.html
    https://www.open-mpi.org/doc/v3.0/man3/MPI_File_set_view.3.php
    MPI_File_set_view(fh, 0, MPI_CHAR, MPI_CHAR, "native", MPI_INFO_NULL);
    sum = 0;
    do{
        MPI_File_read(fh, buf, BUFSIZE, MPI_CHAR, &status);
        MPI_Get_count(&status, MPI_CHAR, &num);
        printf("buf=%s\n", buf);
        sum += num;
    } while(num >= BUFSIZE);
    MPI_File_close(&fh);
    //    вывести число считанных символов sum из файла
    cout << sum << endl;
    MPI_Finalize();

    remove("file.txt");
    return EXIT_SUCCESS;
}