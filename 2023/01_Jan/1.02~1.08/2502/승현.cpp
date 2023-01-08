#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
int fibo[31];
int d,k;
int main(){
    cin >> d >> k;
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i = 3; i <= 30; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    int p1 = fibo[d-2];
    int p2 = fibo[d-1];
    for(int a = 1; ; a++){
        if((k - a * p1) % p2 == 0){
            int b = (k - a * p1) / p2;
            cout << a << endl << b << endl;
            exit(0);
        }
    }
}