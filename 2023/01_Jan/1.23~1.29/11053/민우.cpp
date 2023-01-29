#include <iostream>
using namespace std;

int arr[1001] = { 0, };
int dp[1001] = { 1, };

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
        dp[i] = 1;
    }

    for(int i=1; i<n; i++) {
        // 나보다 작거나 같은 값 중에 dp값 가장 큰거 찾기
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        } 
        
    }

    int answer = 0;
    for(int i=0; i<n; i++) {
        if(dp[i] > answer) {
            answer = dp[i];
        }
    }
    cout << answer;
}