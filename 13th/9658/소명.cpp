//9658번: 돌게임4
//9658번: 돌게임 4
//몰라서 구글링함.
#include <iostream>
using namespace std;

int n;

//상근이가 이기면1, 지면 0
int dp[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    dp[1]=0;
    dp[2]=1;
    dp[3]=0;
    dp[4]=1;

    for(int i=5; i<=n; i++){

        // i-4, i-3, i-1에서 모두 상근이가 이기는 상태이면 i번째에는 상근이는 진다
        // i-4, i-3, i-1 에서 하나라도 지는경우 있으면 i번째에는 이길 수 있다.
        if(dp[i-4] && dp[i-3] && dp[i-1]){
            dp[i]=0;
        }else{
            dp[i]=1;
        }
    }

  if(dp[n]){
      cout<<"SK"<<"\n";
  }else{
      cout<<"CY"<<"\n";
  }
}