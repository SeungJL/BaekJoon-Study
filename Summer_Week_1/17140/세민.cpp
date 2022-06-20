#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int r, c, k;
int R_new, C_new;	//바뀌는 행과 열의 크기
int A[101][101];	
int A_T[101][101];	
int num_cnt[101];	//등장 횟수 저장용 배열

void transpose() {	//C 연산을 하기 위해 행렬의 행과 열을 바꾼다. (전치행렬)
	for (int i = 1; i <= R_new; i++) {
		for (int j = 1; j <= C_new; j++) {
			A_T[j][i] = A[i][j];
		}
	}
}

void reset() {
	for (int i = 1; i <= R_new; i++) {
		for (int j = 1; j <= C_new; j++) {
			A[i][j] = A_T[j][i];
		}
	}
}

int Sort(int(&S)[101][101], int R, int C) {
	int l = 0;
	vector<int> Size;
	for (int i = 1; i <= R; i++) {
		vector<pair<int, int>> v;
		memset(num_cnt, 0, sizeof(num_cnt));
		for (int j = 1; j <= C; j++) num_cnt[S[i][j]]++;
		for (int j = 1; j < 101; j++) {
			if (num_cnt[j] == 0) continue;	//등장 횟수가 0인 경우 무시
			v.push_back(make_pair(num_cnt[j], j));	//등장 횟수와 숫자를 vector에 저장
		}
		sort(v.begin(), v.end());	//정렬
		for (int j = 1; j <= C; j++) S[i][j] = 0; //열이 커진 곳에는 0으로 채운다.
		int idx = 1;	//배열의 인덱스는 1부터 시작
		for (int j = 0; j < v.size(); j++) {
			S[i][idx++] = v[j].second;	//배열에 정렬된 순서대로 숫자를 저장
			S[i][idx++] = v[j].first;	//배열에 정렬된 순서대로 등장 횟수를 저장
		}
		idx--;
		Size.push_back(idx);
	}
	sort(Size.begin(), Size.end());
	l = Size.back();

	return l; //최대 열(열의 크기)를 return
}
int main(void)
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}
	R_new = 3, C_new = 3;	//초기 행과 열의 크기는 모두 3

	int T = 0;	//시간
	while (true) {
		if (T > 100) {	//100초가 지나면 T에 -1 할당 후 while문을 빠져나온다.
			T = -1;
			break;
		}
		if (A[r][c] == k) {	//A[r][c] = k 라면 T 출력 후 while문을 빠져나온다.
			cout << T;
			break;
		}
		if (C_new > R_new) {	//C 연산
			transpose();
			R_new = Sort(A_T, C_new, R_new);
			reset();
		}
		else {	//R 연산
			C_new = Sort(A, R_new, C_new);
		}
		T++;	//increment T by 1
	}

	if (T == -1) {
		cout << -1;
	}

	return 0;
}