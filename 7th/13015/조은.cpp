#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<2*n-1; i++) {
		
		if(i==0 || i==2*n-2) { // �� ��, �� �Ʒ�
			for(int j=0; j<n; j++) cout << '*';
			for(int j=0; j<2*n-3; j++) cout << ' ';
			for(int j=0; j<n; j++) cout << '*';
			cout << '\n';
		}

		else {
			// ���� * ���� * ������� * ���� * (��) //

			// ����
			if(i<n) for(int j=0; j<i; j++) cout << ' ';
			else for(int j=0; j<(2*n-2)-i; j++) cout << ' ';
			cout << '*';

			// ����
			for(int j=0; j<n-2; j++) cout << ' ';
			cout << '*';

			// ��� ����
			for(int j=0; j<2*abs(n-(i+1))-1; j++) cout << ' ';
			if(i != n-1) cout << '*'; // ���� ��� ���� ��(*) ���� �ϳ� ����

			// ����
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