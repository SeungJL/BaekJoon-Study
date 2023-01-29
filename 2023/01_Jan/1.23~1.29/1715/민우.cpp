#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    int sum = 0;

    while(pq.size() != 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        // cout << first << " " << second << "\n";

        sum += first + second;
        pq.push(first + second);
    }

    cout << sum;
}
