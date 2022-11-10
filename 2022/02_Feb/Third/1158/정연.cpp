#include <iostream>
#include <queue>
#include <vector>

using namespace std;
 
 
 
int main() {
    int n,k;
    cin >> n >> k;
    
    queue<int> q;
    vector<int> v;
    
    for(int i=1;i<=n;i++)
        q.push(i);
        
    while(!q.empty()){
        for(int i=0; i <k-1 ;i++){
            int r = q.front();
            q.pop();
            q.push(r);
        }
        int r = q.front();
        q.pop();
        v.push_back(r);
    }
    

    cout << "<" << v[0];
    for(int i=1; i<n ; i++)
        cout  << ", " << v[i];
    cout << ">";
    
    return 0;
}
