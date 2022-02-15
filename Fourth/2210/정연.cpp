#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int arr[5][5];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
set<int> s;

void DFS(int x, int y, int num, int depth){
    if(depth == 6){
        s.insert(num);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx >= 0 && nx < 5 && ny >=0 && ny <5){
            DFS(nx, ny, num*10 + arr[nx][ny], depth+1);
            
        }
    }
}

int main()
{
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            DFS(i,j,arr[i][j], 1);
        }
    }
    
    cout << s.size() <<'\n';

    return 0;
}
