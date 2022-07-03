//2178. 미로 탐색
/*
2<=N,M<=100

*/
#include <iostream>
#include <queue>
using namespace std;

int n,m;
char arr[101][101];
int dist[101][101];
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
queue<pair<int,int>> q;

void bfs(int i,int j){
    q.push({i,j});
    while(!q.empty()){
        int cy=q.front().first;
        int cx=q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n && arr[ny][nx]=='1'){
                if(dist[ny][nx]==0){ //방문하지 않았을때만
                    // cout<<"ny: "<<ny<<", nx: "<<nx<<"\n";
                    dist[ny][nx]=dist[cy][cx]+1;
                    q.push({ny,nx});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    dist[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    bfs(0,0);
    // cout<<"-----"<<"\n";
    //  for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<dist[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<dist[n-1][m-1]<<"\n";

}