#include <iostream>

using namespace std;
int arr[21];
int N; int S;
int cnt = 0;
bool visit = 0;
void sequenceSum(int pos, int sum) {
    if (sum == S && visit == 1) {
        cnt++;
    }
    if (pos == N) {
        return;
    }
    visit = 1;
    sequenceSum(pos + 1, sum + arr[pos]);
    visit = 0;
    sequenceSum(pos + 1, sum);
}

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sequenceSum(0, 0);

    cout << cnt;
    return 0;
}