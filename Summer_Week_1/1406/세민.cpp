#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s1; //Ŀ���� ���� �κ� ���ڿ�
stack<char> s2;	//Ŀ���� ������ �κ� ���ڿ�
string str;


int main(void)
{
	int M; char c;
	cin >> str;
	int N = str.length();
	for (int i = 0; i < N; i++) {
		s1.push(str[i]); //�ʱ� Ŀ���� ��ġ�� ������ �� ���̹Ƿ� s1�� push
	}
	cin >> M;	//��ɾ��� ���� �Է�
	while (M--) {
		cin >> c;
		if (c == 'L') {
			if (!s1.empty()) {	//Ŀ���� ������ �� ���� �ƴ϶��
				s2.push(s1.top());	//Ŀ�� �����ʿ� �ִ� ���ڸ� s2�� push
				s1.pop();
			}
		}
		else if (c == 'D') {
			if (!s2.empty()) {	//Ŀ���� ������ �� �ڰ� �ƴ϶��
				s1.push(s2.top());	//Ŀ�� ���ʿ� �ִ� ���ڸ� s1�� push
				s2.pop();
			}
		}
		else if (c == 'B') {
			if (!s1.empty()) {	//Ŀ���� ������ �� ���� �ƴ϶��
				s1.pop();	//Ŀ�� ���ʿ� �ִ� ���ڸ� ����
			}
		}
		else {
			char alp;	//$��� ����
			cin >> alp;
			s1.push(alp);	//Ŀ���� ���ʿ� �߰�
		}
	}

	while (!s1.empty()) {	//s1�� �ϳ��� s2�� push�ϸ鼭 ���ڿ� ��ġ��
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {	//s2�� �ϳ��� pop�ϸ鼭 ���ڿ� ���
		cout << s2.top();
		s2.pop();
	}
	
	return 0;
}