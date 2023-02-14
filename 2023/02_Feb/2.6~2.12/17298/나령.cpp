#include <iostream>
#include <stack>
using namespace std;

int a[1000001];
int ans[1000001];
stack<int> s; // 오큰수를 구하려고 하는 수의 인덱스(값X)

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++) {
        while(!s.empty() && a[s.top()] < a[i]){
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";

    return 0;
}
