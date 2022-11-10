#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;

int n,cnt=0;

int main() {
    
    cin >> n;
    int factorial=1;
    for(int i=1; i<=n; i++){
        int x=i;
        while(x%5==0){
            cnt++;
            x/=5;
        }
    }
    
    cout << cnt;
    return 0;
}