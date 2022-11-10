#include <iostream>
#include <string>
#define MIN 123
#define MAX 987
using namespace std;

typedef struct baseball_game{
	string input;
	int strike, ball;
} bg;

int N;
bool arr[MAX+1];

bool check_strike(string input, string ans, int strike) {
	int count = 0;
	if (input[0] == ans[0]) count++;
	if (input[1] == ans[1]) count++;
	if (input[2] == ans[2]) count++;
	
	if (count == strike) return true;
	else return false;
}

bool check_ball(string input, string ans, int ball) {
	int count = 0;
	if ((input[0] == ans[1]) || (input[0] == ans[2])) count++;
	if ((input[1] == ans[0]) || (input[1] == ans[2])) count++;
	if ((input[2] == ans[0]) || (input[2] == ans[1])) count++;

	if (count == ball) return true;
	else return false;
}

void init_arr() {
	fill(arr+MIN, arr+MAX+1, true);

	for(int i=MIN; i<=MAX; i++) {
		string ans = to_string(i);
		if ((ans[0] == '0') || (ans[1] == '0') || (ans[2] == '0') ||
			(ans[0] == ans[1]) || (ans[0] == ans[2]) || (ans[1] == ans[2])) {
			arr[i] = false;
		}
	}

	return;
}

int main() {
	int N;
	cin >> N;

	init_arr();

	while (N--) {
		bg game;
		cin >> game.input >> game.strike >> game.ball;
		for (int i=MIN; i<=MAX; i++) {
			if (!check_strike(game.input, to_string(i), game.strike)) arr[i] = false;
			else if (!check_ball(game.input, to_string(i), game.ball)) arr[i] = false;
		}
	}

	int cnt = 0;
	for(int i=MIN; i<=MAX; i++) {
		if (arr[i]) cnt++;
	}
	cout << cnt;

	return 0;
}