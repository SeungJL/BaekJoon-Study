#include<iostream>
using namespace std;
int n,m;
//유클리드 호제법
int gcd(int,int);

int main(){
    cin >> n >> m;
    cout << m - gcd(m, n);
    
}
int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}