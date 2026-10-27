#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students." << endl;
        return 0;
    }

    int scores[n];
    cout << "Enter " << n << " integer scores: ";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    // 1. Calculate Mean (Casting sum to double preserves decimal averages)
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    double mean = (double)sum / n;

    // 2. Sort scores and Calculate Median
    sort(scores, scores + n);
    double median;
    if (n % 2 == 0) {
        median = (scores[n / 2 - 1] + scores[n / 2]) / 2.0;
    } else {
        median = scores[n / 2];
    }

    // 3. Find Highest Frequency using direct integer equality
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (scores[j] == scores[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }

    // 4. Store Unique Modes in an Integer Array
    int modes[n];
    int modeCount = 0;

    for (int i = 0; i < n; i++) {
        // Skip duplicate values in sorted array
        if (i == 0 || scores[i] != scores[i - 1]) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (scores[j] == scores[i]) {
                    count++;
                }
            }
            if (count == maxCount) {
                modes[modeCount] = scores[i];
                modeCount++;
            }
        }
    }

    // Output Results
    cout << "\n--- Student Scores Analysis ---" << endl;
    cout << "Sorted Scores: ";
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl << endl;

    cout << "Mean   : " << mean << endl;
    cout << "Median : " << median << endl;

    // Determine Modality
    if (maxCount == 1 && n > 1) {
        cout << "Mode   : No Mode (All values appear exactly once)" << endl;
    } else if (modeCount == 1) {
        cout << "Mode   : " << modes[0] << " (Unimodal, appears " << maxCount << " times)" << endl;
    } else if (modeCount == 2) {
        cout << "Mode   : " << modes[0] << ", " << modes[1] 
             << " (Bimodal, appear " << maxCount << " times each)" << endl;
    } else {
        cout << "Mode   : ";
        for (int i = 0; i < modeCount; i++) {
            cout << modes[i] << (i + 1 < modeCount ? ", " : "");
        }
        cout << " (Multimodal, appear " << maxCount << " times each)" << endl;
    }
return 0;
}
