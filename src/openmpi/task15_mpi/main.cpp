#include "mpi.h"
#include <vector>
#include <iostream>

using namespace std;

void print_arrs(float *a, char *b, size_t size, int rank) {
    cout << "rank= " << rank << endl;

    cout << "a: " << endl;
    for (auto i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "b: " << endl;

    for (auto i = 0; i < size; i++) {
        cout << b[i] << " ";
    }
    cout << endl << endl;
}

int main(int argc, char **argv) {
    int size, rank, position, i;
    float a[10];
    char b[10], buf[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for(i = 0; i<10; i++){
        a[i] = rank + 1.0;

        if(rank == 0)
            b[i]='a';
        else
            b[i] = 'b';
    }

    position = 0;

    if(rank == 0){
        print_arrs(a, b, 10, rank);
        // упаковка данных. помещает 10 элементов в buf, со смещением position.
        // position += 10 после операции. Тип данных MPI_PACKED
        MPI_Pack(a, 10, MPI_FLOAT, buf, 100, &position, MPI_COMM_WORLD);
        MPI_Pack(b, 10, MPI_CHAR, buf, 100, &position, MPI_COMM_WORLD);
        // рассылает 100 элементов от процесса 0 всем процессам в коммуникаторе,
        // включая сам процесс 0
        MPI_Bcast(buf, 100, MPI_PACKED, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Bcast(buf, 100, MPI_PACKED, 0, MPI_COMM_WORLD);
        position = 0;
        // процедура распаковки аналогична процедуре упаковки.
        MPI_Unpack(buf, 100, &position, a, 10, MPI_FLOAT, MPI_COMM_WORLD);
        MPI_Unpack(buf, 100, &position, b, 10, MPI_CHAR, MPI_COMM_WORLD);
        print_arrs(a, b, 10, rank);
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}