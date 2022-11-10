#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    char name;
    struct Node *left;
    struct Node *right;
} Node;

Node *root;

Node *getNode(char name) {
    Node *newNode = new Node();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->name = name;
    return newNode;
}

Node *findNode(Node *p, char name) {
    if (p == NULL) return NULL;
    if (p->name == name) return p;
    Node *q = findNode(p->left, name);
    if (q != NULL) return q;
    q = findNode(p->right, name);
    if (q != NULL) return q;
    return NULL;
}

void insertNode(char name, char left, char right) {
    Node *newNode = findNode(root, name);
    if (newNode == NULL) newNode = getNode(name);

    if (left != '.') {
        newNode->left = getNode(left);
    }
    if (right != '.') {
        newNode->right = getNode(right);
    }
}

void preOrder(Node *p) {
    if (p == NULL) return;
    printf("%c", p->name);
    preOrder(p->left);
    preOrder(p->right);
}

void inOrder(Node *p) {
    if (p == NULL) return;
    inOrder(p->left);
    printf("%c", p->name);
    inOrder(p->right);
}

void postOrder(Node *p) {
    if (p == NULL) return;
    postOrder(p->left);
    postOrder(p->right);
    printf("%c", p->name);
}

int main() {
    root = getNode('A');

    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char name, left, right;
        scanf("%c %c %c", &name, &left, &right);
        insertNode(name, left, right);
        getchar();
    }


    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    return 0;
}