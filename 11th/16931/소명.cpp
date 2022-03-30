//16931번: 겉넓이 구하기
#include <iostream>
using namespace std;

int n,m;
int arr[102][102];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum=0;
    cin>>n>>m;
    sum=2*n*m; //위아랫면 합 : 2*n*m

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    // 4개의 옆면 합 구하기
    for(int x=1; x<=n; x++){
        for(int y=1; y<=m; y++){
            for(int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(arr[x][y]>arr[nx][ny])
                sum+=(arr[x][y]-arr[nx][ny]);
            }
        }
    }
    cout<<sum<<"\n";

}