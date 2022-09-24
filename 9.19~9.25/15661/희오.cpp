#include <iostream>

using namespace std;

int N, res = 100000;
int input[20][20];

int my_abs(int x) { return (x >= 0 ? x : -x); }

int get_sum(int comb, bool isZero) {
	int sum = 0;
	for (int i=0; i<N; i++) {
		if (((comb & (1 << i)) == 0) != isZero) continue;

		for (int j=i+1; j<N; j++) {
			if (((comb & (1 << j)) == 0) == isZero) sum += (input[i][j] + input[j][i]);
		}
	}
	
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

	cin >> N;
	for(int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> input[i][j];
		}
	}

	for (int comb = 1; comb < (1<<(N-1)); comb++) {
		int diff = my_abs(get_sum(comb, 0) - get_sum(comb, 1));
		if (diff < res) res = diff;

		/*/ prinf for checking
		for (int i=0; i<N; i++) { // group 1
			if ((comb & (1 << i)) != 0) cout << i << " ";
		}
		cout << "/ ";
		for (int i=0; i<N; i++) { // group 0
			if ((comb & (1 << i)) == 0) cout << i << " ";
		}
		cout << "/ sum0 = " << get_sum(comb, 0) << ", sum1 = " << get_sum(comb, 1);
		cout << "/ diff = " << diff << "\n";
        */
	}

	cout << res << "\n";

}