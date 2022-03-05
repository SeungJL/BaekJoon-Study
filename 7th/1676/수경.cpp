#include <bits/stdc++.h>

using namespace std;

long long zero(int n, int what){
    int result = 0;
    for(long long i = what ; i <= n ; i *= what){
        result += n / i;

    }
    return result;
}

int main(){
    int N;
    cin >> N;
    int two = zero(N, 2), five = zero(N, 5);
    cout << min(two, five);
    return 0;
}
// 1*2*3*4*5