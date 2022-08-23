#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int leaf_count = 0;

struct Node {
	vector<Node*> childs;
};

void dfs_delete(Node* now, Node* del_target) {
	if (!now)
		return;
	for (int i = 0; i < now->childs.size(); i++) {
		if (now->childs[i] == del_target) 
			now->childs.erase(now->childs.begin() + i);
		else if (now->childs[i])
			dfs_delete(now->childs[i], del_target);
	}
}

void dfs_leaf_count(Node* now) {
	if (!now) 
		return;
	int child_count = 0;
	for (int i = 0; i < now->childs.size(); i++) {
		if (now->childs[i]) {
			child_count++;
			dfs_leaf_count(now->childs[i]);
		}
	}
	if (!child_count)
		leaf_count++;
}

int main() {
	int N, del_node;
	cin >> N;
	vector<Node*> nodes(N);
	Node* root;
	int now_parent;
	for (int i = 0; i < N; i++) 
		nodes[i] = new Node;
	for (int i = 0; i < N; i++) {
		cin >> now_parent;
		if (now_parent == -1) {
			root = nodes[i];
		}
		else {
			nodes[now_parent]->childs.push_back(nodes[i]);
		}
	}
	cin >> del_node;
	Node* del_target = nodes[del_node];
	if (del_target == root) {
		root = NULL;
	}
	dfs_delete(root, del_target);
	dfs_leaf_count(root);
	cout << leaf_count << endl;
	return 0;
}