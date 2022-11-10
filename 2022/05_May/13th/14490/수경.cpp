#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main(){
    int n, m;
    scanf("%d:%d", &n, &m);

    //최대공약수
    int a = n, b = m;
    if(n<m) {
        a = m;
        b = n;
    }

    int tmp = GCD(a, b);
    printf("%d:%d\n", n/tmp, m/tmp);
    return 0;
}
