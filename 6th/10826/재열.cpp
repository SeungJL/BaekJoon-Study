#include <iostream>
#include <string>
#include <stack>

using namespace std;

string dp[10001];

string stringPlus(string& n1, string& n2) {		//두 개의 문자열을 숫자 더하듯이 더해 문자열에 저장해 반환
	stack<int> result;		
	int extra = 0;		//받아올림용
	int n2Index = n2.size()-1;
	int n1Index = n1.size()-1;

	//n2가 더 큰 상황. 따라서 자릿수를 n2를 기준으로 생각
	while (n2Index >= 0) {
		int temp;
		if (n1Index >= 0) 
			temp = extra + (n2[n2Index]-'0') + (n1[n1Index]-'0');
		else 
			temp = extra + (n2[n2Index]-'0');
		
		if (temp >= 10) {
			extra = 1;
			result.push(temp - 10);
		}
		else {
			extra = 0;
			result.push(temp);
		}

		n2Index--;
		n1Index--;
	}
	//다 끝났는데 extra가 남으면 맨 앞에 붙여야
	if (extra > 0) 
		result.push(extra);
	
	string str;
	while (!result.empty()) {
		str += (static_cast<char>(result.top() + '0'));
		result.pop();
	}
	return str;
}

int main() {
	int n;
	cin >> n;
	fill(dp, dp+n, "");

	dp[0] = "0";
	dp[1] = "1";
	
	for (int i = 2; i <= n; i++) {
		dp[i] = stringPlus(dp[i-2], dp[i-1]);
	}
	
	cout << dp[n] << endl;

	return 0;
}
