#include <iostream>
#include <string>

using namespace std;

int columnMove[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int rowMove[8] = {0, 0, -1, 1, 1, 1, -1, -1};

struct Chess {
	int column;	//열 (알파벳)
	int row;		//행 (숫자)
	Chess(string s) {
		this->column = (s[0] - 'A');
		this->row = (s[1] - '1');
	}
	string location() {		//현재 위치 반환
		string s;
		s += (char)(column + 'A');
		s += (char)(row + '1');
		return s;
	}
	string ifMove(string way) {		//만약 이동할 시 좌표 반환. 만약 체스판을 벗어나 이동 못할 경우 "X"반환
		int status;
		if (way == "R") status = 0;
		else if (way == "L") status = 1;
		else if (way == "B") status = 2;
		else if (way == "T") status = 3;
		else if (way == "RT") status = 4;
		else if (way == "LT") status = 5;
		else if (way == "RB") status = 6;
		else if (way == "LB") status = 7;
		int x = column + columnMove[status];
		int y = row + rowMove[status];
		if (x < 0 || x >= 8 || y < 0 || y >= 8) return "X";
		else {
			string s;
			s += (char)(x + 'A');
			s += (char)(y + '1');
			return s;
		}
	}
	void move(string way) {		//이동
		int status;
		if (way == "R") status = 0;
		else if (way == "L") status = 1;
		else if (way == "B") status = 2;
		else if (way == "T") status = 3;
		else if (way == "RT") status = 4;
		else if (way == "LT") status = 5;
		else if (way == "RB") status = 6;
		else if (way == "LB") status = 7;
		column += columnMove[status];
		row += rowMove[status];
	}
};

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	Chess king(str1);
	Chess stone(str2);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {

		string inputStr;
		cin >> inputStr;
		string result = king.ifMove(inputStr);
		if (result == "X") continue;		//만약 king이 체스판을 벗어나게 되면
		if (result == stone.location()) {			//만약 king위치가 stone와 같아지면 stone을 움직이기 
			if (stone.ifMove(inputStr) == "X") continue;		//만약 stone이 체스판을 벗어나게 되면
			stone.move(inputStr);
			king.move(inputStr);
		}
		else
			king.move(inputStr);
	}

	cout << king.location() << '\n' << stone.location() << endl;
	return 0;
}