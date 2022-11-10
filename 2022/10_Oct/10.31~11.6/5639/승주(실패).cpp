#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> V(1000000);

void toZeroPush(int a) {
	V[a].push_back(0);
	V[a].push_back(0);
	V[a].push_back(0);
}
int main() {

	int x, root, temp, parent, backStart;

	cin >> temp;
	toZeroPush(temp);
	root = temp;
	parent = temp;
	int flag = 0;
	while (cin >> x) {
		toZeroPush(x);

		if (x < parent) {
			V[parent][0] = x;
			V[x][2] = parent;
		}
		else {
			if (flag == 0) {
				backStart = parent;
				flag = 1;
			}
			int tmp = parent;
			while (1) {
				if (tmp == root) break;
				if (x < V[tmp][2]) {
					if (V[tmp][1] == 0) {
						parent = tmp;
					}
					break;
				}
				tmp = V[tmp][2];
			}

			V[parent][1] = x;
			V[x][2] = parent;
		}
		parent = x;
		if (parent == 110) break;
	}

	parent = V[backStart][2];
	int toNode = 0;
	while (1) {
		if (V[parent][0] != 0) {
			toNode = 0;
			parent = V[parent][0];
		}
		else if (V[parent][1] != 0) {
			toNode = 1;
			parent = V[parent][1];
		}
		else {
			cout << parent << '\n';
			if (parent == root) break;
			if (parent > V[parent][2]) toNode = 1;
			else toNode = 0;
			parent = V[parent][2];
			V[parent][toNode] = 0;
		}
	}

}