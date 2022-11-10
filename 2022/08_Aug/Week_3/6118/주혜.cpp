#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAX = 20010;
vector<int> g[MAX];
int visited[MAX];
int parent[MAX];
int a,b;
queue<int> q;
int dis = -1;
vector<int> same_dis[MAX];

//숨바꼭질
//가장 거리가 먼 노드'들' 찾기
void go(){
    visited[1] = 1;
    q.push(1);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        vector<int>::iterator iter;

        for(iter = g[cur].begin(); iter != g[cur].end(); iter++){
            if(!visited[*iter]){
                visited[*iter] = visited[cur] + 1;
                q.push(*iter);
                same_dis[visited[cur] + 1].push_back(*iter);
            }
        }
    }

    // 헛간 리스트들 중 max값을 구하고, 같은 max값을 가진 헛간 번호들의 리스트와 개수를 알아야함. 
    for(int i=2; i < MAX; i++){
        dis = max(dis, visited[i]);
    }
    sort(same_dis[dis].begin(), same_dis[dis].end());
    cout << same_dis[dis][0] << " ";
    cout << dis - 1 << " ";
    cout << same_dis[dis].size() << endl; 

    /*
    cout << "\n";
    for(int i=0; i < same_dis[dis].size(); i++){
        cout << same_dis[dis][i] << " ";
    }
    */

}


int main(){
    cin >> n >> m;

    for(int i=0; i < m; i++){
        cin >> a >> b;
        //양방향으로 길이 나있다.
        g[a].push_back(b);
        g[b].push_back(a);
    }

    go();
}