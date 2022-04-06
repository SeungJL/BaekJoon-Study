#include <iostream>
#include <set>
using namespace std;

set<int> S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M;
	cin >> M;

	string op;
	int x;
	while(M--) {
		cin >> op;
		if(op == "add") {
			cin >> x;
			S.insert(x);
		}
		else if(op == "remove") {
			cin >> x;
			S.erase(x);
		}
		else if(op == "check") {
			cin >> x;
			if(S.find(x) != S.end()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(op == "toggle") {
			cin >> x;
			if(S.find(x) != S.end()) S.erase(x);
			else S.insert(x);
		}
		else if(op == "all") {
			S = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if(op == "empty") {
			S = {};
		}
	}
    
    return 0;
}