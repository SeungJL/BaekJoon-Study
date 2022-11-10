#include <iostream>

using namespace std;

int main()
{
    
    int N,K;
    int a[11];
    
    cin >> N >> K;
    
    
    for (int i=0; i< N; i++){
        cin >> a[i];
    }
    
    int cnt =0;
    
    for(int i=N-1 ; i>=0; i--){
            cnt+= K/a[i];
            K = K%a[i];
    }
    
    cout << cnt;
   
    return 0;
}
