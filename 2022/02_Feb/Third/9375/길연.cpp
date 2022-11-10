#include<iostream>
#include<map>
#include<string>


using namespace std;



int main()
{

	int num, test;
	int ans;
	string wear_name, category;

	cin >> test; 

	
	while (test--)
	{
		map<string, int> map;	// < 의상 종류,의상 수 >

		cin >> num;		// 의상 수

		ans = 1; 

		for (int i = 0; i < num; i++)
		{
			cin >> wear_name >> category;

			if (map.find(category) == map.end())
				map[category] = 1;

			else // 해당 key값이 존재할 경우
				map[category]++;

		}

		for (auto iter : map) // iter.first = key, iter.second = value
			ans *= (iter.second + 1); // +1 : 선택안하는 경우

		cout << ans - 1 << "\n";
	}
}
