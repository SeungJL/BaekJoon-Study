#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    char data;
    Node *pre, *next;
} Node; 

Node* create_node(char data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->pre = NULL;
    new_node->next = NULL;
    return (new_node);
}

Node* insert_node(Node* cursor, int data) {
    Node *new_node = create_node(data);
    new_node->pre = cursor;
    new_node->next = cursor->next;
    if (cursor->next) cursor->next->pre = new_node;
    cursor->next = new_node;
    return (new_node);
}

Node* delete_node(Node* cursor) {
    cursor->pre->next = cursor->next;
    if (cursor->next) cursor->next->pre = cursor->pre;
    Node *new_cursor = cursor->pre;
    delete cursor;
    return (new_cursor);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    // init
    string str;
    int cmd_n;
    cin >> str >> cmd_n;
    
    Node *head = create_node(' ');
    Node* cursor = head;
    for (auto e : str) {
        cursor = insert_node(cursor, e);
        if (!(head->next)) head->next = cursor;
    }
    
    // solve 
    for (int c = 0; c < cmd_n; c++) {
        char cmd;
        cin >> cmd;

        switch (cmd) {
            case 'L' :
                if (cursor != head) cursor = cursor->pre;
                break; 
            case 'D' :
                if (cursor->next) cursor = cursor->next;
                break;
            case 'B' :
                if (cursor != head) cursor = delete_node(cursor);
                break;
            case 'P' :
                cin >> cmd;
                cursor = insert_node(cursor, cmd);
                break;
        }
    }

    // print result
    cursor = head->next;
    while (cursor) {
        cout << cursor->data;
        Node *tmp = cursor;
        cursor = cursor->next;
        delete tmp;
    }
    cout << "\n";
}