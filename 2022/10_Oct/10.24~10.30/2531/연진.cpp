#include <iostream>
#include <vector>
using namespace std;

int N, d, k, c;	// 접시 수, 초밥 가짓수, 연속 개수, 쿠폰 번호
vector<int> v;	// 초밥들
int sushiTypes[3000]={0,};
int answer=0;
int cnt=0;

void get_types(int front, int last){
	sushiTypes[front]--; 		// 맨 앞 초밥 빼기
	if(sushiTypes[front]==0) cnt--;
	if(sushiTypes[last]==0) cnt++;	// 그 다음 초밥 추가
	sushiTypes[last]++;
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> d >> k >> c;

	// 회전초밥벨트 위 초밥 입력
	for(int i=0;i<N;i++){
		int t;
		cin >> t;
		v.push_back(t);
	}

	// init  앞 d개 붙이기, 맨 처음 k개먹을 때 가지수구하기
	sushiTypes[c]=1;
	cnt++;
	for(int i=0;i<k;i++){	
		v.push_back(v[i]);

		if(sushiTypes[v[i]]==0) cnt++;
		sushiTypes[v[i]]++;
	}
	answer=cnt;

	for(int i=0;i<N;i++){ // 다음 k 개 칸으로 이동하면서 진행
		get_types(v[i], v[k+i]);
		if(answer<cnt) answer=cnt;
	}
	cout << answer;

	return 0;
}