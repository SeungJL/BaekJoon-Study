#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
int rock[10] = {
		0,
};

void init() {
	for(int i=0;i<M;i++) rock[i]=1;
}

void make_pair(int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
			cout << num[i];
		cout << "\n";
		return;
	}

	int last = 0;


	return;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		num[i]=k;
	}
	sort(num, num+10);
	init();
	make_pair(0);

	return 0;
}