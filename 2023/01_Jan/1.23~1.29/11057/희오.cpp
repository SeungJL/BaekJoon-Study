// https://hio9105.tistory.com/entry/BOJ-11507-%EC%98%A4%EB%A5%B4%EB%A7%89-%EC%88%98-dp

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);
	
    int N, answer = 0;
    vector<int> prev(10);
	vector<int> cur(10);
    
    /* input */
	cin >> N;
	N--;
	for (int i=0; i<10; i++) {
		prev[i] = i+1;
		cur[i] = i+1;
	}
    
	/* solve */
	while (N--) {
		cur[0] = prev[9];
		for (int i=1; i<10; i++) {
			// 10007로 나눈 나머지를 저장
			// prev[9] <= prev[i-1] -> diff = prev[9] + 10007 - prev[i-1] 
			int diff = prev[9] - prev[i-1]; 
			if (diff <= 0) diff += 10007; 
			cur[i] = (cur[i-1] + diff) % 10007;
		}
		prev = cur;
	}

	cout << cur[9] << "\n";
}