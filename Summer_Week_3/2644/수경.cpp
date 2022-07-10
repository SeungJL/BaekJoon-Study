#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int num;
    int parent;
    vector<int> child;
    int dis;    //촌수
} Node;

int n, m;
int a, b;
Node nodes[101];
bool visited[101];

int BFS() {
    queue<Node> Q;
    nodes[a].dis = 0;
    visited[a] = true;
    Q.push(nodes[a]);

    while (!Q.empty()) {
        Node cur = Q.front();
        Q.pop();

        // child
        for (int i = 0; i < cur.child.size(); i++) {
            if (visited[cur.child[i]]) continue;
            visited[cur.child[i]] = true;
            nodes[cur.child[i]].dis = cur.dis + 1;
            Q.push(nodes[cur.child[i]]);
        }

        // parent
        if (visited[cur.parent]) continue;
        visited[cur.parent] = true;
        nodes[cur.parent].dis = cur.dis + 1;
        Q.push(nodes[cur.parent]);
    }
    return nodes[b].dis;

}

int main() {
    cin >> n >> a >> b >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        // x 부모 y 자식
        nodes[x].num = x;
        nodes[x].child.push_back(y);

        nodes[y].num = y;
        nodes[y].parent = x;
    }

    int ans = BFS();
    if (ans == 0) cout << -1;
    else cout << ans;

    return 0;
}