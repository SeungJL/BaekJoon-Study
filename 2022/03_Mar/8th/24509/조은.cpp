#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int X;
	int A, B, C, D;
}student;

bool sort_A(const student &s1, const student &s2) {
	if(s1.A == s2.A) return s1.X < s2.X;
	else return s1.A > s2.A;
}
bool sort_B(const student &s1, const student &s2) {
	if(s1.B == s2.B) return s1.X < s2.X;
	else return s1.B > s2.B;
}
bool sort_C(const student &s1, const student &s2) {
	if(s1.C == s2.C) return s1.X < s2.X;
	else return s1.C > s2.C;
}
bool sort_D(const student &s1, const student &s2) {
	if(s1.D == s2.D) return s1.X < s2.X;
	else return s1.D > s2.D;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<student> v(N);
	for(int i=0; i<N; i++) {
		cin >> v[i].X >> v[i].A >> v[i].B >> v[i].C >> v[i].D;
	}

	sort(v.begin(), v.end(), sort_A); // sort by A
	cout << v[0].X << ' ';
	v.erase(v.begin()); // 1등 출력 후 맨 앞 원소 삭제
	sort(v.begin(), v.end(), sort_B); // sort by B
	cout << v[0].X << ' ';
	v.erase(v.begin()); // 1등 출력 후 맨 앞 원소 삭제
	sort(v.begin(), v.end(), sort_C); // sort by C
	cout << v[0].X << ' ';
	v.erase(v.begin()); // 1등 출력 후 맨 앞 원소 삭제
	sort(v.begin(), v.end(), sort_D); // sort by D
	cout << v[0].X;

	return 0;
}