//17070. 파이프 옮기기1(실패)
//예제 잘 나오는데 어디가 틀린지 모르겠따 ,,,,,,
/*
집의 크기 3<=N<=16
(1,1), (1,2)는 항상 빈칸.
방법의수: 0이상 1,000,000이하

*/
#include <iostream>
using namespace std;

int n;
int arr[17][17];
int d[17][17][4]; 
//d[n][n][0]:(n,n)에 -모양으로 도착
//d[n][n][1]: \모양으로 도착
//d[n][n][2]: |모양으로 도착
int answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    d[0][1][0]=1; //(0,1)에 가로로 놓여있음

    for(int i=0; i<n; i++){ //arr[0][1]부터 확인
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                if(i==0 && j<=1){
                    continue;
                }
                //(i,j)번째에 가로로 들어오는 경우
                if(arr[i][j-1]==1)
                    d[i][j][0]=0;
                else
                    d[i][j][0]=d[i][j-1][0]+d[i][j-1][1];
                
                //(i,j)번째에 대각선으로 들어오는 경우
                if(arr[i-1][j-1]==1 || arr[i-1][j]==1 || arr[i][j-1]==1){
                    d[i][j][1]=0;
                }else{
                    d[i][j][1]=d[i-1][j-1][0]+d[i-1][j-1][1]+d[i-1][j-1][2];
                }

                //(i,j)번째에 세로로 들어오는 경우
                if(arr[i-1][j]==1){
                    d[i][j][2]=0;
                }else{
                    d[i][j][2]=d[i-1][j][2]+d[i-1][j][1];
                }
                
            }
        }
    }
    answer=d[n-1][n-1][0]+d[n-1][n-1][1]+d[n-1][n-1][2];    
    cout<<answer<<"\n";
}