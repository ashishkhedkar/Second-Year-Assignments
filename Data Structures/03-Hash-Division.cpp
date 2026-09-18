/* For example, imagine you have a set of servers that handle requests for a web application. 
The key to load balancing is using the hash value of a client’s IP address or a request ID to determine which server should handle the request.
The hash function is typically designed so that the data is evenly distributed across the servers, ensuring that no single server is overloaded. 
Write a program of a load balancing system using hashing, where a basic hash table for mapping incoming requests to a set of servers. */


#include <iostream>
using namespace std;    

// Insert Function
void insertRequest(int HashTable[], int servers)
{
    int id;
    cout << "\nEnter Request ID: ";
    cin >> id;

    int loc = id % servers;
    int startLoc = loc;

    // Move to next location if slot is occupied (not -1 and not -2)
    while (HashTable[loc] != -1 && HashTable[loc] != -2)
    {
        cout << "Collision at Location " << loc << "! Moving to next location.\n";
        loc = (loc + 1) % servers;

        // Prevent infinite loop if table is full
        if (loc == startLoc)
        {
            cout << "Error: Server hash table is full! Cannot insert Request " << id << endl;
            return;
        }
    }

    HashTable[loc] = id;
    cout << "Request " << id << " --- Placed at Location " << loc << endl;
}

// Search Function
void searchRequest(int HashTable[], int servers)
{
    int id;
    cout << "\nEnter Request ID to search: ";
    cin >> id;

    int loc = id % servers;
    int startLoc = loc;

    // Continue probing through tombstones (-2), stop only on truly unallocated slots (-1)
    while (HashTable[loc] != -1)
    {
        if (HashTable[loc] == id)
        {
            // Case 1: Key at proper hash index
            if (loc == startLoc)
            {
                cout << "Case 1: Request ID " << id << " found at proper index " << loc << endl;
            }
            // Case 2: Key found at a probed (non-original) index
            else
            {
                cout << "Case 2: Request ID " << id << " found at probed index " << loc << endl;
            }
            return;
        }

        loc = (loc + 1) % servers;

        if (loc == startLoc)
        {
            break;
        }
    }

    // Case 3: Key does not exist
    cout << "Case 3: Request ID " << id << " does not exist in the server Hash Table!" << endl;
}

// Delete Function (Using -2 as Tombstone)
void deleteRequest(int HashTable[], int servers)
{
    int id;
    cout << "\nEnter Request ID to delete: ";
    cin >> id;

    int loc = id % servers;
    int startLoc = loc;

    while (HashTable[loc] != -1)
    {
        if (HashTable[loc] == id)
        {
            HashTable[loc] = -2; // Mark as deleted (tombstone)
            cout << "Client ID " << id << " deleted since work was completed." << endl;
            return;
        }

        loc = (loc + 1) % servers;

        if (loc == startLoc)
        {
            break;
        }
    }

    cout << "Deletion Failed: Request ID " << id << " not found!" << endl;
}

// Display Function
void displayTable(int HashTable[], int servers)
{
    cout << "\n----- Server Hash Table Status -----\n";
    cout << "Index\t\tRequest ID\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < servers; i++)
    {
        if (HashTable[i] == -1)
        {
            cout << i << "\t\t[ Empty ]\n";
        }
        else if (HashTable[i] == -2)
        {
            cout << i << "\t\t[ Deleted ]\n";
        }
        else
        {
            cout << i << "\t\t" << HashTable[i] << "\n";
        }
    }
}

int main()
{
    int servers = 10;
    cout << "Enter number of servers: ";
    cin >> servers;

    int HashTable[100];

    // Mark all locations as empty (-1)
    for (int i = 0; i < servers; i++)
    {
        HashTable[i] = -1;
    }

    int choice = 0;
    while (choice != 5)
    {
        cout << " \n----- Managing Servers using Hash Table ----- " << endl;
        cout << "1. Input Request (Insert)" << endl;
        cout << "2. Search Request" << endl;
        cout << "3. Delete Request" << endl;
        cout << "4. Display Final Status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertRequest(HashTable, servers);
                break;
            case 2:
                searchRequest(HashTable, servers);
                break;
            case 3:
                deleteRequest(HashTable, servers);
                break;
            case 4:
                displayTable(HashTable, servers);
                break;           
            case 5:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}


