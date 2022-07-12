#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;          // i의 부모 정보
vector<int> children[101];   // i의 자식 정보가 저장된 인접리스트
vector<bool> ch;             // i번째 노드의 검사 여부(dfs 호출 여부) 정보, true-이미 호출됨

/* x의 부모 또는 자식 중에 y가 있는지 체크하는 재귀함수
 *
 * x, y - x의 부모 또는 자식 중에 y가 있는지 검사 
 * cnt - count한 촌수
 *
 * x의 부모 또는 자식 중에 y가 있을 경우 count한 촌수를 return
 * 없을 경우 x의 부모와 자식을 새로운 x로 하여 재귀함수 호출 후 그 결과값을 return
 */
int DFS(int x, int y, int cnt) {
    // (x, y)가 1촌 관계일 경우
    if (parent[x] == y) return (cnt + 1); // y가 x의 부모일 경우
    for (auto c : children[x]) {
        if (c == y) return (cnt + 1);     // y가 x의 자식일 경우
    }

    int res = -1; // 촌수를 계산할 수 없을 경우 -1을 출력하므로 -1로 초기화
    // x의 부모를 새로운 x로 하여 재귀함수 호출
    if (parent[x] && !ch[parent[x]]) {
        ch[parent[x]] = true;
        res = DFS(parent[x], y, cnt + 1);
    }
    if (res != -1) 
        return (res);

    // x의 모든 자식들을 새로운 x로 하여 재귀함수 호출
    for (auto c : children[x]) {
        if (ch[c]) continue;
        ch[c] = true;
        res = DFS(c, y, cnt + 1);
        if (res != -1) 
            return (res);
    }

    return (res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int n, x, y, m;
    cin >> n >> x >> y >> m;

    for (int i=0; i<=n; i++) {
        parent.push_back(0);
        ch.push_back(false);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        parent[b] = a;
        children[a].push_back(b);
    }

    cout << DFS(x, y, 0) << "\n";
}