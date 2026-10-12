#include <iostream>
using namespace std;

int main() {
    int n;
    int reach[10][10];

    cout << "Enter number of vertices (max 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Invalid number of vertices";
        return 0;
    }

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> reach[i][j];
        }
    }

    // Apply Warshall's Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] ||
                              (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Display the transitive closure
    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
