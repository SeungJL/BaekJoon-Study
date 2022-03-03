#include <bits/stdc++.h>

using namespace std;

/*
 * deque 사용
 *
 * 양수일 경우)
 * → tmp - 1(매 반복문마다 1회 수행하기 때문에)만큼
 * 덱의 맨 앞 원소를 맨 뒤에 push하고 pop.
 *
 * 음수일 경우)
 * → tmp만큼 덱의 맨 뒤 원소를 맨 앞에 push하고 pop.
 */

int main() {
    int N;
    cin >> N;
    deque <pair<int, int>> balloon;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        balloon.push_back(make_pair(i + 1, tmp));
    }

    while (!balloon.empty()) {
        cout << balloon.front().first << " ";
        int tmp = balloon.front().second;
        balloon.pop_front();
        if (tmp > 0) {
            for (int i = 0; i < tmp - 1; i++) {
                balloon.push_back(balloon.front());
                balloon.pop_front();
            }
        } else if (tmp < 0) {
            tmp *= -1;
            for (int i = 0; i < tmp; i++) {
                balloon.push_front(balloon.back());
                balloon.pop_back();
            }
        }
    }
    return 0;
}