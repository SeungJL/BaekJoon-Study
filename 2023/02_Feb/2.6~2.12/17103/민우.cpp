#include <iostream>
using namespace std;

bool check[1000001] = { false, };

int main() {

    check[0] = true;
    check[1] = true;

    for(int i=2; i<1000001; i++) {
        if(check[i] == false) {
            for(int j=i + i; j<1000001; j += i) {
                check[j] = true;
            }
        }
    }
    
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        int ans = 0;
        for(int i=0; i <= n / 2 ; i++) {
            if(check[i] == false && check[n-i] == false) ans++;
        }
        
        cout << ans << "\n";
    }
}