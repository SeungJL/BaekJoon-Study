#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(2*n);
	for(int i=0; i<n; i++) 
		cin >> v[i];
	for(int i=n; i<2*n; i++)
		v[i] = v[i-n];

	int _min = 999999999;
	for(int i=0; i<n; i++) {
		int tmp = 0;
		for(int j=i+1; j <= (i+n-1); j++) {
			//cout << "v[j] * (j-i) = " << v[j] << " * " << (j-i) << " = " << v[j] * (j - i) << endl;
			tmp += v[j] * (j-i);
		}
		_min = min(_min, tmp);
		//cout << _min << endl;
	}
	cout << _min;

	return 0;
}


/* n개의 방

7cows부터인 경우:
	(8 + 6 + 4 + 4)
	+ (6 + 4 + 4)
	+ (4 + 4)
	+ (4)
	= 4*4 + 4*3 + 6*2 + 8*1
	= 16 + 12 + 12 + 8
	= 48

8cows부터인 경우:
	(6 + 4 + 4 + 7)
	+ (4 + 4 + 7)
	+ (4 + 7)
	+ (7)
	= 7*4 + 4*3 + 4*2 + 6*1
	= 28 + 12 + 8 + 6
	= 54

*/
