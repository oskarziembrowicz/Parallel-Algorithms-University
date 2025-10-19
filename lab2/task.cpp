#include <iostream>

using namespace std;

bool f1() {
  return true;
}

bool f2() {
  return false;
}

bool f3() {
  return true;
}

bool f4() {
  return true;
}

bool f5() {
  return true;
}


int main() {
  bool result = true;

#pragma omp parallel 
  {
    #pragma omp sections
    {
      #pragma omp section
      {
        if (!f2()) {
          #pragma omp critical
          result = false;
        }
      }
      #pragma omp section
      {
        if (!f2()) {
          #pragma omp critical
          result = false;
        }
      }
      #pragma omp section
      {
        if (!f2()) {
          #pragma omp critical
          result = false;
        }
      }
      #pragma omp section
      {
        if (!f2()) {
          #pragma omp critical
          result = false;
        }
      }
      #pragma omp section
      {
        if (!f2()) {
          #pragma omp critical
          result = false;
        }
      }
    }
  }

  cout << result << "\n";

  return 0;
}