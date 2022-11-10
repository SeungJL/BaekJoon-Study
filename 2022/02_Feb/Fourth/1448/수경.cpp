#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> V;
    for(int i=0;i<N;i++) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    sort(V.rbegin(), V.rend());
    int a, b, c;
    for(int i=0;i<N-2;i++){
        a = V[i];
        b = V[i+1];
        c = V[i+2];
        if(a < b+c){
            cout << a+b+c;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
/*
 * 1 2 3 -> -1
 * 1 2 2 -> 5
 * 2 3 2 3 2 4 -> 10
 * 2 2 2 3 3 4 -> 10
 * 4 '5' '6' '7' 20 -> 18
 */