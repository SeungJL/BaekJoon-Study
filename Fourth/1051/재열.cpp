#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int square[n][m];		//직사각형의 각 위치의 숫자정보
	map<int,vector<pair<int,int>>> info;	//키가 '숫자', 값이 '{좌표1,좌표2}의 벡터' 인 맵

	for (int i = 0; i < n; i++) {
		string inputStr;
		cin >> inputStr;
		for (int j = 0; j < m; j++) {
			square[i][j] = inputStr[j] - '0';
			info[inputStr[j]-'0'].push_back({i, j});
		}
	}

	int maxLength = 1;		//만들수 있는 정사각형 최댓값 기록 (그 때의 한변의 길이)
	for (auto x : info) {		//info에 담긴 모든 {키,값} 에 대해
		if (x.second.size() >= 4) {		//그 숫자의 점이 4개 이상 있으면
			int tempMax = 1;
			for (auto point : x.second) {		
				int len = 2;
				while (point.first + (len-1) < n && point.second + (len-1) < m) {		//영역을 넘지 않을 때까지
					//len-1만큼 우상단, 좌하단, 우하단만큼 떨어진 점이 전부 현재 숫자와 같은지 판단.
					if (square[point.first][point.second + (len-1)] == x.first	
							&& square[point.first + (len-1)][point.second] == x.first		
							&& square[point.first + (len-1)][point.second + (len-1)] == x.first	
					) {
						tempMax = max(tempMax, len);		//갱신
					}
					len++;
				}
			}
			maxLength = max(maxLength, tempMax);		//더 크면 갱신
		}
	}

	cout << maxLength * maxLength << endl;

	return 0;
}
