#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m, n, k;
int mymap[101][101];
int dir[4][2] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dfs(int tok,int x,int y);
int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k ; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1 ; j < x2; j++){
            for(int k = y1; k < y2; k++){
                mymap[j][k] = -1;
            }
        }
    }
    int tok = 0;
    vector<int> area;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(mymap[i][j] == 0){
                int a = 0;
                tok += 1;
                mymap[i][j] = tok;
                a = dfs(tok, i, j);
                area.push_back(a);
            }
        }
    }
    // for(int i =0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << mymap[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    sort(area.begin(), area.end());
    cout << tok << endl;
    for(auto it : area){
        cout << it << " ";
    }
    cout << endl;
}

int dfs(int tok,int x,int y){
    int area = 0;
    for(int i = 0 ; i < 4; i++){
        int nextx, nexty;
        nextx = x + dir[i][0];
        nexty = y + dir[i][1];
        if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && mymap[nextx][nexty] == 0){
            mymap[nextx][nexty] = tok;
            area += dfs(tok, nextx, nexty);
        }
    }
    return area + 1;

}