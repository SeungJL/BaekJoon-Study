/*
https://www.acmicpc.net/problem/20055
백준 20055 : 컨베이어 벨트 위의 로봇
https://velog.io/@jeongopo/%EB%B0%B1%EC%A4%80-20055-%EC%BB%A8%EB%B2%A0%EC%9D%B4%EC%96%B4-%EB%B2%A8%ED%8A%B8-%EC%9C%84%EC%9D%98-%EB%A1%9C%EB%B4%87
*/


#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> rail; //현재 레일의 내구도를 저장하는 배열
	list<int> robot; //로봇을 순서대로 기록한 리스트
	vector<bool> onuse(N * 2); //쓰이고 있다면 True값을 가진다

	for (int i = 0; i < N * 2; i++) {
		int input;
		cin >> input;
		rail.push_back(input);
	}
	
	int t = 1;
	while (1) {
		//1. 벨트의 로봇을 한 칸씩 회전시킨다
		fill(onuse.begin(), onuse.end(), false);
		//레일을 한번 회전시켜준다 = vector의 맨 뒷값을 가장 앞에 insert 해준다
		rail.insert(rail.begin(),rail[2*N-1]);
		rail.erase(rail.end()-1);

		for (auto iter = robot.begin(); iter != robot.end();) {
			*iter = (*iter+1)%(2*N);
			if (*iter == N-1) { //내리는 레일에 도달하면 내리기
				iter = robot.erase(iter);
				if(iter!=robot.begin()) iter--;
				if (robot.size() == 0)	break;
				continue;
			}
			onuse[*iter] = true;
			iter++;
		}

		//2. 가장 먼저 놓은 로봇부터 로봇을 한칸씩 이동시킨다
		for (auto iter = robot.begin(); iter != robot.end();) {
        //다른 로봇이 올라가있는지 / 레일의 내구도가 있는지 확인한다
			if (!onuse[*iter + 1]&&rail[(*iter+1)%(2*N)]>0) {
				onuse[*iter] = false;
				*iter = (*iter + 1) % (2 * N);
				rail[*iter]--;
				if (*iter == N-1) { //내리는 레일에 도달하면 내리기
					iter = robot.erase(iter);
					if (iter != robot.begin()) iter--;
					if (robot.size() == 0)	break;
					continue;
				}

				onuse[*iter] = true;
			}
			iter++;
		}
		//3. 올리는 위치(0번 인덱스)에 로봇을 하나 올린다
		if (!onuse[0] && rail[0] > 0) {
			rail[0]--;
			onuse[0] = true;
			robot.push_back(0);
		}
		//4. 내구도가 0인 칸의 개수가 K개 이상이라면, 종료한다
		int count = 0;
		for (int i = 0; i < rail.size(); i++) {
			if (rail[i] == 0)	count++;
		}
		if (count >= K) {
			cout << t << "\n";
			return 0;
		}
		t++;
	}
	return 0;
}
