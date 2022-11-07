// 5639

#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
vector<int> postorder;

void pre_to_post(int s, int e) {
	int root = preorder[s];

	if (s < e) {
		int mid = s + 1;
		for ( ; mid <= e; mid++) {
			if (preorder[mid] > root) break;
		}

		if (s+1 <= mid-1) pre_to_post(s+1, mid-1);
		if (mid <= e) pre_to_post(mid, e);
	}
	postorder.push_back(root);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int input;
	while (cin >> input) {
		preorder.push_back(input);
	}

	pre_to_post(0, preorder.size()-1);

	for (auto e : postorder)
		cout << e << "\n";
	
}