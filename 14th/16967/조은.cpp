#include <iostream>
using namespace std;

int A[301][301];
int B[602][602];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	for(int i=1; i<=(H+X); i++)
		for(int j=1; j<=(W+Y); j++)
			cin >> B[i][j];
	
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			A[i][j] = B[i][j];
		}
	}

	int h = H + X - H + 1;
	int w = W + Y - W + 1;
	//cout << "h = " << h << ", w = " << w << endl;
	for(int i=h; i<=H; i++) {
		for(int j=w; j<=W; j++) {
			//cout << "A[i-X][j-Y] = A[" << i-X << "][" << j-Y << "] = " << A[i-X][j-Y] << endl;
			A[i][j] -= A[i-X][j-Y];
		}
	}

	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}