#include <bits/stdc++.h>

using namespace std;

// <첫 원소와 공차를 이용하여 해당 수열에 N이 포함되는지의 여부를 확인>
int main() {
    int N;
    scanf("%d", &N);

    /*조합할 숫자의 개수.
     * ex) 1 / 2 / 3 -> cnt = 1
     * 1+2 / 2+3 / 3+4 -> cnt = 2
     * 1+2+3 / 2+3+4 / 3+4+5 -> cnt = 3
     * */
    int cnt = 1;

    //N을 연속된 자연수의 합으로 나타낼 수 있는 가지수
    int result = 0;

    while (true) {
        /*
         * ex) cnt = 2인 경우,
         * 1+2 / 2+3 / 3+4
         * = 3 / 5 / 7
         * 첫 원소는 cnt*(cnt+1)/2 = 3 (sum)이며,
         * 다음 원소와는 cnt만큼의 공차가 있다.
         * 첫 원소가 N보다 크다면 확인할 필요가 없으니 반복문을 탈출한다.
         */
        int sum = cnt * (cnt + 1) / 2;
        if (sum > N) break;
        if ((N - sum) % cnt == 0) result++;
        cnt++;
    }

    printf("%d", result);
    return 0;
}
