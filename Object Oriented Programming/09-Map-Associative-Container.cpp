
#include <iostream>
#include <map>
#include <string> 
using namespace std;

int main() {
    map<int, string> student;
    int n, prn, search_prn;
    string name;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter PRN: "; 
        cin >> prn;
        cout << "Enter student name: ";
        cin >> name;
        student[prn] = name;
    }

    cout << "\nEnter PRN to search: ";
    cin >> search_prn;

       if (student.find(search_prn) != student.end()) {
        cout << "Student Name: " << student[search_prn] << endl;
    } else {
        cout << "Student not found!" << endl; 
    }

    return 0;
}
