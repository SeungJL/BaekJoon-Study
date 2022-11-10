#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int n, m , v;
int arr[1001][10001];
int visited[1001]={0};
int x, y;

void dfs(int v){
    visited[v]=1;
    cout << v << " ";
    
    for(int i=1; i<=n; i++){
        if(arr[v][i]==1 && !visited[i]){
            dfs(i);
        }
        else continue;
    }
    
}
void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v]=1;
    
    while(!q.empty()){
        int x = q.front();
        cout << x <<" ";
        q.pop();
        for(int i=1; i<=n; i++){
            if(arr[x][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=1;
            }
        else continue;
        }
    }
    
}

int main() {
    cin >> n >> m >> v;
    while(m--){
        cin >> x >> y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
    
    dfs(v);
    cout <<"\n";
    
    memset(visited,0,sizeof(visited));
    
    bfs(v);
    
    return 0;
}