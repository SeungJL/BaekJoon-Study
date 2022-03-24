#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	/* 조커 위치 */
	bool left = true; // 조커가 왼쪽에 있으면 true, 오른쪽에 있으면 false
	int pos = 1;

	int ans;
	while(N--) {
		int a[27];
		int l=0, r=0, total=0;

		for (int i=0; total!=27; i++) {
			cin >> a[i];
			total += a[i];
		}

		total = 0; //
		int _pos = pos;
		for(int i=0; a[i]!='\0'; i++) {
			if(i%2 == 0) r += a[i];
			else l += a[i];

			if( (left && (pos<=l)) || (!left && (pos<=r)) ) {
				ans = total+ _pos;

				if(ans<14) { left=true; pos=ans; }
				else { left=false; pos=(ans-13); }

				break;
			}

			if( (i%2==0 && !left) || (i%2==1 && left) )
				_pos -= a[i];

			total += a[i]; //
		}
	}

	cout << ans;

	return 0;
}