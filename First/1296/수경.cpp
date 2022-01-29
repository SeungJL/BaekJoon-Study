#include <bits/stdc++.h>

using namespace std;

int L, O, V, E;


int calculatePer(string str) {
    //팀 이름의 LOVE 연두의 LOVE와 합치기
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'L') L++;
        else if (str[i] == 'O') O++;
        else if (str[i] == 'V') V++;
        else if (str[i] == 'E') E++;
    }

    //승리 확률 계산
    int percent = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
    return percent;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //연두의 이름 입력
    string name;
    cin >> name;

    //연두의 이름에서 등장하는 LOVE 개수 계산
    int name_L = L, name_O = O, name_V = V, name_E = E;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'L') name_L++;
        else if (name[i] == 'O') name_O++;
        else if (name[i] == 'V') name_V++;
        else if (name[i] == 'E') name_E++;
    }

    int N;
    cin >> N;
    cin.get();
    //연두의 LOVE값 저장

    int max = 0;
    string winner;
    for (int i = 0; i < N; i++) {
        //team 이름에 있는 LOVE 개수 세기 전 연두의 이름에 있는 LOVE의 개수로 초기화
        L = name_L;
        O = name_O;
        V = name_V;
        E = name_E;

        string teamName;
        cin >> teamName;
        //winner 첫 번째 팀으로 초기화
        if (i == 0) winner = teamName;

        //승리 확률 계산
        int per = calculatePer(teamName);

        //최댓값보다 크면 승리 확률이 가장 높은 팀로 올리기
        if (per > max) {
            winner = teamName;
            max = per;
        } else if (per == max) {    // 승리 확률이 가장 높은 팀이 두 팀이면 사전 순으로 결정
            if (winner > teamName) winner = teamName;
        }
    }

    cout << winner << "\n";


    return 0;
}
