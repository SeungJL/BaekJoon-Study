#include <iostream>
#include <algorithm>

using namespace std;


int main(){
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 
  
  int n,m;
  
  cin >> n >> m;
  
  char arr[50][50];
  int col[50]={0},row[50]={0};
  

  for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
			    col[i]=1;
			    row[j]=1;
			}
		}
	}
	
  int cntx = count(col,col+n, 0);
  int cnty = count(row,row+m, 0);

  
  cout << max(cntx,cnty) <<"\n";
  
}
