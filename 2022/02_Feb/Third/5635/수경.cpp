#include <bits/stdc++.h>

using namespace std;

typedef struct Student {
    string name;
    int month;
    int day;
    int year;
} Student;

bool compare(Student A, Student B) {
    if (A.year == B.year) {
        if (A.month == B.month) {
            return A.day > B.day;
        }
        return A.month > B.month;
    }
    return A.year > B.year;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Student *students = new Student[n];
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].day >> students[i].month >> students[i].year;
    }
    sort(students, students + n, compare);

    cout << students[0].name << '\n' << students[n - 1].name;
    return 0;
}