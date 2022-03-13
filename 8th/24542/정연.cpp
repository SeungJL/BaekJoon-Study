#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> v[200001];
bool visited[200001];
int depth=1, ans=1;

void dfs(int cur){
    visited[cur] = true;
    depth++;
    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i];
        if(!visited[next]){
            dfs(next);
            visited[next]=true;
        }
    }

}

int main() {
	
	cin >> n >> m;
	
	while(m--){
	    int a, b;
	    cin >> a >> b;
	    v[a].push_back(b);
	    v[b].push_back(a);
	}
	
	for(int i=1; i<= n; i++){
	    if(!visited[i]){
	        dfs(i);
            ans *= depth-1;
	    }
	    depth=1;
	}

    cout << ans%1000000007 <<"\n";
    
	return 0;
}