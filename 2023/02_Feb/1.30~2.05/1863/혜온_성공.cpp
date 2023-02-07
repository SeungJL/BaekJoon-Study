#include<iostream>
#include<set>


using namespace std;


int n, ans;
int main()
{


	cin >> n;
	int x, y;
	set<int>city;
	int xx = 0, yy = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		if (y < yy)
		{
			for (int j = yy; j > y; j--)// 새로 나온 y 보다 더 높은 높이는 새로운 건물이므로 더 높은 높이를 set에서 삭제
			{
				if (city.find(j) != city.end())//존재하면
					city.erase(j);
			}
		}

		if (y == 0)//땅이면 모든 높이 삭제
		{
			city.clear();

		}
		else if (city.find(y) == city.end())//나오지 않은 높이라면
		{

			ans++;
			city.insert(y);
		}
		xx = x; yy = y;

	}
	cout << ans;
}