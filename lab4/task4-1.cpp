#include <iostream>
#include <omp.h>
#include <random>

using namespace std;

int main() {

    // Podanie wielkości tablic
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n <=0) {
        cerr << "Array size must be greater than zero!\n";
        return 1;
    }

    // Definiowanie tablic
    int* a = new int[n];
    int* b = new int[n];

    // Blok równoległy
    #pragma omp parallel
    {
        int threadNum = omp_get_thread_num();

        // Inicjacja generatora liczb losowych
    mt19937_64 rng;
    rng.seed(static_cast<unsigned>(time(nullptr)) + threadNum);
    uniform_int_distribution<int> dist(0, 10);

        // Wypełnianie tablic
        #pragma omp for schedule(static, 5)
        for (int i=0; i<n; i++) {
            a[i] = threadNum;
            b[i] = dist(rng);
        }

        // Sumowanie tablic
        #pragma omp for schedule(static, 5)
        for (int i=0; i<n; i++) {
            a[i] += b[i];
        }
    }

    // Wyniki
    cout << "\nArray a:\n";
    for (int i=0; i<n; i++) cout << a[i] << " ";

    cout << "\nArray b:\n";
    for (int i=0; i<n; i++) cout << b[i] << " ";

    delete[] a;
    delete[] b;

    return 0;
}