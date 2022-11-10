#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string>

using namespace std;

int L, C;
vector<char> letters;

/* 만든 암호 문자열이 조건에 부합한지 검사하는 함수
 * password - 암호 문자열
 * 부합하면 true, 아닐 경우 false return
 */
bool check_password(string password) {
    string vowels = "aeiou";
    int vowel_cnt = 0, cons_cnt = 0;

    for (auto e : password) {
        if (vowels.find(e) != string::npos) vowel_cnt++;
        else cons_cnt++;
        if (vowel_cnt >= 1 && cons_cnt >= 2) 
            return (true);
    }
    return (false);
}

/* DFS를 이용하여 암호가 될 수 있는 문자 조합 찾고, 조건에 맞는 암호를 출력하는 함수
 *
 * k - 현재까지 만든 문자조합 길이
 * password - 현재까지 만든 문자조합 
 * last_i - 마지막에 사용한 문자 인덱스
 */
void DFS(int k, string password, int last_i) {
    // 문자 조합 완성
    // check_password()를 통해 조건에 맞는지 검사한 후 맞을 경우 출력
    if (k == L) {
        if (check_password(password))
            cout << password << "\n";
        return ;
    }

    // 이전에 선택한 문자보다 값이 큰 문자 중에 사용 가능한 문자를 암호 문자열에 추가
    for (int i = last_i + 1; i <= C-(L-k); i++)
        DFS(k + 1, password + letters[i], i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    cin >> L >> C;

    for (int i=0; i<C; i++) {
        char c;
        cin >> c;
        letters.push_back(c);
    }
    // L개의 문자 오름차순 정렬
    sort(letters.begin(), letters.end());

    DFS(0, "", -1);

}