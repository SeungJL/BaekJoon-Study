/*
https://www.acmicpc.net/problem/2531
백준 2531 : 회전초밥
https://velog.io/@jeongopo/%EB%B0%B1%EC%A4%80-2531-%ED%9A%8C%EC%A0%84%EC%B4%88%EB%B0%A5
슬라이딩 윈도우를 활용하여 윈도우의 첫 인덱스를 0~N-1 까지 증가시켜가며 그때의 최댓값을 기록함
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> table(N);
	vector<int> repeatcheck(d+1); //숫자가 있는 개수만큼 값을 넣을 배열
	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}
	fill(repeatcheck.begin(), repeatcheck.end(), 0); //배열의 값을 모두 0으로 초기화

	int count = 0;
	int maxcount = 0;

 	//가장 초기 값을 한 번만 구한다
	for (int i = 0; i < k; i++) {
		if (repeatcheck[table[i]] == 0 ) {
			count++;
		}
		repeatcheck[table[i]]++;
	}
	if (repeatcheck[c] == 0)	count++;
	maxcount = count;


	for (int i = 1 ; i < N; i++) { //회전 시작점을 i라고 하고, 오른쪽으로 슬라이드
		int outnum, innum;
		outnum = table[(i - 1)%N];
		innum = table[(i + k - 1)%N];
		repeatcheck[outnum]--; //나가는 숫자의 개수를 빼준다
		
		//쿠폰으로 받는 초밥이 연속행에서 전부 빠졌으면 이제 쿠폰으로 받을 수 있다
		if (outnum == c && repeatcheck[outnum] == 0) {
			count++;
		}
		//쿠폰으로 받아야 하는 초밥이 연속행에 들어와버리면 쿠폰으로 못받는다
		if (innum == c && repeatcheck[innum] == 0) {
			count--;
		}
		//들어오고 나가는 초밥에 대해 count값을 처리한다
		if (repeatcheck[outnum] <= 0)	count--;
		if (repeatcheck[innum] <= 0)	count++;
		//새롭게 들어온 값인지 체크하기 위해 뒤에 더해준다
		repeatcheck[innum]++;
		//그 중 종류의 최댓값을 채택한다
		maxcount = max(count, maxcount);
	}
	cout << maxcount << "\n";
	return 0;
}
