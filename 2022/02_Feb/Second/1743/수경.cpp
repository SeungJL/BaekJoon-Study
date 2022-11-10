#include <bits/stdc++.h>

using namespace std;

int N, M, K;

vector <pair<int, int>> v;
vector <pair<int, int>> q;

bool isNext(pair<int, int> a, pair<int, int> b) {
    if (abs(a.first - b.first) + abs(a.second - b.second) == 1) return true;
    return false;
}

int solve() {
    int max_size = 0;
    int tmp_size = 0;

    //v, q에 원소가 하나라도 남아있으면 계속 반복
    while (!v.empty() || !q.empty()) {

        //v에는 원소가 남아있는데 q가 비었으면
        if (!v.empty() && q.empty()) {
            //새로운 음식물 덩어리를 만들어야하기 때문에
            //최대값보다 크면 최대값에 방금 모였던 음식물 덩어리 크기 저장해주고
            if (max_size < tmp_size) max_size = tmp_size;

            //tmp는 0으로 바꾸기. 새로운 음식물 덩어리를 만들기 위해
            tmp_size = 0;

            //q에 새로운 음식물 덩어리를 만들기 위한 시작 원소를 충전
            q.push_back(v.front());
            //v에서는 삭제.
            v.erase(v.begin());
        }

        //q에서 front를 pop 할 때마다 tmp_size 증가
        pair<int, int> tmp = q.front();
        q.erase(q.begin());
        tmp_size++;

        //q의 front에서 뽑은 음식물 시작 원소(tmp)와 맞닿아있는 모든 원소들을 v에서 q로 이동
        for (vector < pair < int, int >> ::iterator it = v.begin(); it != v.end();) {
            if (isNext(tmp, *it)) {
                q.push_back(*it);
                v.erase(it);
            } else it++;
        }
    }

    //반복이 끝나고 최대값보다 마지막에 계산한 음식물 덩어리 크기가 크면 바꿔주고
    if (max_size < tmp_size) max_size = tmp_size;

    //최대값 return
    return max_size;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        //vector에 음식물이 있는 index를 저장
        v.push_back(make_pair(r - 1, c - 1));
    }

    int result = solve();
    printf("%d\n", result);

    return 0;
}