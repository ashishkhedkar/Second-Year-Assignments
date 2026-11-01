
#include <iostream>
#include <string>
using namespace std;

template <class T>
void sortArray(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice, n;

    cout << "1. Integer Array\n";
    cout << "2. Float Array\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid size";
        return 0;
    }

    if (choice == 1) {
        int arr[100];

        cout << "Enter integers: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sortArray(arr, n);
    }
    else {
        float arr[100];
        string x;

        cout << "Enter float values: ";
        for (int i = 0; i < n; i++) {
            cin >> x;

            if (x.find('.') == string::npos) {
                cout << "Enter decimal values only!";
                return 0;
            }

            arr[i] = stof(x);
        }

        sortArray(arr, n);
    }

    return 0;
}

