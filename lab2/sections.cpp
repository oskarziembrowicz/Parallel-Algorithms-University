#include <iostream>
#include <omp.h>

using namespace std;

int main() {

#pragma omp parallel
  {

#pragma omp sections
    {
#pragma omp section
      {
        cout << "S1: " << omp_get_thread_num() << "\n";
      }
#pragma omp section
      {
        cout << "S2: " << omp_get_thread_num() << "\n";
      }
    }
  }

  return 0;
}