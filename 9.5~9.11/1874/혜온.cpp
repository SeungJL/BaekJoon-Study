#include<iostream>
#include<vector>
#include <stack>
using namespace std;
vector<char> ans;
stack<int>s;

int n;
int num[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];

	int index = 1;
	bool check = false;
	int top = 0;
	for (int i = 1; i <= n; i++)
	{

		if (i != num[index])
		{
			ans.push_back('+');
			s.push(i);
		}
		else
		{
			ans.push_back('+');
			s.push(i);


			while (num[index] <= i && index <= n)
			{

				//if (index + 1 <= n && num[index + 2]<i && num[index + 2] > num[index+1 ]) { cout << "NO" << endl; return 0; }
				//if (index + 1 <= n &&!check&& num[index + 1] < i && top != num[index + 1]) { cout << index; cout << "NO" << endl; return 0; }
				if (s.top() != num[index]) { cout << "NO" << endl; return 0; }
				//cout << index << endl;
				ans.push_back('-');
				s.pop();
				index++;

			}
		}

	}

	if (ans.size() == 2 * n)
	{
		for (int i = 0; i < 2 * n; i++)
			cout << ans[i] << "\n";
	}
	else
		cout << "NO";

}