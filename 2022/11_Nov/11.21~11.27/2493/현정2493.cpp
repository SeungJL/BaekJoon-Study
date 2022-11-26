#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    stack<pair<int, int> > s;  // <위치, 높이>
    int n, height;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> height;

        while (!s.empty()) {
            if (height < s.top().second) {  // 현재 높이보다 큰 탑이 있다면 해당 높이에 레이저를 쏘고 뽑는다
                cout << s.top().first << " ";
                break;
            }
            //레이저 받는 탑이 있을때까지 계속 뽑는다. 어차피 여기서 택해지지않으면, 지금 건물에 의해 가려질것이다
            s.pop();
        }
        if (s.empty()) {
            cout << 0 << " ";
        }
        s.push(make_pair(i + 1, height));
    }

	return 0;


}
