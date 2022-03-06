//백준 13015
//별 찍기 - 23
//태그: 구현
//난이도: 실버5

#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	string strs[2*N+1];

	//첫번째, 마지막 줄엔 N만큼 * 출력 후 2*(N-1)-1만큼 공백 출력 후 다시 N만큼 *출력
	string s = "";
	for (int i = 0; i < N; i++)
		s += '*';
	for (int i = 0; i < 2 * (N-1) - 1; i++) 
		s += ' ';
	for (int i = 0; i < N; i++)
		s += '*';
	strs[1] = s;
	strs[2*N-1] = s;

	//N번째 줄에선, 공백 N-1번 * 1번, 공백 N-2번, * 1번, 공백 N-2번, * 1번
	s = "";
	for (int i = 0; i < N-1; i++)
		s += ' ';
	s += '*';
	for (int i = 0; i < N-2; i++) 
		s += ' ';
	s += '*';
	for (int i = 0; i < N-2; i++) 
		s += ' ';
	s += '*';
	strs[N] = s;
	
	//중간에 있는 줄이면, 'i또는 2n-i'번째 줄일 시, "공백 i-1번, * 1번, 공백 N-2번, * 1번, 공백 2*(N-i)-1번, ..." 입력
	for (int i = 2; i <= N-1; i++) {
		string s = "";
		for (int j = 0; j < i-1; j++) 
			s += ' ';
		s += '*';
		for (int j = 0; j < N-2; j++)
			s += ' ';
		s += '*';
		for (int j = 0; j < 2*(N-i)-1; j++)
			s += ' ';
		s += '*';
		for (int j = 0; j < N-2; j++)
			s += ' ';
		s += '*';
		strs[i] = s;
		strs[2*N - i] = s; 
	}

	for (int i = 1; i <= 2*N-1; i++)
		cout << strs[i] << '\n';

	return 0;
}