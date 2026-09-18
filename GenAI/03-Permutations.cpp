
#include <iostream>
using namespace std;

int arr[10], result[10], visit[20];
int n, r;

// Generate all possible permutations
void generatep(int index) {
    // If r elements are selected, print the result
    if (index == r) {
        for (int i = 0; i < r; i++)
            cout << result[i] << " ";
        cout << endl;
        return;
    }

    // Try every element at the current position
    for (int i = 0; i < n; i++) {
        if (visit[i] == 0) {
            result[index] = arr[i];
            visit[i] = 1;

            generatep(index + 1);

            // Backtrack and make the element available again
            visit[i] = 0;
        }
    }
}

int main() {
    cout << "Enter number of objects: " << endl;
    cin >> n;

    cout << "Enter number of selected objects: " << endl;
    cin >> r;

    // Check whether n and r are valid
    if (r > n || r <= 0 || n <= 0) {
        cout << "Invalid values of n and r" << endl;
        return 0;
    }

    cout << "Enter " << n << " distinct elements: " << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        visit[i] = 0;
    }

    cout << "All possible results of length " << r << ":\n";
    generatep(0);

    return 0;
}



