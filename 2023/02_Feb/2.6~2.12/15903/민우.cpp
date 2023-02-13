#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue< long long, vector< long long>, greater< long long>> pq;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    for(int i=0; i<m; i++) {
        long long first = pq.top();
        pq.pop();
        
        long long second = pq.top();
        pq.pop();

        pq.push(first+second);
        pq.push(first+second);
    }

     long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}