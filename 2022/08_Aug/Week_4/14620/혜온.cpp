//#include<iostream>
//#include<cmath>
//
//using namespace std;
//int N;
//int garden[10][10];
//int num[128][3]; //sum,i,j
//int arr[3][2];
//
//
//bool overlap(int y1,int x1,int y2,int x2)
//{
//	if (abs(y1 - y2) == abs(x1 - x2))//대각선
//		return false;
//	if (y1 == y2 && abs(x1 - x2) < 3)
//		return false;
//	if (x1 == x2 && abs(y1 - y2) < 3)
//		return false;
//	if (y1 == y2 && x1 == x2)
//		return false;
//	
//	
//
//	return true;
//}
//void backtracking (int depth, int cnt)
//{
//	if (depth == 3)
//	{
//		if(overlap(arr[0][0], arr[0][1], arr[1][0], arr[1][1]))
//			if(overlap(arr[0][0], arr[0][1], arr[2][0], arr[2][1]))
//				if(overlap(arr[1][0], arr[1][1], arr[2][0], arr[2][1]))
//
//
//	}
//
//}
//
//int sum(int y, int x)
//{
//	int temp=garden[y][x];
//	int dx[4] = { 0,1,0,-1 };
//	int dy[4] = { 1,0,-1,0 };
//	int Y , X;
//	for (int k = 0; k < 4; k++)
//	{
//		Y = y + dy[k]; X = x + dx[k];
//		temp += garden[y][x];
//					
//	}
//	return temp;
//}
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> garden[i][j];
//	int cnt = 0;
//	
//
//	/*int size = (N - 2)*(N + 1);
//
//	for(int k=1;k<size;k++)
//		for(int l=k+1;l<size;l++)
//			for (int m = l + 1; m < size; m++)
//			{
//
//			}*/
//
//	
//
//	//int min = 30000, temp = 0;
//	//int dx[4] = { 0,1,0,-1 };
//	//int dy[4] = { 1,0,-1,0 };
//	//int x = 0, y = 0;
//	//
//	////모든 합과 i,j저장
//	//for (int i = 1; i < N - 1; i++)
//	//	for (int j = 1; j < N - 1; j++)
//	//	{
//	//		temp = 0;
//	//		temp += garden[i][j];
//	//		for (int k = 0; k < 4; k++)
//	//		{
//	//			y = i + dy[k]; x = j + dx[k];
//	//			temp += garden[y][x];
//	//			
//	//		}
//	//		
//	//		num[i*N + j][0] = temp;
//	//		num[i*N + j][1] = i;
//	//		num[i*N + j][2] = j;
//	//		cout << i * N + j << endl;
//
//	//	}
//	//
//	//int size = (N - 2)*(N - 2);
//	//temp = 0;
//	//cout << endl;
//	//cout << N + 1 << "   " << N + 1 + size << endl;
//	//int cnt = 0;
//	//for (int i = N+1; i <N+1+ size; i++)
//	//{
//	//	cnt = 0;
//	//	temp += num[i][0];
//	//	cnt++;
//	//	for (int j = N+1; j < N+1+size; j++)
//	//	{
//	//		if (overlap(num[i][1], num[i][2], num[j][1], num[j][2]))
//	//		{
//	//			temp += num[j][0]; cnt++;
//	//		}
//	//		else
//	//			continue;
//	//		for (int k = j + 1; k < size; k++)
//	//		{
//	//			if (overlap(num[i][1], num[i][2], num[k][1], num[k][2]) && overlap(num[j][1], num[j][2], num[k][1], num[k][2]))
//	//			{
//	//				temp += num[k][0]; cnt++;
//	//			}
//	//			else
//	//				continue;
//	//			
//	//			if (temp < min)
//	//				min = temp;
//	//			temp -= num[k][0]; 
//
//	//		}
//	//		temp -= num[j][0]; 
//
//	//	}
//	//	temp -= num[i][0]; 
//	//}
//	//cout << min;
//}

#include <iostream>

using namespace std;

int cost[10][10] = { 0 };
bool visit[10][10] = { false };
int n = 0;
int mini = 10000;
int di[4] = { 0, 0, 1 ,-1 };
int dj[4] = { 1,-1,0,0 };

bool overlap(int i0, int j0) {
	if (visit[i0][j0]) {
		return false;
	}
	for (int idx = 0; idx < 4; idx++) {
		int i1 = i0 + di[idx];
		int j1 = j0 + dj[idx];
		if (i1<0 || i1>n - 1 || j1<0 || j1>n - 1 || visit[i1][j1]) {
			return false;
		}
	}
	return true;
}

void dfs(int count, int sum, int start_i) {
	if (count == 3) {
		if (mini > sum) {
			mini = sum;
		}
		return;
	}

	for (int i = start_i; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!overlap(i, j)) {
				continue;
			}

			int s = cost[i][j];
			visit[i][j] = true;
			for (int idx = 0; idx < 4; idx++) {
				int i1 = i + di[idx];
				int j1 = j + dj[idx];
				visit[i1][j1] = true;
				s += cost[i1][j1];
			}

			dfs(count + 1, sum + s, i);

			visit[i][j] = false;
			for (int idx = 0; idx < 4; idx++) {
				int i1 = i + di[idx];
				int j1 = j + dj[idx];
				visit[i1][j1] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	dfs(0, 0, 1);
	cout << mini;
}