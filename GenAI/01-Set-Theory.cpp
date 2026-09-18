#include <iostream>
using namespace std;

int main()
{
    int A[10], B[10];
    int n1, n2;

    cout << "Enter number of students in Drama Club: ";
    cin >> n1;

    cout << "Enter student roll numbers: ";
    for (int i = 0; i < n1; i++)
        cin >> A[i];

    cout << "Enter number of students in Science Club: ";
    cin >> n2;

    cout << "Enter student roll numbers: ";
    for (int i = 0; i < n2; i++)
        cin >> B[i];

    // Students in at least one club (Union)
    cout << "\nStudents in at least one club: ";
    for (int i = 0; i < n1; i++)
        cout << A[i] << " ";

    for (int i = 0; i < n2; i++)
    {
        bool found = false;

        for (int j = 0; j < n1; j++)
        {
            if (B[i] == A[j])
            {
                found = true;
                break;
   
         }

        }

        if (!found)
            cout << B[i] << " ";
    }

    // Students in both clubs (Intersection)
    cout << "\nStudents in both clubs: ";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (A[i] == B[j])
            {
                cout << A[i] << " ";
                break;
            }
        }
    }

    // Drama but not Science (A-B)
    cout << "\nDrama but not Science: ";
    for (int i = 0; i < n1; i++)
    {
        bool found = false;

        for (int j = 0; j < n2; j++)
        {
            if (A[i] == B[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
            cout << A[i] << " ";
    }

    // Science but not Drama (B-A)
    cout << "\nScience but not Drama: ";
    for (int i = 0; i < n2; i++)
    {
        bool found = false;

        for (int j = 0; j < n1; j++)
        {
            if (B[i] == A[j])

            {
                found = true;

                break;
            }
        }

        if (!found)
            cout << B[i] << " ";
    }

    return 0;
}




