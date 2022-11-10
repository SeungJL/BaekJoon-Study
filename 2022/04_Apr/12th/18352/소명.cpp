//18352번: 특정 거리의 도시 찾기

/*
도시 갯수 N 2<=N<=300,000
도로 갯수 M 1<=M<=1,000,000
거리 정보 K 1<=K<=300,000
출발 도시 번호 X 1<=X<=N

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,k,x; //k: 거리정보, x: 출발도시번호
vector<int> vec[300001];
int dist[300001];
vector<int> answer;
queue<int> q;

void bfs(){
    dist[x]=0;
    q.push(x);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0;i<vec[cur].size(); i++){
            int next=vec[cur][i];
            if(dist[next]==-1){
                dist[next]=dist[cur]+1;
                q.push(next);
            }
        }
    }
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k>>x;
    for(int i=1; i<=n; i++){
        dist[i]=-1;
    }

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
    }

    bfs();
    for(int i=1; i<=n; i++){
        if(dist[i]==k)
         answer.push_back(i);
    }

    sort(answer.begin(), answer.end());
    
    if(answer.size()==0)
        cout<<-1<<"\n";
    else{
        for(int i=0; i<answer.size(); i++){
            cout<<answer[i]<<"\n";
        }
    }
}