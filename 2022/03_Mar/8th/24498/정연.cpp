#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;


int main() {
	
	int n;
	cin >> n;
    
    vector<int> tower(n);
    
    for(int i=0; i<n; i++){
        cin >> tower[i];
    }
    int max = 0;
    for(int i=1; i<n-1; i++){
        int left = tower[i-1];
        int right = tower[i+1];
        int min_value = min(left, right);
        
        if(max < min_value+tower[i]){
            max = min_value+tower[i];
        }
    }
    if(max < tower[0]) max = tower[0];
    if(max < tower[n-1]) max = tower[n-1];
    
    cout << max;
    
	return 0;
}