#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    cout << "Start\n";

    int parallel = true;

    #pragma omp parallel if(parallel)
    {
        int index = omp_get_thread_num();
        bool isInParallel = omp_in_parallel();
        cout << "hello world 1\n";
        cout << "hello world 2\n";
        cout << "hello world 3\n";
    }

    cout << "End\n";
}