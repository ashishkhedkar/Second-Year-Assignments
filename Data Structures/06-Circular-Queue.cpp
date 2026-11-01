
#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class CircularQueue {
    string arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(const string &job) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = job;
        cout << job << " added to the queue." << endl;
    }

    string dequeue() {
        if (isEmpty())
            return "";

        string job = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }

        return job;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice;
    string job;

    do {
        cout << "\n===== PRINT QUEUE =====" << endl;
        cout << "1. Add Print Job" << endl;
        cout << "2. Process Print Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter print job: ";
                cin >> job;
                q.enqueue(job);
                break;

            case 2:
                if (q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << q.dequeue() << " is processed." << endl;
                break;

            case 3:
                cout << "Print jobs: ";
                q.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}

