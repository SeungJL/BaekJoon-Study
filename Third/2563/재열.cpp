#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> g(1001, false);
	vector<vector<bool>> graph(1001, g);


	int sum = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		sum += 100;		//일단 100을 더함

		int count = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (graph[x+j][y+k]) count++;
				graph[x+j][y+k] = true;
			}
		}

		sum -= count;		//count만큼을 뺀다(기존에 있던거랑 겹치는거)
	}

	cout << sum << endl;

	return 0;
}