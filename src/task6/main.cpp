#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <sstream>

#ifdef _WIN32
    #define _OPENMP _OMP_H
#endif

void client(omp_lock_t& read_lock, omp_lock_t& write_lock, std::string& input, const std::vector<std::string>& tasks);
void server(omp_lock_t& read_lock, omp_lock_t& write_lock, std::string& input);

int main(int argc, char* argv[]) {
    //initialize
    std::vector<std::string> task = {
            "5+3",
            "res/2",
            "24/res",
            "res*res",
            "res-6",
            "res-2",
            ""
    };

    omp_lock_t read_lock, write_lock;

    omp_init_lock(&read_lock);
    omp_set_lock(&read_lock);

    omp_init_lock(&write_lock);
    std::string input;

    #pragma omp parallel
    {
        #pragma omp sections
        {
            // server thread
            #pragma omp section
            {
                server(read_lock, write_lock, input);
            }
            // client thread
            #pragma omp section
            {
                client(read_lock, write_lock, input, task);
            }

        }
    }
    return 0;
}

void client(omp_lock_t& read_lock, omp_lock_t& write_lock, std::string& input, const std::vector<std::string>& tasks) {
    for (const auto& cmd : tasks) {
        omp_set_lock(&write_lock);
        input = cmd;


        omp_unset_lock(&read_lock);
    }
}

void server(omp_lock_t& read_lock, omp_lock_t& write_lock, std::string& input) {
    int res = 0;
    int term1, term2;
    char op;
    int tmpi;
    int tmpc;


    while (true) {
        omp_set_lock(&read_lock);
        std::stringstream ss;
        ss << input;

        if (input.length() == 0) {
            std::cout << res << std::endl;
            return;
        }

        if (input[0] == 'r') {
            term1 = res;
            op = input[3];

            if (input[4] == 'r') {
                term2 = res;
            }
            else {
                ss.get();
                ss.get();
                ss.get();
                ss.get();
                ss >> term2;
            }

        }
        else {
            ss >> term1;
            ss >> op;
            if (ss.peek() == 'r') {
                term2 = res;
            }
            else {
                ss >> term2;
            }
        }

        if (op == '+')
            res = term1 + term2;
        else if (op == '-')
            res = term1 - term2;
        else if (op == '/')
            res = term1 / term2;
        else if (op == '*')
            res = term1 * term2;

        omp_unset_lock(&write_lock);
    }
}