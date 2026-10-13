#include <iostream>
#include <cmath>
using namespace std;

void analyzeGroup(string groupName, double arr[], int n) {
    // 1. Calculate Range
    double minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    double range = maxVal - minVal;

    // 2. Calculate Mean
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double mean = sum / n;

    // 3. Calculate Variance
    double sqDiffSum = 0;
    for (int i = 0; i < n; i++) {
        sqDiffSum += (arr[i] - mean) * (arr[i] - mean);
    }
    double variance = sqDiffSum / (n - 1);

    // 4. Calculate Standard Deviation
    double stdDev = sqrt(variance);

    // Output
    cout << "--- " << groupName << " ---" << endl;
    cout << "Mean               : " << mean << " hrs" << endl;
    cout << "Range              : " << range << " hrs" << endl;
    cout << "Variance          : " << variance << endl;
    cout << "Standard Deviation : " << stdDev << " hrs" << endl << endl;
}

int main() {
    double groupA[] = {6, 8, 7, 5, 6, 9, 7, 8};
    double groupB[] = {10, 12, 13, 11, 10, 9, 8, 14};

    cout << "--- Study Hours Dispersion Analysis ---" << endl;
    analyzeGroup("Group A", groupA, 8);
    analyzeGroup("Group B", groupB, 8);

    return 0;
}

