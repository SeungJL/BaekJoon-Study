//15591번: MooTube (Silver)
/*
 N (1 ≤ N ≤ 5,000)
 Q (1 ≤ Q ≤ 5,000)
 pi, qi, ri (1 ≤ pi, qi ≤ N, 1 ≤ ri ≤ 1,000,000,000)
(1 ≤ ki ≤ 1,000,000,000, 1 ≤ vi ≤ N)
*/

/*
왜 BFS인지 모르겠어서 참고
https://velog.io/@woga1999/BOJ-15591%EB%B2%88-MooTube-C

*/

#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
int check[5001];
vector<pair<int,int>> v[5001];
queue <int> q;
int N,Q;

int bfs(int vertex, int k){ //시작정점, k값
    int cnt=0;
    check[vertex]=true;
    q.push(vertex);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i].first;
            int next_len=v[cur][i].second;

            if(next_len>=k && check[next]==false){
                cnt++;
                check[next]=true;
                q.push(next);
            }
            
        }
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>Q;
    for(int i=0; i<N-1; i++){
        int p,q,r;
        cin>>p>>q>>r;
        v[p].push_back({q,r});
        v[q].push_back({p,r});
    }

    for(int i=0; i<Q; i++){
        int k,vertex;
        cin>>k>>vertex;
        memset(check,false,sizeof(check));
        cout<<bfs(vertex,k)<<"\n";
    }
}



