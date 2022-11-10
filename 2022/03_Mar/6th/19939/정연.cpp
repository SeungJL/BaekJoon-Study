#include <iostream>

using namespace std;

int sum(int k){
    int res=0;
    for(int i=1; i<= k;i++){
        res+=i;
    }
    return res;
}

int main() {
    
    int n, k;
    cin  >> n >> k;
    
    int r = sum(k);
    
    if(n < r) cout << "-1\n";
    else{
        if((n-r)%k==0) cout << k-1 <<"\n";
        else cout << k <<"\n";
    }

}