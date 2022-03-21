#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	int kind[N+1];
	for (int i = 0; i < N; i++) 
		cin >> kind[i];		
	
	deque<int> results;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (kind[i] == 0) 
			results.push_back(n);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		results.push_front(x);
		printf("%d ", results.back());
		results.pop_back();
	}
	cout << endl;

	return 0;
}