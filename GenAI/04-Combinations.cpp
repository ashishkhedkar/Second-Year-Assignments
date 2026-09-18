#include <iostream>
#include <string>

using namespace std;

// Factorial function
long long fac(int num) {
    long long result = 1;

    for (int i = 1; i <= num; i++) {
        result *= i;
    }

    return result;
}

// Power function
long long power(int base, int exp) {
    long long result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

// Combination function (nCr)
long long combination(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    return fac(n) / (fac(r) * fac(n - r));
}

// Recursive function to generate combinations
void generate(string elements[], string data[], int n, int r, int index, int start) {

    // Print the combination when r elements are selected
    if (index == r) {
        cout << "{ ";

        for (int j = 0; j < r; j++) {
            cout << data[j] << " ";
        }

        cout << "}\n";
        return;
    }

    // Select elements one by one
    for (int i = start; i < n; i++) {
        data[index] = elements[i];

        // Recursively select the next element
        generate(elements, data, n, r, index + 1, i + 1);
    }
}

int main() {
    int choice;

    // Display the menu
    cout << "MENU:\n";
    cout << "1. Generate Combinations\n";
    cout << "2. Permutation Formulas (With/Without Repetition)\n";
    cout << "3. Problem Solving: Committee Selection\n";
    cout << "Enter choice: ";
    cin >> choice;

    // Generate combinations
    if (choice == 1) {
        int n, r;

        cout << "Enter n: ";
        cin >> n;

        cout << "Enter r: ";
        cin >> r;

        // Check whether r is valid
        if (r < 0 || r > n) {
            cout << "Invalid values of n and r!\n";
            return 0;
        }

        string elements[100];
        string data[100];

        // Take elements from the user
        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++) {
            cin >> elements[i];
        }

        // Calculate and display total combinations
        cout << "\nTotal Count (nCr) = "
             << combination(n, r) << "\n";

        // Generate all possible combinations
        cout << "Generated Sets:\n";
        generate(elements, data, n, r, 0, 0);
    }

    // Display permutation formulas
    else if (choice == 2) {
        int n, r;

        cout << "Enter n: ";
        cin >> n;

        cout << "Enter r: ";
        cin >> r;

        // Check whether r is valid
        if (r < 0 || r > n) {
            cout << "Invalid values of n and r!\n";
            return 0;
        }

        // Calculate permutations with repetition
        cout << "Permutations WITH repetition (n^r) = "
             << power(n, r) << "\n";

        // Calculate permutations without repetition
        cout << "Permutations WITHOUT repetition (nPr) = "
             << fac(n) / fac(n - r) << "\n";
    }

    // Solve committee selection problem
    else if (choice == 3) {
        int n, r;

        cout << "\nCommittee Selection\n";

        cout << "Enter total number of people: ";
        cin >> n;

        cout << "Enter number of people in committee: ";
        cin >> r;

        // Check whether the committee size is valid
        if (r < 0 || r > n) {
            cout << "Invalid values of n and r!\n";
            return 0;
        }

        // Order does not matter when selecting a committee
        cout << "\nNumber of possible committees = "
             << combination(n, r) << "\n";

        char display;

        cout << "Do you want to display the committees? (y/n): ";
        cin >> display;

        // Display all possible committees if requested
        if (display == 'y' || display == 'Y') {
            string people[100];
            string committee[100];

            // Take names of the people
            cout << "Enter names of " << n << " people:\n";

            for (int i = 0; i < n; i++) {
                cin >> people[i];
            }

            // Generate all possible committees
            cout << "\nPossible Committees:\n";
            generate(people, committee, n, r, 0, 0);
        }
    }

    // Handle invalid menu choice
    else {
        cout << "Invalid Choice!\n";
    }

    return 0;
}
