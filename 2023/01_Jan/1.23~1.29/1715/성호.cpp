#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>>q;
	int n,a,ans=0;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		q.push(a);
	}
	for(int i=0;i<n-1;i++)
	{
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ans+=x+y;
		q.push(x+y);
	}
	cout<<ans;

	return 0;
}