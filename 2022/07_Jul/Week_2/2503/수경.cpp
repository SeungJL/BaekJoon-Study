#include <bits/stdc++.h>

using namespace std;

bool baseball[1000];

bool check(int num, int index, int strike, int ball) {
    int num_arr[3];
    num_arr[0] = num / 100;
    num_arr[1] = num / 10 % 10;
    num_arr[2] = num % 10;

    int index_arr[3];
    index_arr[0] = index / 100;
    index_arr[1] = index / 10 % 10;
    index_arr[2] = index % 10;

    int S = 0, B = 0;
    for (int i = 0; i < 3; i++) {
        // flag 1: strike, 2: ball
        int flag = 0;
        for (int j = 0; j < 3; j++) {
            if (num_arr[i] == index_arr[j]) {
                if (i == j) flag = 1;
                else flag = 2;
            }
        }
        if (flag == 1) S++;
        else if (flag == 2) B++;
    }
    if (S == strike && B == ball) return true;
    else return false;
}

int main() {
    for (int i = 123; i <= 987; i++) {
        int a, b, c;
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;

        // 0이 들어갔거나 중복된 숫자면 true
        if (a == b || b == c || c == a || a == 0 || b == 0 || c == 0) baseball[i] = true;
    }


    int N;
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        int strike, ball;
        cin >> strike >> ball;
        for (int i = 123; i <= 987; i++) {
            if(baseball[i] == true) continue;
            if (!check(num, i, strike, ball)) {
                baseball[i] = true;
                // strike, ball 수를 만족하면 false. 만족하지 않으면 true.
            }
        }
    }
    int cnt = 0;
    for (int i = 123; i <= 987; i++) {
        // true로 바꿔준 것들을 제외하고 false인 숫자의 수 세기
        if (!baseball[i]) cnt++;
    }

    cout << cnt;
    return 0;
}