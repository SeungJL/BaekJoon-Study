#include <bits/stdc++.h>
using namespace std;
int n, k;
int point[100004];
int parent[100004];
queue<int> q;
stack<int> path;

void shortest_path(int child){
    if(child == n){ 
        while(!path.empty()){
            int x = path.top(); path.pop();
            cout << x << " ";
        }
        return;
    }

    int next = parent[child];
    path.push(next);

    shortest_path(next);
}

int main(){
	cin >> n >> k;
	
	point[n] = 1;
	q.push(n);
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		
		if(cur == k){
			break;
		}
		
		for(int next : {cur - 1, cur + 1, cur * 2}){
			if( 0 <= next && next <= 100000){
				if(!point[next]){ 
					point[next] = point[cur] + 1;
                    parent[next] = cur;
					q.push(next); 
				}
			}
		}
	}
	cout << point[k] - 1 << endl;
    path.push(k);
    shortest_path(k);

}