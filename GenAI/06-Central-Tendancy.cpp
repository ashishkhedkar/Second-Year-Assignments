
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int scores[n];
    cout << "Enter " << n << " scores: ";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    // 1. Calculate Mean
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    double mean = sum / n;

    // 2. Sort scores and Calculate Median
    sort(scores, scores + n);
    double median;
    if (n % 2 == 0) {
        median = (scores[n/2 - 1] + scores[n/2]) / 2.0;
    } else {
        median = scores[n/2];
    }

    // 3. Calculate Mode
    int mode = scores[0], maxCount = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (scores[j] == scores[i]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = scores[i];
        }
    }

    // Output
    cout << "\n--- Student Scores Analysis ---" << endl;
    cout << "Sorted Scores: ";
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    cout << "Mean         : " << mean << endl;
    cout << "Median       : " << median << endl;
    cout << "Mode         : " << mode << " (Appears " << maxCount << " times)" << endl;

    return 0;
}
