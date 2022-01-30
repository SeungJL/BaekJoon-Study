#include <bits/stdc++.h>

using namespace std;

int P[14];
int K[14];
int H[14];
int T[14];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int num;
    for (int i = 0; i < str.size(); i++) {
        if (i % 3 == 0) num = 0;    //i%3==0 -> 카드의 종류('P', 'K', 'H', 'T' 중 한 개)
        else if (i % 3 == 1) {  //i$3==1 -> 카드의 숫지의 십의 자리 숫자
            //num 변수에 십의 자리 숫자 저장
            num += (str[i] - '0') * 10;
        } else if (i % 3 == 2) {  //i$3==2 -> 카드의 숫지의 일의 자리 숫자
            //num 변수에 일의 자리 숫자 저장
            num += str[i] - '0';

            if (str[i - 2] == 'P') {
                //이미 해당 카드가 존재한다면
                if (P[num] != 0) {
                    cout << "GRESKA" << "\n";
                    return 0;
                }
                //아니라면 해당 배열 값 증가시키기
                P[num]++;
            } else if (str[i - 2] == 'K') {
                //이미 해당 카드가 존재한다면
                if (K[num] != 0) {
                    cout << "GRESKA" << "\n";
                    return 0;
                }
                //아니라면 해당 배열 값 증가시키기
                K[num]++;
            } else if (str[i - 2] == 'H') {
                //이미 해당 카드가 존재한다면
                if (H[num] != 0) {
                    cout << "GRESKA" << "\n";
                    return 0;
                }
                //아니라면 해당 배열 값 증가시키기
                H[num]++;
            } else if (str[i - 2] == 'T') {
                //이미 해당 카드가 존재한다면
                if (T[num] != 0) {
                    cout << "GRESKA" << "\n";
                    return 0;
                }
                //아니라면 해당 배열 값 증가시키기
                T[num]++;
            }
        }
    }

    //각 종류별 카드를 잃어버릴 수 있는 최대 개수인 13으로 초기화 시키고
    int p = 13, k = 13, h = 13, t = 13;
    for (int i = 1; i <= 13; i++) {
        //해당 카드가 존재한다면 감소시키기
        if (P[i] != 0) p--;
        if (K[i] != 0) k--;
        if (H[i] != 0) h--;
        if (T[i] != 0) t--;
    }
    cout << p << " " << k << " " << h << " " << t << "\n";
    return 0;
}