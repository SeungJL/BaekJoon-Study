#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
int n, m;
int cost[1001];
vector<pair<int, int>> a[1001];
int main(){
    memset(cost, 0x7f7f7f7f, sizeof(cost));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e, w;
        cin >> s >> e >> w;
        a[s].push_back(make_pair(w,e));
        // a[e][s] = w;
    }
    // cout << "hi" <<endl;
    int st, dest;
    cin >> st >> dest;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,st));
    // visited[st] = true;
    int ans = -1;
    while(!pq.empty()){
        int s,w;
        tie(w,s) = pq.top();
        // cout <<"W"<<w<<"s"<<s<<endl;
        pq.pop();
        if(s == dest){
            ans = w;
            break;
        }
        for(int i = 0; i < a[s].size(); i++){
            int nextw, nexte;
            tie(nextw, nexte) = a[s][i];
            if((w + nextw) < cost[nexte]) {
                pq.push(make_pair(w + nextw, nexte));
                cost[nexte] = w + nextw;
            }
        }    
    }
    if(ans == -1) {
        cout << "sth wrong!"<<endl;
    }else cout << ans << endl;

}