#include <iostream>

using namespace std;

// Generates all combinations recursively
void generateCombinations(int idx, int start, int n, int r, const int arr[], int result[]) 
{
    if (idx == r) 
    {
        cout << "[ ";
        for (int i = 0; i < r; i++) 
        {
            cout << result[i] << " ";
        }
        cout << "]\n";
        return;
    }

    for (int i = start; i < n; i++) 
    {
        result[idx] = arr[i];
        generateCombinations(idx + 1, i + 1, n, r, arr, result);
    }
}

// Calculates factorial n!
long long factorial(int n) 
{
    if (n < 0) return 0;
    long long pro = 1;
    for (int i = 1; i <= n; i++) 
    {
        pro *= i;
    }
    return pro;
}

// Calculates nCr (Combinations)
long long combination(int n, int r) 
{
    if (r < 0 || r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() 
{
    int choice;

    // Variables declared outside switch to prevent jump errors
    int n, r;
    int arr[10];
    int result[10];
    long long c1, c2, c3, total;

    while (true) 
    {
        cout << "\n--- COMBINATIONS MENU ---\n";
        cout << "1. Print All Combinations\n";
        cout << "2. Calculate nCr (With and Without Repetition)\n";
        cout << "3. Select 5 Members (At least 3 Women from 7 W, 5 M)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "\nEnter n (total objects, max 10): ";
                cin >> n;
                cout << "Enter r (selected objects): ";
                cin >> r;

                if (r > n || n > 10 || r < 0) 
                {
                    cout << "Invalid input!\n";
                    break;
                }

                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) 
                {
                    cin >> arr[i];
                }

                cout << "\nCombinations (" << combination(n, r) << " total):\n";
                generateCombinations(0, 0, n, r, arr, result);
                break;

            case 2:
                cout << "\nEnter n: ";
                cin >> n;
                cout << "Enter r: ";
                cin >> r;

                if (r < 0) 
                {
                    cout << "Invalid input!\n";
                    break;
                }

                // Without repetition: C(n, r) = n! / (r! * (n - r)!)
                if (r <= n) 
                {
                    cout << "Without repetition C(" << n << ", " << r << ") = " 
                         << combination(n, r) << "\n";
                } 
                else 
                {
                    cout << "Without repetition C(" << n << ", " << r << ") = 0\n";
                }

                // With repetition: C'(n, r) = C(n + r - 1, r)
                if (n > 0) 
                {
                    cout << "With repetition C'(" << n << ", " << r << ")    = " 
                         << combination(n + r - 1, r) << "\n";
                } 
                else 
                {
                    cout << "With repetition C'(" << n << ", " << r << ")    = 0\n";
                }
                break;

            case 3:
                c1 = combination(7, 3) * combination(5, 2); // 3 Women, 2 Men
                c2 = combination(7, 4) * combination(5, 1); // 4 Women, 1 Man
                c3 = combination(7, 5) * combination(5, 0); // 5 Women, 0 Men
                total = c1 + c2 + c3;

                cout << "\n3 Women and 2 Men = " << c1 << "\n";
                cout << "4 Women and 1 Man = " << c2 << "\n";
                cout << "5 Women and 0 Men = " << c3 << "\n";
                cout << "Total combinations = " << total << "\n";
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
                break;
        }
    }

    return 0;
}
