#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int n, m;
int a[8][8];
int dir[4][2] = {{-1,0}, {1,0}, {0, 1}, {0, -1}};
vector<pair<int,int>> mpty;
vector<pair<int,int>> virus;
int main(){
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                mpty.push_back(make_pair(i,j));
            }else if(a[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }

    for(int i = 0; i < mpty.size(); i++){
        for(int j = i + 1; j < mpty.size(); j++){
            for(int k = j + 1; k < mpty.size(); k++){
                a[mpty[i].first][mpty[i].second] = 1;
                a[mpty[j].first][mpty[j].second] = 1;
                a[mpty[k].first][mpty[k].second] = 1;
                queue<pair<int,int>> q;
                for(auto it : virus){
                    q.push(it);
                }
                while(!q.empty()){
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for(int l = 0; l < 4; l++){
                        int nextx = x + dir[l][0];
                        int nexty = y + dir[l][1];
                        if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
                        if(a[nextx][nexty] == 0){
                            a[nextx][nexty] = -1;
                            q.push(make_pair(nextx, nexty));
                        }
                    }
                }
                int part_cnt = 0;
                for(int r = 0; r < n ; r++){
                    for(int c = 0; c < m; c++){
                        if(a[r][c] == -1){
                            a[r][c] = 0;
                        }else if(a[r][c] == 0){
                            part_cnt += 1;
                        }
                    }
                }
                cnt = max(part_cnt, cnt);
                a[mpty[i].first][mpty[i].second] = 0;
                a[mpty[j].first][mpty[j].second] = 0;
                a[mpty[k].first][mpty[k].second] = 0;
            }
        }
    }    
    cout << cnt << endl;
}



