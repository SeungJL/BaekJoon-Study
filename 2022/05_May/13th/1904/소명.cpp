//1940번: 01타일
#include <iostream>
using namespace std;

int n;
long long arr[1000001];

//몇개 구해보니까 arr[n]=arr[n-1]+arr[n-2] 조건이 성립했다.
//이유를 생각해보면 arr[n-1] 종류에 끝에 1붙인것과 arr[n-2]종류에 끝에 00붙인것의 합이 arr[n]이므로
//arr[n]=arr[n-1]+arr[n-2]가 성립한다.

int main(){
    cin>>n;
    arr[1]=1;
    arr[2]=2;

    for(int i=3; i<=n; i++){
        arr[i]=(arr[i-1]+arr[i-2])%15746;
    }
    cout<<arr[n]<<"\n";
}