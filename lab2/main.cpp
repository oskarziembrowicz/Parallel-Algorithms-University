#include <iostream>

using namespace std;

int main() {
  // Variable defined before parallel block is shared between threads
  int sharedVar = 0;

  #pragma omp parallel num_threads(4)
  {
    int privateVar = 0;
    for (int i = 0; i < 250000000; i++) {
      privateVar++;
    }

    #pragma omp atomic
    sharedVar += privateVar;
  }

  cout << sharedVar << "\n";

  return 0;
}