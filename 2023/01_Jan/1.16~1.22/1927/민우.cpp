#include <iostream>
#include <queue>
using namespace std;

long long arr[100001] = { 0, };
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        long long input;
        cin >> input;
        if(input==0) {
            if(pq.size() == 0) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(input);
        }
    }
}

