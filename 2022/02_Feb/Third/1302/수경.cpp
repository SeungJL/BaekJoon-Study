#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> books;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        books.push_back(tmp);
    }

    sort(books.begin(), books.end());

    int max = 1;
    string max_book = books[0];

    int cnt = 1;
    for (int i = 0; i < N - 1; i++) {
        //printf("cnt=%d\n", cnt);
        if (books[i] != books[i + 1] || i == N - 2) {
            if (max < cnt) {
                max = cnt;
                max_book = books[i];
            }
            cnt = 1;
        } else cnt++;
    }

    cout << max_book;

    return 0;
}