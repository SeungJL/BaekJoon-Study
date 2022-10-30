#include<bits/stdc++.h>
using namespace std;
int n, d, k, c;
int a[30001];
int issushi[3001];
int sushi_length = 0;
int ans = 0;
int main(){
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // cout << "a[i] " <<a[i] << ": ";
        issushi[a[i]] += 1;
        if(issushi[a[i]] == 1) sushi_length += 1;
        if(i >= k){
            // cout << "takeout is " << a[i - k] << " ! "; 
            issushi[a[i - k]] -= 1;
            if(issushi[a[i - k]] == 0) sushi_length -= 1;
        }
        if(issushi[c] == 0){
            ans = max(ans, sushi_length + 1);
        }else{
            ans = max(ans, sushi_length);
        }
        // cout << ans <<endl;
    }
    // n과 0의 경계를 넘는 것까지 고려
    for(int i = n - k + 1; i < n; i++){
        // i ~ (i + k -1) % n
        issushi[a[(i + k - 1) % n]] += 1;
        if(issushi[a[(i + k - 1) % n]] == 1) sushi_length += 1;
        issushi[a[(i - 1) % n]] -= 1;
        if(issushi[a[(i - 1) % n]] == 0) sushi_length -= 1;
        
        if(issushi[c] == 0){
            ans = max(ans, sushi_length + 1);
        }else{
            ans = max(ans, sushi_length);
        }       

    }
    cout << ans << endl;
}