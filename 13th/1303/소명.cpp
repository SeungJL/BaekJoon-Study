//1303번: 전쟁-전투
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
char arr[100][100];
bool check[100][100];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
vector<int> blue; //우리팀 이어져있는 병사 수  담는 벡터
vector<int> white;
int num;
int our_white; //우리팀의 위력
int your_blue; //적군의 위렴



int bfs(int x, int y,char team){
    queue<pair<int,int>> q;
    check[x][y]=true;
    q.push(make_pair(x,y));
    int cnt=1;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0; i<4; i++ ){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && nx<m && ny>=0 && ny<n){
                if(check[nx][ny]==false && arr[nx][ny]==team){
                    cnt++;
                    check[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                    // cout<<"team: "<<team<<", nx:"<<nx<<", ny:"<<ny<<", cnt: "<<cnt<<"\n";
                }

            }
        }

    }
    
    return cnt; //q가 비면 현재까지 이어짐을 확인한 병사 수 리턴
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //여기서 헤맴,,, 가로크기:n, 세로크기:m
    //원래 세로크기 먼저 입력받을때가 많은데 여기선 순서가 [가로크기, 세로크기]임. 주의!

    cin>>n>>m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];

        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j]==false && arr[i][j]=='W'){ //white(아군팀) 세기
                num=bfs(i,j,'W');
                white.push_back(num); //bfs를 한번 돌았을때 몇명인지 cnt세서, 그값을 벡터에 보관
            }else if(check[i][j]==false && arr[i][j]=='B'){//blue(적군팀) 세기
                num=bfs(i,j,'B');
                blue.push_back(num);
            }
        }
    }

    

    //팀별로 벡터 돌면서 이어져있는 아군수의 제곱만큼 위력에 더해준다. 
    for(int i=0; i<blue.size(); i++){
        // cout<<"blue: "<<blue[i]<<endl;
        your_blue+=(blue[i]*blue[i]);
    }
    for(int i=0; i<white.size(); i++){
        // cout<<"white: "<<white[i]<<endl;
        our_white+=(white[i]*white[i]);
    }

    cout<<our_white<<" "<<your_blue<<"\n";


}