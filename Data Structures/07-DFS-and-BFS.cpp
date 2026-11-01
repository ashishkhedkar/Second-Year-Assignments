


#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX 20

class WebCrawler {
    int adj[MAX][MAX], n;
    string url[MAX];

public:
    WebCrawler(int n) {
        this->n = n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void setURL(int i, string u) {
        url[i] = u;
    }

    void addLink(int from, int to) {
        adj[from][to] = 1;
    }

    void BFS(int start) {
        bool visited[MAX] = {false};
        queue<pair<int, int>> q;

        q.push({start, 0});
        visited[start] = true;

        cout << "\nBFS Traversal:\n";

        while (!q.empty()) {
            int node = q.front().first;
            int depth = q.front().second;
            q.pop();

            cout << "Depth " << depth << ": "
                 << url[node] << endl;

            for (int i = 0; i < n; i++) {
                if (adj[node][i] && !visited[i]) {
                    visited[i] = true;
                    q.push({i, depth + 1});
                }
            }
        }
    }

    void DFSUtil(int node, int depth, bool visited[]) {
        visited[node] = true;

        cout << "Depth " << depth << ": "
             << url[node] << endl;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i])
                DFSUtil(i, depth + 1, visited);
        }
    }

    void DFS(int start) {
        bool visited[MAX] = {false};

        cout << "\nDFS Traversal:\n";
        DFSUtil(start, 0, visited);
    }
};

int main() {
    WebCrawler w(6);

    w.setURL(0, "college.edu/home");
    w.setURL(1, "college.edu/departments");
    w.setURL(2, "college.edu/admissions");
    w.setURL(3, "college.edu/comp-sci");
    w.setURL(4, "college.edu/fees");
    w.setURL(5, "college.edu/faculty");

    w.addLink(0, 1);
    w.addLink(0, 2);
    w.addLink(1, 3);
    w.addLink(2, 4);
    w.addLink(3, 5);
    w.addLink(4, 0);
    w.addLink(1, 2);

    int choice;

    do {
        cout << "\n1. BFS\n2. DFS\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                w.BFS(0);
                break;
            case 2:
                w.DFS(0);
                break;
            case 3:
                cout << "Exiting Web Crawler.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}

