// 5639

#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
vector<int> postorder;

/* pre_to_post: pre-order을 post-order로 변환하는 함수
 *             - 재귀 이용
 *
 * parameters - s, e: post-order로 변환하고자 하는 범위 (s ~ e)
 * return: none
 */
void pre_to_post(int s, int e) {
	int root = preorder[s];

	if (s < e) {
		// left, right 구분되는 지점 찾기
		int mid = s + 1;
		for ( ; mid <= e; mid++) {
			if (preorder[mid] > root) break;
		}

		if (s+1 <= mid-1) pre_to_post(s+1, mid-1);	// left
		if (mid <= e) pre_to_post(mid, e);			// right
	}
	postorder.push_back(root); 						// root
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// freopen("input.txt", "rt", stdin);

	/* input */
	int input;
	while (cin >> input) {
		preorder.push_back(input);
	}

	/* solve */
	pre_to_post(0, preorder.size()-1);

	for (auto e : postorder)
		cout << e << "\n";
	
}