#include <iostream>
using namespace std;

int main() {
    int A[] = {6, 8, 7, 5, 6, 9, 7, 8};
    int B[] = {10, 12, 13, 11, 10, 9, 8, 14};

    int n = 8;
    double sum, mean, variance, sd;
    int min, max, range;

    cout << "--- Study Hours Dispersion Analysis ---\n";

    // Group A
    sum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    mean = sum / n;
    min = max = A[0];
    variance = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];

        double d = A[i] - mean;
        variance += d * d;
    }

    range = max - min;
    variance /= n;

    // Calculate standard deviation without cmath
    double x = variance;

    if (x > 0) {
        double y = 1;

        while (x - y > 0.000001 || y - x > 0.000001) {
            x = (x + y) / 2;
            y = variance / x;
        }

        sd = x;
    } else {
        sd = 0;
    }

    cout << "\n--- Group A ---\n";
    cout << "Mean                : " << mean << " hrs\n";
    cout << "Range               : " << range << " hrs\n";
    cout << "Variance            : " << variance << endl;
    cout << "Standard Deviation  : " << sd << " hrs\n";

    // Group B
    sum = 0;

    for (int i = 0; i < n; i++) {
        sum += B[i];
    }

    mean = sum / n;
    min = max = B[0];
    variance = 0;

    for (int i = 0; i < n; i++) {
        if (B[i] < min) min = B[i];
        if (B[i] > max) max = B[i];

        double d = B[i] - mean;
        variance += d * d;
    }

    range = max - min;
    variance /= n;

    // Calculate standard deviation without cmath
    x = variance;

    if (x > 0) {
        double y = 1;

        while (x - y > 0.000001 || y - x > 0.000001) {
            x = (x + y) / 2;
            y = variance / x;
        }

        sd = x;
    } else {
        sd = 0;
    }

    cout << "\n--- Group B ---\n";
    cout << "Mean                : " << mean << " hrs\n";
    cout << "Range               : " << range << " hrs\n";
    cout << "Variance            : " << variance << endl;
    cout << "Standard Deviation  : " << sd << " hrs\n";

    return 0;
}

   
