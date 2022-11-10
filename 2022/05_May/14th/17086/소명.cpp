//17086번: 아기상어 2

/*풀이
처음에, 문제이해를 잘 못했는데 상어와~상어 사이의 거리가 최대인 값을 구하는 줄 알았는데,
상어가 없는 지점에서 상어까지의 거리가 최대인 값을 구하는 문제였다.

BFS를 이용하였다.
입력받은 배열을 돌면서 상어가 있는지점에서 bfs를 시작한다.
상어가 있는 지점마다 bfs를 돌면서 이전 dist값보다 더 작으면 더 작은값으로 갱신한다.
이때, dist배열이 0이면(한번도 방문하지 않았으면) bfs 방식 그대로(이전 좌표+1 하는과정) dist값을 갱신해주면 되고,
dist배열이 0이 아니면(방문 된 적 있으면) 더 작은값으로 갱신해주어야 한다.

마지막에, 최대 dist값을 찾는다.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n,m;
int arr[50][50]; //상어 입력
int dist[50][50]; //상어로부터의 거리
int check[50][50]; //방문체크
queue <pair<int,int>> q;

//8방향
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};

int answer;

void bfs(int x, int y){
    check[x][y]=true;
    q.push({x,y});
  
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(arr[nx][ny]==0){ //상어가 없는 지점만.
                    if(check[nx][ny]==false){
                        check[nx][ny]=true;
                        
                        int temp=dist[cx][cy]+1;
                        if(dist[nx][ny]==0){ //방문한적 없으면 그대로 갱신
                            dist[nx][ny]=temp;
                        }else if(dist[nx][ny]>temp){  // 방문한 적 있으면 최솟값으로 갱신
                            dist[nx][ny]=temp;
                        }
                            q.push({nx,ny});
                    }
                }
            }
        }
    }


}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    //상어가 있는 지점에서 bfs돌리면서 dist배열 갱신
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            memset(check,false,sizeof(check)); //check배열 false 초기화
            if(arr[i][j]==1){
                bfs(i,j);
            }
        }
    }

    //최댓값 구하기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(answer<dist[i][j])
                answer=dist[i][j];
        }
    }

    cout<<answer<<"\n";
}
