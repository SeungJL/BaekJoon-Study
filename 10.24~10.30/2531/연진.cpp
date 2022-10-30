#include <iostream>
#include <vector>
using namespace std;

int N, d, k, c;	// 접시 수, 초밥 가짓수, 연속 개수, 쿠폰 번호
vector<int> v;	// 초밥들
int sushiTypes[3000]={0,};
int dish[3000]={0,};
int answer=0;
int cnt=0;


int init(){
	int initCnt=0;
	for(int i=0;i<d;i++){
		if(dish[i]>0){
			initCnt++;
		}
	}
	if(initCnt>=k) initCnt=k;

	return initCnt;
}

void get_types(int front, int last){
	sushiTypes[front]--; 
	if(sushiTypes[front]==0) cnt--;
	if(sushiTypes[last]==0) cnt++;
	sushiTypes[last]++;
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> d >> k >> c;

	for(int i=0;i<N;i++){
		int t;
		cin >> t;
		v.push_back(t);
		dish[t]++;
	}
	answer=init();
	// init  앞d개 붙이기, 맨 처음 k개먹을 때 가지수구하기
	sushiTypes[c]=1;
	cnt++;
	for(int i=0;i<k;i++){	
		v.push_back(v[i]);

		if(sushiTypes[v[i]]==0) cnt++;
		sushiTypes[v[i]]++;
	}
	if(answer<cnt) answer=cnt;

	for(int i=0;i<N-1;i++){
		get_types(v[i], v[k+i]);
		if(answer<cnt) answer=cnt;
	}


	cout << answer;

	return 0;
}