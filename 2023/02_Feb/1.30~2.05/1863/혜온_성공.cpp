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
			for (int j = yy; j > y; j--)// ���� ���� y ���� �� ���� ���̴� ���ο� �ǹ��̹Ƿ� �� ���� ���̸� set���� ����
			{
				if (city.find(j) != city.end())//�����ϸ�
					city.erase(j);
			}
		}

		if (y == 0)//���̸� ��� ���� ����
		{
			city.clear();

		}
		else if (city.find(y) == city.end())//������ ���� ���̶��
		{

			ans++;
			city.insert(y);
		}
		xx = x; yy = y;

	}
	cout << ans;
}