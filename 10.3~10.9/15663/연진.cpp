#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M; // 입력 개수, 길이
pair<int, int> arr[8]; // 0: num, 1: count
vector<int> answer;
int arr_size = 0;

void getAnswer(int len)
{
	if (len == M)
	{ // 길이가 M에 다르면 답을 출력해준다.
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i].second != 0)
		{
			arr[i].second--;
			answer.push_back(arr[i].first);
			getAnswer(len + 1);
			answer.pop_back();
			arr[i].second++;
		}
	}
}

int main()
{
	cin >> N >> M;
	map<int, int> m; // num count
	for(int i=0;i<8;i++) arr[i].first=0;	// initialize
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		bool is_new_k = true;
		for (int j = 0; j < 8; j++)
		{
			if (arr[j].first == k)
			{
				arr[j].second++;
				is_new_k=false;
			}
		}
		if (is_new_k)
		{
			arr[arr_size].first = k;
			arr[arr_size].second = 1;
			arr_size++;
		}
	}
	sort(arr, arr+arr_size);

	for (auto iter=m.begin();iter!=m.end();iter++)
	{ // map -> arr
		arr[arr_size].first = iter->first;
		arr[arr_size].second = iter->second;
		arr_size++;
	}

	getAnswer(0);

}