#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;


int n;

struct node {
	struct node* left;
	struct node* right;
	int data;
};


void insert(struct node*& root, int k) {
	if (root == nullptr) {
		root = new node();
		root->data = k;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (k < root->data)
			insert(root->left, k);
		else
			insert(root->right, k);
	}
}



void postorder(node* root)
{
	if (root != NULL)
	{
		if (root->left != nullptr)
			postorder(root->left);
		if (root->right != nullptr)
			postorder(root->right);
		if (root->data != 0)
			cout << root->data << "\n";
	}
}
int main()
{

	node* root = new node();

	while (cin >> n) {

		if (n == EOF) break;
		insert(root, n);

	}
	postorder(root);

}