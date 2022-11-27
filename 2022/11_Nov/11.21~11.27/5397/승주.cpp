#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	string userInput;

	cin >> T;
	while (T--) {
		deque <char> D;
		cin >> userInput;
		char word = 0;
		int moveToFront = 0;
		for (int i = 0; i < userInput.length(); i++) {
			word = userInput[i];
			if (word >= 'A' || ('0' <= word && word <= '9'))
				D.push_back(word);
			else if (word == '-') {
				if (D.size() == 0 || moveToFront >= D.size()) continue;
				D.pop_back();
			}
			else if (word == '<') {
				if (D.size() == 0 || moveToFront >= D.size()) continue;
				moveToFront++;
				D.push_front(D.back());
				D.pop_back();
			}
			else if (word == '>') {
				if (D.size() == 0 || moveToFront == 0) continue;
				moveToFront--;
				D.push_back(D.front());
				D.pop_front();
			}
		}
		for (int i = 0; i < moveToFront; i++) {
			D.push_back(D.front());
			D.pop_front();
		}
		int temp = D.size();
		for (int i = 0; i < temp; i++) {
			cout << D.front();
			D.pop_front();
		}
		cout << '\n';
	}
}