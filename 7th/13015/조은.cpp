#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<2*n-1; i++) {
		
		if(i==0 || i==2*n-2) { // 맨 위, 맨 아래
			for(int j=0; j<n; j++) cout << '*';
			for(int j=0; j<2*n-3; j++) cout << ' ';
			for(int j=0; j<n; j++) cout << '*';
			cout << '\n';
		}

		else {
			// 공백 * 공백 * 가운데공백 * 공백 * (끝) //

			// 공백
			if(i<n) for(int j=0; j<i; j++) cout << ' ';
			else for(int j=0; j<(2*n-2)-i; j++) cout << ' ';
			cout << '*';

			// 공백
			for(int j=0; j<n-2; j++) cout << ' ';
			cout << '*';

			// 가운데 공백
			for(int j=0; j<2*abs(n-(i+1))-1; j++) cout << ' ';
			if(i != n-1) cout << '*'; // 제일 가운데 줄은 별(*) 개수 하나 적게

			// 공백
			for(int j=0; j<n-2; j++) cout << ' ';
			cout << '*';
			cout << '\n';
		}
	}
	
	return 0;
}


/*
n=2

** **
 *** 
** **
*/

/*
n=3

***   ***
 * * * * 
  * * *  
 * * * *
***   ***
*/

/*
n=4

****     ****
 *  *   *  * 
  *  * *  *  
	 *  *  *
	*  * *  *
 *  *   *  *
****     ****
*/

/*
n=5

*****       *****
 *   *     *   *
	*   *   *   *
	 *   * *   *
		*   *   *
	 *   * *   *
	*   *   *   *
 *   *     *   *
*****       *****
*/