#include <iostream>
#include <omp.h>
#include <random>

using namespace std;

double calculatePi(int pointsInRectangle) {
    int pointsInCircle = 0;

    #pragma omp parallel
    {
        int numThreads = omp_get_num_threads();
        int threadIndex = omp_get_thread_num();

        // Generator liczb z unikalnym ziarnem
        mt19937_64 rng;
        rng.seed(static_cast<unsigned>(time(nullptr)) + threadIndex);
        uniform_real_distribution<double> dist(0.0, 1.0);

        // Podział pracy
        int pointsPerThread = pointsInCircle / numThreads;
        int start = pointsPerThread * threadIndex;
        int end = (threadIndex == numThreads -1) ? pointsInRectangle : start + pointsPerThread;

        // Wyznaczanie punktów
        int localPointsInCircle = 0;
        for (int i=start; i < end; i++) {
            double x = dist(rng);
            double y = dist(rng);

            if (x*x + y*y <= 1.0) localPointsInCircle++;
        }

        // Aktualizacja globalnej zmiennej
        #pragma omp atomit
        pointsInCircle += localPointsInCircle;
    }

    // Wzór Monte Carlo
    return 4.0 * static_cast<double>(pointsInCircle) / pointsInRectangle;
}

int main() {
    int totalPoints = 1000000;

    cout << "Liczba Pi: " << calculatePi(totalPoints) << "\n";

    return 0;
}