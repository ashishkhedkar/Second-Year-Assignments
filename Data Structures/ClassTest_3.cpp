// Split a Linked List into two halves
// Hare and Tortoise Method
// TC = O(N)
// SC = O(1)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;

    // Add node at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Split list into two halves using Fast & Slow Pointers (1-Pass Optimization)
    void split(Node*& head1, Node*& head2) {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            head1 = head;
            head2 = nullptr;
            return;
        }

        Node* slow = head;
        Node* fast = head->next; // Starting fast 1 step ahead gives standard left-leaning split

        // Advance fast by 2 steps and slow by 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        head1 = head;            // First half starts at head
        head2 = slow->next;      // Second half starts after slow pointer
        slow->next = nullptr;    // Sever the connection
    }

    // Helper to print any list
    static void print(Node* node) {
        if (node == nullptr) {
            cout << "NULL\n";
            return;
        }
        while (node != nullptr) {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int n, value;

    cout << "How many nodes? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter node " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    Node *firstHalf = nullptr, *secondHalf = nullptr;
    list.split(firstHalf, secondHalf);

    cout << "\nFirst Half:  "; LinkedList::print(firstHalf);
    cout << "Second Half: "; LinkedList::print(secondHalf);

    return 0;
}
