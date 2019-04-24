#include "mpi.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int size, rank;
    MPI_Init(&argc, &argv);

    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // инициализация матрицы каждым процессом
    int N = 500;
    vector<vector<int>> matrixA, matrixB, result;

    for (auto i = 0; i < N; i++) {
        matrixA.emplace_back();
        matrixB.emplace_back();
        result.emplace_back();
        for (auto j = 0; j < N; j++) {
            matrixA[i].push_back(1);
            matrixB[i].push_back(1);
            result[i].push_back(0);
        }
    }

    MPI_Barrier(MPI_COMM_WORLD); //барьерная синхронизация процессов
    // начало замера времени для каждого процесса
    auto start_time = MPI_Wtime();
    // перемножение матриц
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    // конец замера времени
    auto time_elapsed = MPI_Wtime() - start_time;
    // вывод время выполнения перемножения матриц на каждом процессе
    cout << "Process " << rank << " took " << time_elapsed << " seconds." << endl;

//    for (auto const& i : result) {
//        for (auto const &j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
    MPI_Finalize();

    return EXIT_SUCCESS;
}