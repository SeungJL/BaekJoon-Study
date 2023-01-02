#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main(){
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 2;
    n = n / 2;
    while(n >= 1){
        vector<vector<int>> tmp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vector<int> b(4);
                b[0] = a[i*2][j*2];
                b[1] = a[i*2 + 1][j*2];
                b[2] = a[i*2][j*2 + 1];
                b[3] = a[i*2 + 1][j*2 + 1];
                sort(b.begin(),b.end());
                tmp[i][j] = b[2];
            }
        }
        a = tmp;
        n = n / 2;
    }
    
    cout << a[0][0] << endl;
    

    
}