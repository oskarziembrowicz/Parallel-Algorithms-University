#include <iostream>
#include <omp.h>

using namespace std;

double average(double a[], int n) {
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i=0; i<n; i++) {
        sum += a[i];
    }

    return sum / n;
}

int main() {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = 5;

    cout << "Average: " << average(arr, n) << "\n";

    return 0;
}