#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int w, h;
int map[50][50];
bool visited[50][50];
int dx[8]={0,0,-1,1,-1,1,1,-1};
int dy[8]={1,-1,0,0,-1,1,-1,1};


void dfs(int y, int x){
    visited[y][x] = true;
    
    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=w ||ny>=h) continue;
        if(map[ny][nx]==1 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
    
    
}

int main()
{
   
    while(cin >> w >> h && (w!=0 && h!=0)){
        
        for(int i=0; i<h ; i++){
            for(int j=0; j<w ; j++){
                cin >> map[i][j];
            }
        }
        
        int cnt=0;
        for(int i=0; i<h ; i++){
            for(int j=0; j<w ; j++){
                if(map[i][j]==1 && !visited[i][j]){
                    
                    dfs(i,j);
                    cnt++;
                }
                
                
            }
        }
        
        cout << cnt<< "\n";
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
    }
    
    
    return 0;
}