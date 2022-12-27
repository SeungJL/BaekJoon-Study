#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int visited[20001];
vector<int> mat[20001];
int isfull(int v);
bool bfs(int startidx);

int main(){
    int k; 
    cin >> k;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 20001; j++){
            mat[j].clear();
        }
        memset(visited, 0x00, sizeof(visited));
        int v,e;
        cin >> v >> e;
        for(int j = 0; j < e; j++){
            int v1, v2;
            cin >> v1 >> v2;
            mat[v1].push_back(v2);
            mat[v2].push_back(v1); 
        }
        bool over = false;
        int startidx = isfull(v);
        while(1){
            bool over = bfs(startidx);
            if(!over){
                if(v == 1) {
                    cout << "NO" << endl;
                    break;
                }
                else{
                    startidx = isfull(v);
                    if(startidx == -1){
                        cout << "YES" <<endl;
                        break;
                    }
                }
            }else{
                break;
            }
        }
        

    }
}
int isfull(int v){
    bool ok = true;
    for(int i = 1; i <= v; i++){
        if(visited[i] == 0){
            return i;
        }
    }
    return -1;
}
bool bfs(int startidx){
    visited[startidx] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(startidx,1));
    bool over = false;
    while(!q.empty()){
        int cur_idx, cur_tok;
        tie(cur_idx, cur_tok) = q.front();
        q.pop();
        for(auto nxt_idx : mat[cur_idx]){
            if(visited[nxt_idx] == cur_tok){
                cout << "NO" << endl;
                over = true;
                break;
            }
            else if(visited[nxt_idx] == 0){
                int nxt_tok = (cur_tok == 1) ? 2 : 1;
                visited[nxt_idx] = nxt_tok;
                q.push(make_pair(nxt_idx, nxt_tok));
            }
        }
        if(over) break;
    }
    return over;
}