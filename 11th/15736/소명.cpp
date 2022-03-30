// 15736번: 청기 백기
#include <iostream>
using namespace std;
int n;

//약수의 갯수 리턴하는 함수
int func(int n)
{

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }

    return cnt;
    // }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int answer = 0;
        cin >> n;

        // 1부터 n까지 수 중에서 제곱수의 갯수 카운트
        for (int i = 1; i * i <= n; i++)
        {
            answer++;
        }

        cout << answer << "\n";
    }
    //약수 갯수가 홀수인것만 최종적으로 백색임.
    //약수 갯수 홀수라는건 제곱수 라는뜻.