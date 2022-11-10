/*
10 512 512
10 511 511
케이스 미통과 -> 배열을 쓰지 않고 해결해야..
*/
#include <bits/stdc++.h>
using namespace std;
int n, r, c;

int board[40000][40000];

int dy[4] = {0,0,1,1};
int dx[4] = {0,1,0,1};

int visit(int y, int x, int count, int size){
	if( size == 1) {
		//cout << y << " " << x << "\n";
		for(int i=0; i <4; i++){
			//cout << "y :" << y+dy[i] << " x : " << x + dx[i] << "\n";
			board[y+dy[i]][x + dx[i]] += i + count;
		} 
		return count + 4;
	}
	
	//4
	int count1 = visit(y, x, count, size-1);
	//cout << count1 << "\n";
	int count2 = visit(y, x + pow(2,size-1), count1, size-1 );
	//cout << count2 << "\n";
	int count3 = visit(y + pow(2,size-1), x, count2, size-1 );
	//cout << count3 << "\n";
	int count4 = visit(y + pow(2,size-1), x + pow(2,size-1), count3, size-1 );
	//cout << count4 << "\n";
	
	return count4;
}

int main(){
	cin >> n >> r >> c;
	visit(0,0,0,n);
	
	for(int i=0; i < pow(2,n); i++){
		for(int j=0; j < pow(2,n); j++){
			cout << board[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << board[r][c] <<endl;
}
