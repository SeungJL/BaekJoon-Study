#include <bits/stdc++.h>

using namespace std;
int N, M, V;
bool graph1[1001][1001];
bool vertices1[1001];

void DFS(int index) {
    if (!vertices1[index]) {
        printf("%d ", index);
        vertices1[index] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (graph1[index][i]) {
            graph1[index][i] = false;
            graph1[i][index] = false;
            if (!vertices1[i]) {  // 이 문장 추가했더니 11% -> 100% 됨
                DFS(i);
            }
        }
    }
}

bool graph2[1001][1001];
bool vertices2[1001];

void BFS() {
    queue<int> Q;
    Q.push(V);
    while (!Q.empty()) {

        int index = Q.front();
        printf("%d ", index);
        vertices2[index] = true;
        Q.pop();

        for (int i = 1; i <= N; i++) {
            if (graph2[index][i]) {
                if (!vertices2[i]) {
                    Q.push(i);
                    vertices2[i] = true;
                }
                graph2[index][i] = false;
                graph2[i][index] = false;

            }
        }
    }

}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph1[a][b] = true;
        graph1[b][a] = true;

        graph2[a][b] = true;
        graph2[b][a] = true;
    }
    DFS(V);
    printf("\n");
    BFS();
    return 0;
}