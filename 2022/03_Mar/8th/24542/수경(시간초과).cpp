#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> V;
int N, M;

int solve() {
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < V.size(); j++) {
            if (V[j].first == i || V[j].second == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) continue;

        queue<int> Q;   //정점의 번호
        Q.push(i);
        int size = 0;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            size++;
            for (int j = 0; j < V.size(); j++) {
                if (V[j].first == cur) {
                    Q.push(V[j].second);
                    V.erase(V.begin() + j);
                    j--;
                }
                else if (V[j].second == cur) {
                    Q.push(V[j].first);
                    V.erase(V.begin() + j);
                    j--;
                }
            }
        }
        ans *= size % 1000000007;

    }
    return ans;
}


int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        V.push_back(make_pair(a, b));
    }

    printf("%d", solve());
    return 0;
}