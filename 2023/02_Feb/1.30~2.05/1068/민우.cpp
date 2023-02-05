#include <iostream>
#include <queue>
using namespace std;

int tree[51] = { -2, };
int child[51] = { 0, };
queue<int> q;

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int node;
        cin >> node;
        tree[i] = node;
        child[tree[i]]++;
    }

    int delete_node;
    cin >> delete_node;
    q.push(delete_node);

    while(!q.empty()) {
        int to_delete = q.front();

        child[to_delete] = -1;
        child[tree[to_delete]]--;
        q.pop(); 

        for(int i=0; i<n; i++) {
            if(tree[i] == to_delete) {
                q.push(i);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(child[i] == 0) ans++;
    }

    cout << ans;
}