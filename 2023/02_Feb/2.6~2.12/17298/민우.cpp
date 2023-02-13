#include <iostream>
#include <stack>

using namespace std;
int arr[1000001];
int ans[1000001] = { -1, };
stack<int> s;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    s.push(0);
    for (int i = 1; i < n; i++) {

        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);

    }

    for (int i = 0; i < n - 1; i++) cout << ans[i] << " ";
    cout << -1;
}