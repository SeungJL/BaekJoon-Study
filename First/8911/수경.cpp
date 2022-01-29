#include <bits/stdc++.h>

using namespace std;
char arrow;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    cin.get();

    string order;
    while (T--) {
        //방향(arrow)은 북쪽('U')으로 초기화
        //북 = 'U', 동 = 'R', 남 = 'D', 서 = 'L'
        arrow = 'U';
        int x = 0, y = 0;
        //자취 기록
        vector<pair<int, int>> points;
        //자취에 원점 추가
        points.push_back(make_pair(0, 0));

        //문자열 입력
        cin >> order;
        int max_x = 0, max_y = 0;
        int min_x = 0, min_y = 0;

        for (int i = 0; i < order.size(); i++) {

            //방향별로 달라지는 좌표
            if (order[i] == 'F') {
                if (arrow == 'U') y++;
                else if (arrow == 'R') x++;
                else if (arrow == 'D') y--;
                else if (arrow == 'L') x--;
                //자취에 좌표 추가
                points.push_back(make_pair(x, y));
            } else if (order[i] == 'B') {
                if (arrow == 'U') y--;
                else if (arrow == 'R') x--;
                else if (arrow == 'D') y++;
                else if (arrow == 'L') x++;
                //자취에 좌표 추가
                points.push_back(make_pair(x, y));
            } else if (order[i] == 'R') {
                //방향만 바꾸는 명령 -> 자취에 좌표 추가 X
                if (arrow == 'U') arrow = 'R';
                else if (arrow == 'R') arrow = 'D';
                else if (arrow == 'D') arrow = 'L';
                else if (arrow == 'L') arrow = 'U';
            } else if (order[i] == 'L') {
                //방향만 바꾸는 명령 -> 자취에 좌표 추가 X
                if (arrow == 'U') arrow = 'L';
                else if (arrow == 'R') arrow = 'U';
                else if (arrow == 'D') arrow = 'R';
                else if (arrow == 'L') arrow = 'D';
            }


            // x, y 각각 최대값, 최소값 구하
            if (x > max_x) max_x = x;
            if (x < min_x) min_x = x;

            if (y > max_y) max_y = y;
            if (y < min_y) min_y = y;
        }

        cout << (max_x - min_x) * (max_y - min_y) << "\n";
    }
    return 0;
}
