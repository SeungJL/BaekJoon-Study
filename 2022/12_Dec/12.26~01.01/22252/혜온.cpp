#include<iostream>
#include<queue>
#include <map> 
#include<vector>
#include<string>
#include <algorithm>

using namespace std;


vector<int>arr[100001];
map<string, int> name;


int main()
{
	int n;
	cin >> n;
	int temp;
	string nn = "";
	int k = 0;
	long long sum = 0;
	int idx = 0, index = 0;
	int a;
	//7
//1 Cpp 5 10 4 2 8 4
//1 Java 2 8 2
//2 Cpp 2
//1 Cpp 2 10 3
//2 Cpp 3
//2 Java 1
//2 Python 10
	while (n--)
	{
		cin >> temp >> nn >> k;
		//�̸� ã��
		if (name.find(nn) != name.end())//������ ���° ���� ã����
		{
			index = name[nn];
		}
		else  //������ �̸� ����
		{

			name.insert({ nn, idx });
			index = idx;
			idx++;
		}
		if (temp == 1)
		{


			//���� ����
			while (k--)
			{
				cin >> a;
				arr[index].push_back(a);
			}

			//����
			sort(arr[index].begin(), arr[index].end());
		}
		else
		{
			//���� k�� ã�� sum�� ���ϱ�
			while (k--)
			{
				if (arr[index].size() > 0)
				{
					sum += arr[index].back();
					arr[index].pop_back();
				}
				else
					break;
			}
		}

	}
	cout << sum << endl;
}