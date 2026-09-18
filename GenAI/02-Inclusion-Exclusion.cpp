#include <iostream>
using namespace std;

const int maxvalue = 100;

void accept(int arr[], int &size, const string &name) {
    cout << "Enter number of students in " << name << ": " << endl;
    cin >> size;
    cout << "Enter roll numbers: " << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void display(const int arr[], int size, const string &title) {
    if (size == 0) {
        cout << "None";
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

bool contains(const int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

void find_intersection(int A[], int sizeA, int B[], int sizeB, int result[], int &result_size) {
    result_size = 0;

    for (int i = 0; i < sizeA; i++) {
        if (contains(B, sizeB, A[i])) {
            result[result_size++] = A[i];
        }
    }
}

void find_union(int A[], int sizeA, int B[], int sizeB, int result[], int &result_size) {
    result_size = 0;

    for (int i = 0; i < sizeA; i++) {
        result[result_size++] = A[i];
    }

    for (int i = 0; i < sizeB; i++) {
        if (!contains(A, sizeA, B[i])) {
            result[result_size++] = B[i];
        }
    }
}

void find_difference(int A[], int sizeA, int B[], int sizeB, int result[], int &result_size) {
    result_size = 0;

    for (int i = 0; i < sizeA; i++) {
        if (!contains(B, sizeB, A[i])) {
            result[result_size++] = A[i];
        }
    }
}

void find_neither(int allStudents[], int totalStudents, int unionSet[], int unionSize, int result[], int &result_size) {
    result_size = 0;

    for (int i = 0; i < totalStudents; i++) {
        if (!contains(unionSet, unionSize, allStudents[i]))
            result[result_size++] = allStudents[i];
    }
}

int main() {
    int allstudents[maxvalue], sports[maxvalue], music[maxvalue];
    int both[maxvalue], either[maxvalue];
    int sports_only[maxvalue], music_only[maxvalue], neither[maxvalue];

    int total_students;
    int sports_count, music_count;
    int both_count, either_count;
    int sports_only_count, music_only_count, neither_count;

    cout << "Enter total number of students: " << endl;
    cin >> total_students;

    cout << "Enter roll numbers of all students: " << endl;

    for (int i = 0; i < total_students; i++) {
        cin >> allstudents[i];
    }

    accept(sports, sports_count, "Sports Club");
    accept(music, music_count, "Music Club");

    find_intersection(sports, sports_count, music, music_count, both, both_count);
    find_union(sports, sports_count, music, music_count, either, either_count);
    find_difference(sports, sports_count, music, music_count, sports_only, sports_only_count);
    find_difference(music, music_count, sports, sports_count, music_only, music_only_count);
    find_neither(allstudents, total_students, either, either_count, neither, neither_count);

    cout << "Students in at least one club : " << either_count << endl;
    cout << "Students only in Sports Club : " << sports_only_count << endl;
    cout << "Students only in Music Club : " << music_only_count << endl;
    cout << "Students in neither club : " << neither_count << endl;

    return 0;
}



