#include<iostream>
using namespace std;
int n, s;
int a[21];
// int mat[21][21];
int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < (1 << n); i++){
        if(i == 0) continue;
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(((1 << j) & i) > 0){
                ans += a[j];
            }
        }
        if(ans == s){
            cnt += 1;
        }
    }

    cout << cnt << endl;
    
    

}
