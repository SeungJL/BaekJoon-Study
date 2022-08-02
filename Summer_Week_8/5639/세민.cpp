#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* addChild(Node* node, int data) {
	if (node == nullptr) {
		node = new Node();
		node->data = data;
		node->left = node->right = nullptr;
	}
	else if (node->data >= data)
		node->left = addChild(node->left, data);
	else
		node->right = addChild(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node->left != nullptr)
		postorder(node->left);
	if (node->right != nullptr)
		postorder(node->right);
	cout << node->data << '\n';
}

int main(void)
{
	int n;
	Node* root = nullptr;
	// freopen("input.txt", "r", stdin);
	while (cin >> n) {
		if (n == EOF) break;
		root = addChild(root, n);
	}
	postorder(root);
	return 0;
}