#include <bits/stdc++.h>

using namespace std;

int G[10][10];
bool edge_visited[10][10];
bool vertex_visited[10];
int minAns = INT_MAX;
int N, M;
vector<int> V;

void DFS(int index, int cost){
    vertex_visited[index] = true;

    int flag = 0;
    for(int i=1;i<=N;i++){
        if(!vertex_visited[i]) flag = 1;
    }
    if(flag == 0) {
        printf("cost = %d\n", cost);
        vertex_visited[index] = false;
        minAns = min(minAns, cost);
        return;
    }

    for(int i=1;i<=N;i++){
        if(G[index][i] != 0){
            if(edge_visited[index][i] || vertex_visited[i]) continue;
            edge_visited[index][i] = true;
            DFS(i, cost + G[index][i]);
            edge_visited[index][i] = false;
        }
    }
}

int main(){

    scanf("%d %d", &N, &M);

    for(int i=0;i<M;i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        G[u][v] = c;
    }
    for(int i=1;i<=N;i++){
        DFS(i, 0);
        printf("///////////\n");
    }
    printf("%d\n", minAns);


    return 0;
}