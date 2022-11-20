#include<bits/stdc++.h>
using namespace std;
int n;
long s[11];
long e[11];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> e[i];
    }
    long ans = 0x7fffffffffffffff; 
    for(int i = 1; i < (1 << n); i++){
        long ssum = 1; 
        long esum = 0;
        for(int j = 0; j < n; j++){
            
            if(((1 << j) & i) > 0){
                ssum *= s[j];
                esum += e[j];
            }
        }
        ans = min(ans, abs(ssum - esum));
    }

    cout << ans << endl;

}