#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s1; //커서의 왼쪽 부분 문자열
stack<char> s2;	//커서의 오른쪽 부분 문자열
string str;


int main(void)
{
	int M; char c;
	cin >> str;
	int N = str.length();
	for (int i = 0; i < N; i++) {
		s1.push(str[i]); //초기 커서의 위치는 문장의 맨 뒤이므로 s1에 push
	}
	cin >> M;	//명령어의 개수 입력
	while (M--) {
		cin >> c;
		if (c == 'L') {
			if (!s1.empty()) {	//커서가 문장의 맨 앞이 아니라면
				s2.push(s1.top());	//커서 오른쪽에 있는 문자를 s2에 push
				s1.pop();
			}
		}
		else if (c == 'D') {
			if (!s2.empty()) {	//커서가 문장의 맨 뒤가 아니라면
				s1.push(s2.top());	//커서 왼쪽에 있는 문자를 s1에 push
				s2.pop();
			}
		}
		else if (c == 'B') {
			if (!s1.empty()) {	//커서가 문장의 맨 앞이 아니라면
				s1.pop();	//커서 왼쪽에 있는 문자를 삭제
			}
		}
		else {
			char alp;	//$라는 문자
			cin >> alp;
			s1.push(alp);	//커서의 왼쪽에 추가
		}
	}

	while (!s1.empty()) {	//s1을 하나씩 s2로 push하면서 문자열 합치기
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {	//s2를 하나씩 pop하면서 문자열 출력
		cout << s2.top();
		s2.pop();
	}
	
	return 0;
}