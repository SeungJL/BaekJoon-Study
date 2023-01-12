#include<iostream>
#include<string>


using namespace std;

long long cnt;

int main()
{
	string s;

	cin >> s;
	int size = s.size();
	int r = 0;
	bool chk = false;
	//()(((()())(())()))(())
	for (int i = 0; i < size; i++)
	{
		if (s[i] == '(')
		{
			r++;
			chk = false;
		}
		else
		{
			if (!chk)
			{
				cnt += (r - 1);
				r--;
			}
			else
			{
				cnt++;
				r--;
			}

			chk = true;

		}
	}

	cout << cnt;
}