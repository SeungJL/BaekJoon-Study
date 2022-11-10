#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct balloon {
	int id; // Ç³¼± ¹øÈ£
	int jump; // ´ÙÀ½ Ç³¼±±îÁö ÀÌµ¿¼ö
};

balloon balloons[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> balloons[i].jump;
		balloons[i].id = i;
	}
	//for (int i = 1; balloons[i].jump!='\0'; i++) {
	//	cout << balloons[i].id << ' ' << balloons[i].jump << endl;
	//}

	int i=0;
	while(n--) {
		cout << balloons[i].id << ' ';
		i = balloons[i].id
	}












	//deque<pair<int,int>> dq;
	//for (int i = 0; i < n; i++) {
	//	cin >> t;
	//	dq.push_back({ i + 1, t });
	//}
	/*for (int i = 0; i < n; i++) {
		cout << i<< ' ' << dq[i].first << ' ' << dq[i].second << endl;
	}*/
	//cout << (-1)/3 << ' ' << (-1) % 3 << endl;

	int i=0;
	while(n--) {
		//cout << dq[i].first << ' ';
		//dq.erase(dq.begin()+dq[i].first);
		//for(int j=0; j<dq.size(); j++) dq[j].first = j+1;

		//i = dq[i].first + dq[i].second - 1;
		///* ´ÙÀ½ ÅÍ¶ß¸± Ç³¼±ÀÇ ÀÎµ¦½º°¡ ¹üÀ§¸¦ ¹þ¾î³¯ °æ¿ì */
		//if (i > dq.size()-1 || i < 0)
		//	i = (i+dq.size()) % dq.size();
	}






	//vector<pair<int,int>> v;
	////v.push_back({0,0});
	//for(int i=1; i<=n; i++) {
	//	cin >> t;
	//	v.push_back({i, t});
	//}

	//int i=0;
	//while(n--) {
	//	int next_idx = v[i].first + v[i].second - 1; // ÀÎµ¦½º´Â 0ºÎÅÍ ½ÃÀÛÇÏ´Ï±î 1 »©ÁÜ

	//	/* ´ÙÀ½ ÅÍ¶ß¸± Ç³¼±ÀÇ ÀÎµ¦½º°¡ ¹üÀ§¸¦ ¹þ¾î³¯ °æ¿ì */
	//	if(next_idx > v.size()-1) next_idx -= v.size();
	//	else if(next_idx < 0) next_idx += v.size();

	//	cout << v[i].first << ' ';
	//	i = next_idx;
	//	v.erase(v.begin()+v[i].first);
	//}

	return 0;
}