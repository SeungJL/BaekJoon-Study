//배낀 답 한끝 차이인데 아래의 교훈을준 문제
/*outpu의 숫자가 높아 10007등으로 나뉘어야 하는 상황에서는 빼기나 나누기를 사용하면, 그 값이 나누어진것을 뺴서 마이나스가 나오는 오류가 생길 수 있다. 되도록이면 더하거나 곱하자.  */
#include <iostream>
using namespace std;

int main()
{
	int dp[10000][10] = {};
	int n;
	int sum = 0;

	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int j = 2; j <= n; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				dp[j][i] += dp[j - 1][k];
			}
			dp[j][i] %= 10007;
		}
	}
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) %10007;

	cout << sum %10007;
}
// 제가 푼 답 로직은 같으나 10007로 나누고, 빼기를 하는 과정에서 오류가 나는 상황. 이거 
// 해결 가능하신분 계실까요...
#include <iostream>
using namespace std;

int main(void)	
{
	int input;
	cin >> input;
	long long arr[1001][11];
	arr[0][10] = {10};
	long long now = 10;
	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += now;
		arr[1][i] = now--;
	}
	arr[1][10] = sum;

	for (int i = 2; i < input;i++)
	{
		arr[i][0] = arr[i - 1][10];
		sum = arr[i][0];
		for (int j = 1; j < 10; j++)
		{
			
			arr[i][j] = arr[i][j-1] - arr[i - 1][j - 1];
			sum += arr[i][j];
		}
		arr[i][10] = sum;
		for(int j=0;j<11;j++)arr[i][j]%=10007;
	}
	cout << arr[input-1][10];
}

