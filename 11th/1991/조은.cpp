#include <iostream>
using namespace std;

int lc[27], rc[27]; // lc[i]/rc[i]: i번 노드의 left/right-child

void preorder(int cur) {
	cout << char(cur+'A'-1);
	if(lc[cur] != 0) preorder(lc[cur]);
	if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
	if(lc[cur] != 0) inorder(lc[cur]);
	cout << char(cur+'A'-1);
	if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
	if(lc[cur] != 0) postorder(lc[cur]);
	if(rc[cur] != 0) postorder(rc[cur]);
	cout << char(cur+'A'-1);
}

int main(void) {
	int N;
	cin >> N;
	for(int i=1; i<=N; i++) {
		char cur, left, right;
		cin >> cur >> left >> right;
		if(left != '.') lc[cur-'A'+1] = left-'A'+1;
		if(right != '.') rc[cur-'A'+1] = right -'A'+1;
	}
	preorder(1); cout << '\n';
	inorder(1); cout << '\n';
	postorder(1); cout << '\n';

	return 0;
}