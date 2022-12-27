#include<iostream>
using namespace std;
int a[51][51];
int n, m;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int leftside[4] = {3, 0, 1, 2};
int backside[4] = {2, 3, 0, 1};
void dfs(int x, int y,int d,int num_left);
int cnt = 0;
int main(){
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) cnt += 1;
        }
    }
    a[r][c] = 2;
    dfs(r, c, d, cnt - 1);


}
void dfs(int x, int y,int d,int num_left){
    // do spin 0 - > 3   1 -> 0  2 -> 1 3 -> 2 
    // cout << "x" << x << "y" << y << "d" << d << "numleft" << num_left << endl;
    if(num_left == 0){
        cout << cnt - num_left << endl;
        exit(0);
    }
    bool ok = false;
    for(int i = 0; i < 4; i++){
        int target_x = x + dir[leftside[d]][0];
        int target_y = y + dir[leftside[d]][1];
        if(a[target_x][target_y] == 0){
            a[target_x][target_y] = 2;
            dfs(target_x, target_y, leftside[d], num_left - 1);
            ok = true;
            break;
        }else{
            d =  leftside[d];
        }

    }
    if(!ok){
        //후진
        int target_x = x + dir[backside[d]][0];
        int target_y = y + dir[backside[d]][1];
        if(a[target_x][target_y] != 1){
            dfs(target_x, target_y, d, num_left);
        }else{
            cout << cnt - num_left;
            exit(0);
        }
    }
    

}