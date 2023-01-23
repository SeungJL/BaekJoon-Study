#include <iostream>
#include <queue>
#define OUTPUT 0
using namespace std;

// vector사용시 메모리 : 2916KB, 시간 16ms
// deque 사용시 메모리 : 2552KB, 시간 20ms

int main(void)	
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	/* priority_queue<int,deque<int>,greater<int> > q; */
	priority_queue<int,vector<int>,greater<int> > q;
	while(n--)
	{
		int input;
		cin >> input;
		if(input==OUTPUT)
		{
			if(q.empty())
				cout << OUTPUT << '\n';
			else{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else{
			q.push(input);
		}
	}
}