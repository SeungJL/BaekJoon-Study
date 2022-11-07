#include<bits/stdc++.h>
using namespace std;
typedef struct _node{
    _node* left;
    _node* right;
    _node* parent;
    int val;
} Node;
typedef struct _tree{
    _node* root;
    _node* cur_pt;
    int len = 0;
} Tree;
void insert_element(Tree* ptree, int val);
void print_post(Node * pnode);
int main(){
    int tmp;
    int cnt = 0;
    Tree tre;
    while(cin >> tmp){
        insert_element(&tre, tmp);
        // cout << "done " << tmp << endl;
    } 
    print_post(tre.root);
    
}
void insert_element(Tree* ptree, int val){
    Node* node = (Node*) malloc(sizeof(Node));
    if(ptree->len == 0 ){
        ptree->root = (Node *) malloc(sizeof(Node));
        ptree->root->val = val;
        ptree->cur_pt = ptree->root;
        ptree->root -> parent = NULL;
    }
    else{
        Node* cur_pt = ptree->cur_pt;
        Node* parent_pt ;
        bool isleftmost = true;
        bool isrightmost =  false;
        while(cur_pt != NULL){
            // cout << "cur pt is" << cur_pt->val<<endl;
            if(val < cur_pt->val){
                parent_pt = cur_pt;
                cur_pt = cur_pt -> left;
            }else{
                isrightmost = true;
                while (cur_pt -> parent != NULL){
                    if(val < cur_pt -> parent -> val ){
                        parent_pt = cur_pt;
                        cur_pt = cur_pt -> right;
                        while (cur_pt != NULL) {
                            parent_pt = cur_pt;
                            cur_pt = cur_pt ->right;
                            
                        }
                        isrightmost = false;
                        break;
                    }else{
                        // cout<<"now current is "<< cur_pt -> val<<endl;
                        cur_pt = cur_pt -> parent;
                    }
                }
                if(isrightmost){
                    parent_pt = cur_pt;
                    cur_pt = cur_pt -> right;
                    while(cur_pt != NULL){
                        parent_pt = cur_pt;
                        cur_pt = cur_pt -> right;
                    }
                }
                isleftmost = false;
                break;
            }
            //못빠져나오면 leftmost
        }
        if(isleftmost){
            parent_pt -> left = (Node *) malloc(sizeof(Node));
            parent_pt -> left -> val = val;
            parent_pt -> left -> parent = parent_pt;
            ptree -> cur_pt = parent_pt -> left;
            // cout <<"leftmost!"<<endl;


        }else{
            parent_pt -> right = (Node *) malloc(sizeof(Node));
            parent_pt -> right -> val = val;
            parent_pt -> right -> parent = parent_pt;
            ptree -> cur_pt = parent_pt -> right;
            // cout<<"myparent is" << parent_pt ->val<<endl;
        }   
    }
    ptree-> len += 1;

}
void print_post(Node * pnode){
    if(pnode == NULL) return;
    print_post(pnode -> left);
    print_post(pnode -> right);
    cout << pnode -> val << endl;
}