/* Write a game development program that implements the Bubble Sort algorithm. 
The program will simulate a simple game where the player can input a set of numbers, and the numbers wi
will be sorted using Bubble Sort to simulate a "level-up" scenario where the player's scores are
sorted in ascending order. */


#include <iostream>

using namespace std;

int main()
{
    int i, j, n, temp;

    cout << "Enter the number of scores for each player: ";
    cin >> n;

    int player1[n];
    int player2[n];

    // Input Player 1
    cout << "\nEnter scores for Player 1:" << endl;

    for (i = 0; i < n; i++)
    {
        cout << "Score " << i + 1 << ": ";
        cin >> player1[i];
    }

    // Input Player 2
    cout << "\nEnter scores for Player 2:" << endl;

    for (i = 0; i < n; i++)
    {
        cout << "Score " << i + 1 << ": ";
        cin >> player2[i];
    }

    // Bubble Sort Player 1
    cout << "\n\n========== PLAYER 1 SORTING ==========" << endl;

    for (i = 0; i < n - 1; i++)
    {
        cout << "\nPass " << i + 1 << ":" << endl;

        for (j = 0; j < n - i - 1; j++)
        {
            if (player1[j] > player1[j + 1])
            {
                cout << "Swapping " << player1[j]
                     << " with " << player1[j + 1]
                     << ", levelling up!" << endl;

                temp = player1[j];
                player1[j] = player1[j + 1];
                player1[j + 1] = temp;
            }
        }
    }

    // Bubble Sort Player 2
    cout << "\n\n========== PLAYER 2 SORTING ==========" << endl;

    for (i = 0; i < n - 1; i++)
    {
        cout << "\nPass " << i + 1 << ":" << endl;

        for (j = 0; j < n - i - 1; j++)
        {
            if (player2[j] > player2[j + 1])
            {
                cout << "Swapping " << player2[j]
                     << " with " << player2[j + 1]
                     << ", levelling up!" << endl;

                temp = player2[j];
                player2[j] = player2[j + 1];
                player2[j + 1] = temp;
            }
        }
    }

    // Final Sorted Output
    cout << "\n\nPlayer 1 Ranked Scores: ";

    for (i = n - 1; i >= 0; i--)
    {
        cout << player1[i] << " ";
    }

    cout << "\nPlayer 2 Ranked Scores: ";

    for (i = n - 1; i >= 0; i--)
    {
        cout << player2[i] << " ";
    }

    // Calculate totals
    int total1 = 0;
    int total2 = 0;

    for (i = 0; i < n; i++)
    {
        total1 += player1[i];
        total2 += player2[i];
    }

    cout << "\n\nPlayer 1 Total Score: " << total1;
    cout << "\nPlayer 2 Total Score: " << total2;

    // Winner
    if (total1 > total2)
    {
        cout << "\n\nWinner: Player 1";
    }
    else if (total2 > total1)
    {
        cout << "\n\nWinner: Player 2";
    }
    else
    {
        cout << "\n\nResult: It's a Tie!";
    }

    return 0;
}


