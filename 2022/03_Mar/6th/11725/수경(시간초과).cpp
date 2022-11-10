#include <bits/stdc++.h>

using namespace std;


int N;
int tree[100001];
vector <pair<int, int>> V;   //first :노드 번호, second: 부모 번호.
bool visited[100001];
queue <pair<int, int>> Q;

void makeTree() {
    Q.push(make_pair(1, 1));
    while (!Q.empty()) {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();

        for (int i = 0; i < V.size(); i++) {
            if (visited[i] == false) {
                if (V[i].first == b || V[i].second == b || V[i].first == a || V[i].second == a) {
                    Q.push(V[i]);
                    visited[i] = true;
                    i--;
                }
            }
        }
        if (a == 1) tree[b] = 1;
        if (b == 1) tree[a] = 1;

        else {
            if (tree[a] > 0) tree[b] = a;
            else if (tree[b] > 0) tree[a] = b;
            else Q.push(make_pair(a, b));
        }

    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        V.push_back(make_pair(a, b));
    }

    makeTree();

    for (int i = 2; i <= N; i++) {
        printf("%d\n", tree[i]);
    }

    return 0;
}