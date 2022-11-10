#include <iostream>

using namespace std;

struct Node {
	char data = NULL;
	Node* left = NULL;
	Node* right = NULL;
};

Node* arr[30];

void preorderTraverse(Node* n) {
	if (n == NULL || n->data == NULL) return;
	cout << n->data;
	preorderTraverse(n->left);
	preorderTraverse(n->right);
}

void inorderTraverse(Node* n) {
	if (n == NULL || n->data == NULL) return;
	inorderTraverse(n->left);
	cout << n->data;
	inorderTraverse(n->right);
}

void postorderTraverse(Node* n) {
	if (n == NULL || n->data == NULL) return;
	postorderTraverse(n->left);
	postorderTraverse(n->right);
	cout << n->data;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 30; i++) {
		Node* node = new Node;
		arr[i] = node;
	}

	for (int i = 0; i < N; i++) {
		char nowNode, leftNode, rightNode;
		cin >> nowNode >> leftNode >> rightNode;
		int index = nowNode - 'A';
		arr[index]->data = nowNode;
		arr[index]->left = arr[leftNode - 'A'];
		arr[index]->right = arr[rightNode - 'A'];
	}
	preorderTraverse(arr[0]);
	cout << '\n';
	inorderTraverse(arr[0]);
	cout << '\n';
	postorderTraverse(arr[0]);
	cout << endl;

	return 0;
}