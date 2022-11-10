#include <iostream>
#include <queue>

using namespace std;

#define dist first 
#define weight second 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int n, w, L, input;
	cin >> n >> w >> L;

	queue<int> waiting_trucks;
	queue<pair<int, int>> onBridge;
	int total_weight = 0, cnt = 0;
	while (n--) {
		cin >> input;
		waiting_trucks.push(input);
	}

	while (!waiting_trucks.empty() || !onBridge.empty()) {
		cnt++;
		
		// out
		if (!onBridge.empty()) {
			int tmp = onBridge.size();
			while (tmp--) {
				onBridge.front().dist--;
				onBridge.push(onBridge.front());
				onBridge.pop();
			}
			if (onBridge.front().dist == 0) {
				total_weight -= onBridge.front().weight;
				onBridge.pop();
			}
		}

		// in
		if (!waiting_trucks.empty() && waiting_trucks.front() + total_weight <= L) {
			onBridge.push(make_pair(w, waiting_trucks.front()));
			total_weight += waiting_trucks.front(); 
			waiting_trucks.pop();
		}
	}
	
	cout << cnt << "\n";
}


