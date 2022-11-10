#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int TC;
	cin >> TC;

	while (TC--) {
		// init
		string p, input;
		int n, nums_i;

		cin >> p >> n >> input;
		nums_i = -1;
		vector<string> nums(n, "");
		for (auto e : input) {
			if (e == '[' || e == ']' || e == ',') nums_i++;
			else nums[nums_i] += e;
		}

		int sp = 0, ep = n-1, cur = sp;
		int reverse_sign = 1; // 1 - not reversed, -1 - reversed
		bool isError = false;

		// solve
		for (auto op : p) {
			switch (op)
			{
			case 'R':
				(reverse_sign == 1) ? cur = ep : cur = sp;
				reverse_sign *= -1;
				break;
			case 'D':
				if (sp <= ep) {
					nums[cur] = "";
					cur += reverse_sign;
					(reverse_sign == 1) ? sp++ : ep--;
				}
				else isError = true;
				break;
			default:
				break;
			}
			if (isError) break;
		}

		if (isError) cout << "error\n";
		else {
			cout << "[";
			if (sp <= ep) {
				if (reverse_sign == 1) {
					for (int i=sp; i<ep; i++) cout << nums[i] << ",";
					cout << nums[ep];
				}
				else {
					for (int i=ep; i>sp; i--) cout << nums[i] << ",";
					cout << nums[sp];
				}
			}
			cout << "]\n";
		}
	}
}