// 백준 1543번 문서 검색

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	string docu, word;
	getline(cin, docu);
	getline(cin, word);

	int size = word.size();
	int cnt = 0;

	if (docu.size() < word.size()) { // 문서 길이보다 단어 길이가 더 길다면 끝냄
		cout << 0 << endl;
		return 0;
	}

	// string::find 찾는 문자열의 첫번째 인덱스 반환하는 함수
	// string::npos 찾는 문자열이 없는 경우에는 string::npos 반환
	// substr(index, length) index부터 length까지 잘라줌

	while(docu.find(word) != string::npos){ // docu안에 word가 없을 때까지 반복
		int tmp = docu.find(word); // docu안에 있는 word의 첫번째 인덱스 반환
		cnt++;
		docu = docu.substr(tmp + word.length(), docu.length());
	}

	cout << cnt << endl;

	return 0;
}
