#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[10001] = { 0, };
int check[10001] = { 1, 1, 0 };
vector<int> v;
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }

    // 10000까지의 소수 미리 check
    for(int i=0; i < 10001; i++) {
        if(check[i] == 0) {
            for(int j=i+i; j<10001; j += i) {
                check[j] = 1;
            }
        }
    }


    for(int i=0; i<n; i++) {
        int target = arr[i]; // 검사할 숫자
        int first = 0; // 작은 수 
        int second = 0; // 큰 수
        int diff = 10000; // 두 수의 차
        for(int j=2; j<target/ 2 + 1; j++) { // 검사할 숫자의 절반까지만 더한다 ( 나머지 절반은 대칭이기 떄문 )

            if(check[j] == 0 && check[target-j] == 0) { // 더해서 두개다 소수이면

                if(abs(target - 2 * j < diff)) { // 차이가 저번 합 보다 작을때 변수에 저장
                    first = j;
                    second = target - j;
                }
            }
        }

        cout << first << " " << second << "\n";
    }

    
}