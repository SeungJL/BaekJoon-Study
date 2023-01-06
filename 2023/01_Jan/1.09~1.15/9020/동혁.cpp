#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// 1 ~ 10000 까지 소수 테이블 생성
void makePrimeTable(vector<bool> &primeTable);

// 하나의 숫자에 대해 소수 체크
bool isPrime(int number);

int main() {
    fastio;
    vector<bool> primeTable(10001, true);
    makePrimeTable(primeTable);

    int testNum, number;
    cin >> testNum;

    
    while(testNum--) {
        cin >> number;
        for(int i = number / 2; i > 1; i--) {
            if(primeTable[i] && primeTable[number - i]) {
                cout << i << " " << number - i << endl;
                break;
            }
        }

    }

    
    return 0;
}

void makePrimeTable(vector<bool> &primeTable) {
    primeTable[0] = false;
    primeTable[1] = false;

    for (int number = 2; number < primeTable.size(); number++) {
        if(primeTable[number]) {
            primeTable[number] = isPrime(number);
            if(!primeTable[number]) {
                for(int i = 2; number * i <= 10000; i++ ) {
                    primeTable[i * number] = false; 
                }
            }
        }
    }
}

bool isPrime(int number) {
    for(int i = 2; i * i <= number; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

