#include<bits/stdc++.h>
using namespace std;
int N; 
int a[1004];
int dp[1004];

					 	 	     
int main(){
	cin >> N;
	
	for(int i=0; i < N; i++){
		cin >> a[i];
		dp[i] = a[i];
	}
	
	for(int i=0; i < N; i++){
		for(int j=0; j < i; j++){
			if( a[j] < a[i] && dp[j] + a[i] > dp[i] ){
				dp[i] = dp[j] + a[i];
			}
		}
	}
    
  int maxx = -1;
	for(int i=0; i < N; i++){
		maxx = max(maxx, dp[i]);
	}
	cout << maxx << endl;
}
