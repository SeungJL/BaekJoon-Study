

#include <iostream>
#include <list>
using namespace std;

/*
*@brief string 에 따라 list 에서 log에 따른 행동을 수행하고, 결과를 출력하는 함수
*@param{string} L : 입력받은 string 값
*/
void KeyLoggerAction(string L) {
	list<char> ret;
	auto iter = ret.begin();
	for (int i = 0; i < L.length(); i++) {
		switch (L[i])
		{
		case '<':
			if (iter != ret.begin())	iter--;
			break;
		case '>':
			if (iter != ret.end())	iter++;
			break;
		case '-':
			if (iter != ret.begin()) { //삭제시에는 --후에 해주는 것을 잊지말자
				iter--;
				iter = ret.erase(iter);
			}
			break;
		default:
			ret.insert(iter, L[i]);
			break;
		}
	}
	for (auto c : ret) {
		cout << c ;
	}
	cout << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string L;
		cin >> L;
		KeyLoggerAction(L);
	}
	return 0;


}
