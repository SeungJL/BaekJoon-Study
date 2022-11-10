// 1991번: 트리 순회
#include <iostream>
using namespace std;
pair<char,char> node[26];
int n;

//전위순회
void preorder(char cur){
    if(cur=='.')
    return;
    
    cout<<cur;
    preorder(node[cur-'A'].first);
    preorder(node[cur-'A'].second);
}
//중위순회
void inorder(char cur){
    if(cur=='.')
    return;

    inorder(node[cur-'A'].first);
    cout<<cur;
    inorder(node[cur-'A'].second);
}
//후위순회
void postorder(char cur){
    if(cur=='.')
    return;

    postorder(node[cur-'A'].first);
    postorder(node[cur-'A'].second);
    cout<<cur;
}

int main(){
  
  cin>>n;
    for(int i=0; i<n; i++){
      char parent, left, right;
      cin>>parent>>left>>right;
      node[parent-'A'].first=left;
      node[parent-'A'].second=right;
    }
  
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
}