#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	
	set<int> A, B;
	
	for(int i=0; i<n ; i++){
	    int a;
	    cin >> a;
	    A.insert(a);
	}
    for(int i=0; i<m ; i++){
		int b;
	    cin >> b;
	    B.insert(b);
	}
	set<int> C, D;
	
	set_difference(A.begin(), A.end(), B.begin(), B.end(),inserter(C, C.begin()));
	set_difference(B.begin(), B.end(), A.begin(), A.end(),inserter(D, D.begin()));

	
	cout << C.size() + D.size();
	
    return 0;
}


