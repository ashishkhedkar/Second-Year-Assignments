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
        next = NULL;
    }
};

void split(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL || head->next == NULL) {
        head1 = head;
        head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    head1 = head;
    head2 = slow->next;
    slow->next = NULL;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node *head = NULL, *temp = NULL;
    Node *head1, *head2;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);

        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    split(head, head1, head2);

    cout << "First half: ";
    print(head1);

    cout << "Second half: ";
    print(head2);

    return 0;
}
