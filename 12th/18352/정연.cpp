#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, x;
bool visited[300000];
vector<int> v[300000];
queue<int> q;
int depth[300000]={1};

void bfs(int start){
    q.push(start);
    visited[start]=true;
    
    while(!q.empty()){
        int cur = q.front();
        
        q.pop();
        for(int i=0; i< v[cur].size(); i++){
            int next = v[cur][i];
            if(!visited[next]){
                q.push(next);
                visited[next]=true;
                depth[next]=depth[cur]+1;
            }
        }
        
    }
    
}

int main()
{
    cin >> n >> m >> k >> x;
    
    int a, b;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
    }

    bfs(x);
    
    int flag =0;
    for(int i=1; i<=n; i++){
        if(depth[i]==k) {
            flag=1;
            cout << i <<"\n";
        }
    }
    
    if(flag == 0) cout <<"-1\n";
    
    return 0;
}