#include <iostream>

using namespace std;

int arr[100001];

int main() {


    int n, k;
    
    cin >> n >> k;
    
    for(int i=2; i<=n; i++){
        if(arr[i]) continue;
        for(int j=i; j<=n; j+=i){
            arr[j]=max(arr[j],i);
        }
    }
    
    int cnt =0;
    
    for(int i=1; i<=n; i++){
        if(arr[i]<=k) cnt++;
    }
    
    cout << cnt <<"\n";
    
    return 0;
}
