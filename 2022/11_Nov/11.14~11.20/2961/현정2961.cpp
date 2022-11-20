
/*
221118
백준 2961 : 맛있는 음식
https://www.acmicpc.net/problem/2961
*/

#include <iostream>
#include <vector>
using namespace std;


/**
* @brief index 번째의 재료를 넣거나 넣지 않았을 때의 맛의 차이를 구하는 함수
*
* @param {vector<pair<int, int>>} Ingredients : 각 재료들의 <쓴맛, 신맛> 데이터
* @param {int} index : 현재 넣을지말지 결정할 인덱스 값
* @param {int} nowS : 현재까지의 쓴맛
* @param {int} nowC : 현재까지의 신맛
* @param {int*} ret : 결과값을 담을 ret 포인터
**/
void FindMinSub(vector<pair<int, int>> Ingredients,int index, int nowS,int nowC, int* ret) {
	if (index == Ingredients.size()) {
		return;
	}

	FindMinSub(Ingredients, index + 1, nowS, nowC, ret); //재료를 넣지 않는 경우

	nowS *= Ingredients[index].first; //재료를 넣는 경우, 그 재료를 포함하여 합연산, 곱연산을 한다
	nowC += Ingredients[index].second;
	*ret = min(*ret, abs(nowS - nowC));

	FindMinSub(Ingredients, index + 1, nowS, nowC, ret);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int ret = -1;

	vector<pair<int, int>> Ingredients(n); //재료들의 <신맛 , 쓴맛>
	for (int i = 0; i < n; i++) {
		int s, c;
		cin >> s >> c;
		Ingredients[i] = make_pair(s, c);

		//값을 넣으면서 재료가 1개씩 들어간 경우 중 최솟값으로 ret의 초기값을 설정한다
		if (ret == -1) ret = abs(s - c);
		else ret = min(ret, abs(s - c));
	}

	FindMinSub(Ingredients, 0, 1, 0, &ret);
	cout << ret << "\n";
	return 0;
}
