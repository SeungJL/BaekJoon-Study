#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Number {
	string num;
	int strike;
	int ball;
};
vector <Number> numbers;
vector <string> ans;

bool check(string str)
{
	if (str[0] == '0' || str[1] == '0' || str[2] == '0')
		return false;
	if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0])
		return false;
	return true;
}

bool compare(string str, string num, int s, int b)
{
	int i, j, s_cnt = 0, b_cnt = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (str[i] == num[j]) {
				if (i == j) {
					s_cnt++;
				}
				else {
					b_cnt++;
				}
			}
		}
	}

	if (s_cnt == s && b_cnt == b) {
		return true;
	}
	else {
		return false;
	}
}

int main(void)
{
	int N, strike, ball;
	string str, tmp;
	bool flag;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str >> strike >> ball;
		Number number;
		number.num = str;
		number.strike = strike;
		number.ball = ball;
		numbers.push_back(number);
	}

	for (int i = 123; i <= 987; i++) {
		flag = true;
		tmp = to_string(i);
		if (!check(tmp)) {
			continue;
		}
		else {
			for (int j = 0; j < N; j++) {
				if (!compare(tmp, numbers[j].num, numbers[j].strike, numbers[j].ball)) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			ans.push_back(tmp);
		}
	}

	cout << ans.size();

	return 0;
}