#include <common.h>

using namespace std;

void runChat(MPI_Comm intercomm) {
    MPI_Status status;

    int count;
    bool execute = true;
    string mymessage;

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
                if (mymessage == "exit") {
                    execute = false;
                    continue;
                }

                MPI_Send(mymessage.data(), mymessage.size(), MPI_CHAR, 0, 0, intercomm);
                mymessage.clear();
            }
        }

        #pragma omp section
        {
            int flag;
            // network section
            while (execute) {
                MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, intercomm, &flag, &status);
                if (!flag)
                    continue;

                MPI_Get_count(&status, MPI_CHAR, &count);
                char message[count + 1];
                message[count] = 0;
                MPI_Recv(&message, count, MPI_CHAR, 0, 0, intercomm, &status);
                cout << "" << string(message) << endl;
            }
        }
        }
    }
}
