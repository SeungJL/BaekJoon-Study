#include<iostream>
#include<vector>

using namespace std;

int N, cnt;
int temp, x = 0, root = 0;

vector<int>tree[51];
int check[51];
int a = 0;
void dfs(int node)
{
	check[node] = true;
	//cout << "  " << node << endl;
	if (tree[node].size() == 0 || tree[node].size() == 1 && tree[node][0] == x)
	{
		//cout << node << endl;
		cnt++;
		return;
	}

	for (int i = 0; i < tree[node].size(); i++)
	{
		if (!check[tree[node][i]])
		{

			dfs(tree[node][i]);


		}


	}
}
//Ʈ�� , ���5
int main()
{
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == -1)
		{
			root = i;
			continue;
		}
		//temp�� �θ�, i�� �ڽ� ��� ��ȣ
		tree[temp].push_back(i);
	}

	cin >> x;
	if (x == root)
	{
		cout << 0;
		return 0;
	}
	check[x] = true;
	tree[x].clear();
	dfs(root);



	cout << cnt;
}