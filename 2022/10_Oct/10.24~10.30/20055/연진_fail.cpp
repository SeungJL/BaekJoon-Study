#include <iostream>
using namespace std;

int N, K;
int answer = 1;
int belt[200]; // 내구도
int robot[200] = {
		// 로봇 여부
		0,
};
int zero_cnt = 0;	// 내구도 0인 칸의 개수

int main()
{
	int start = 1;

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
	{
		int b;
		cin >> b;
		belt[i] = b;
	}

	while (zero_cnt < K)
	{
		// 1. 한칸 회전 및 N칸 로봇 내리기
		start = (start - 1 < 0) ? (2 * N - 1) : (start - 1);
		int end = (start + N - 1) % (2 * N);
		if (robot[end] == 1) // 내리는 칸에 로봇있는지 확인
		{
			if (robot[end] == 1)
			{
				robot[end] = 0;
			}
		}

		// 2. 로봇들 한칸 이동하기
		int moveIdx = end-1;
		for (int i = 1; i < N; i++)
		{
			int nextIdx = moveIdx+1;
			moveIdx = (moveIdx-1) < 0 ? (2*N-1) : (moveIdx-1);
			if (robot[nextIdx] == 0 && belt[nextIdx] > 0)
			{
				robot[moveIdx] = 0;
				robot[nextIdx] = 1;
				if (belt[nextIdx] == 1) zero_cnt++;
				belt[nextIdx]--;
			}
		}
		if (robot[end] == 1) robot[end] = 0; // 마지막칸에 로봇 있으면 내리기

		// 3. 로봇 올리기. 내구도 0아닐 경우
		if (belt[start] > 0 && robot[start]==0)
		{
			robot[start] = 1;
			if(belt[start]==1) zero_cnt++;
			belt[start]--;
		}

		// 4. 내구도 0이 k 이상이면 종료

		answer++;
	}

	cout << answer;

	return 0;
}