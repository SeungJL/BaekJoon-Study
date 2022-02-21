// 백준 11501번 주식

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;

	int day;
	vector<int> price;
	
	while (t--) {
		cin >> day;
		for (int i = 0; i < day; i++) { // 날 별로 주가 입력
			int p;
			cin >> p;
			price.push_back(p);
		}
	
		//예를 들어 날 수가 3일이고 날 별로 주가가 10, 7, 6일 때, 주가가 계속 감소하므로 최대 이익은 0이 된다. 
		// 주가가 가장 높은날 팔아야함 -> 가장 큰 값찾기 23423 이면 뒤에 큰값나올지 작은값나올지 케이스 나눠줘야함
		// 뒤에서부터보면 더 쉬움 2<3 이니까 이익발생 -> 마지막꺼 == max로 하고 그전꺼 [i]로
		// max - [i] 하면 이익실현, 그 다음 4>2이니까 사면 ㄴㄴ

		long long ans = 0;
		int max = price.back();

		for (int i = price.size() - 2; i >= 0; i--) { // price.size()-1 == price.back()
			
			if (price[i] > max) {  // 현재값이 max보다 크다면 (ex) 2 4 3 
				max = price[i];
			}
			else if (price[i] < max) // 현재값이 뒤의 max보다 작다면 (ex)2 2 4
				ans = ans + (max - price[i]);
			else
				continue;

		}
			cout << ans << endl;
			price.clear();
	}
	return 0;
}
