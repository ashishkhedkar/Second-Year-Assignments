/* Application: When playing card games, players often use an approach similar to insertion sort to organize their cards. 
They pick one card at a time and insert it into the correct position in their hand, maintaining a sorted sequence. 
Write a program that demonstrates how to organize (sort) cards in a hand using insertion sort. */


Program -

#include <iostream>
using namespace std;

int main()
{
    int cards[13], n, temp, i, j, k;

    cout << "Enter the number of Cards (1-13): ";
    cin >> n;

    // Input
    cout << "\nEnter the card values (1-13): ";
    for (i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    // Insertion Sort - Organising Cards in Hand
    cout << "\n\n========== ORGANISING CARDS IN HAND ==========\n";

    for (i = 1; i < n; i++)
    {
        temp = cards[i];
        j = i - 1;

        cout << "\nPass " << i << ": Picking up card " << temp;

        while (j >= 0 && cards[j] > temp)
        {
            cards[j + 1] = cards[j];
            j--;
        }

        cards[j + 1] = temp;

        cout << "\nInserting card " << temp << " into its position";
        cout << "\nHand: ";

        for (k = 0; k < n; k++)
        {
            cout << cards[k] << " ";
        }

        cout << endl;
    }

    // Final Sorted Output
    cout << "\n\n========== FINAL HAND ==========\n";
    cout << "Organised Cards: ";

    for (i = 0; i < n; i++)
    {
        cout << cards[i] << " ";
    }

    cout << "\n\nCards successfully organised in hand!" << endl;

    return 0;
}

