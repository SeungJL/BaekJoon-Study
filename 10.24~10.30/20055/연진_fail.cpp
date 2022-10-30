#include <iostream>
using namespace std;

int N, K;
int answer=1;
int belt[200];	// 내구도
int robot[200] = {	// 로봇 여부
		0,
};
int zero_cnt = 0;

bool updateZeroCnt(int idx)
{
	robot[idx] = 0;
	zero_cnt++;
	if (zero_cnt == K) { // The End
		cout << answer;
		return true;
		}

	return false;
}

int main()
{
	int start = 0;

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
	{
		int k;
		cin >> k;
		belt[i] = k;
	}

	while (zero_cnt < K)
	{
		// 1. 한칸 회전 및 N칸 로봇 내리기
		start = start - 1 < 0 ? (2 * N - 1) : (start - 1);
		int end = (start + N - 1) % (2 * N);
		if (robot[end] == 1)	// 내리는 칸에 로봇있는지 확인
		{
			if(updateZeroCnt(end)) ;
		}

		// 2. 로봇들 한칸 이동하기
		int moveIdx=end-1;
		for(int i=0;i<N;i++){
			if (robot[moveIdx+1]==0 && ){
				
			}
		}



		answer++;
	}

	return 0;
}