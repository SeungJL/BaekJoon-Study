#include <bits/stdc++.h>

using namespace std;

int main() {
    char king_x, stone_x;
    int king_y, stone_y, N;
    cin >> king_x >> king_y>> stone_x >> stone_y >> N;

    while(N--){
        string order;
        cin >> order;
        if(order == "R"){
            //체스판 넘어갈 경우
            if(king_x - 'A' == 7) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x+1 && stone_y == king_y) {
                if(stone_x -'A' == 7) continue;
                else stone_x ++;
            }
            king_x++;
        }
        else if(order == "L"){
            //체스판 넘어갈 경우
            if(king_x - 'A' == 0) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x-1 && stone_y == king_y) {
                if(stone_x -'A' == 0) continue;
                else stone_x --;
            }
            king_x--;

        }
        else if(order == "B"){
            //체스판 넘어갈 경우
            if(king_y == 1) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x && stone_y == king_y-1) {
                if(stone_y == 1) continue;
                else stone_y --;
            }
            king_y--;
        }
        else if(order == "T"){
            //체스판 넘어갈 경우
            if(king_y == 8) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x && stone_y == king_y+1) {
                if(stone_y == 8) continue;
                else stone_y ++;
            }
            king_y++;
        }
        else if(order == "RT"){
            //체스판 넘어갈 경우
            if(king_x - 'A' == 7 || king_y == 8) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x+1 && stone_y == king_y+1) {
                if(stone_x -'A' == 7 || stone_y == 8) continue;
                else {
                    stone_x ++;
                    stone_y++;
                }
            }
            king_x++;
            king_y++;

        }
        else if(order == "LT"){
            //체스판 넘어갈 경우
            if(king_x - 'A' == 0 || king_y == 8) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x-1 && stone_y == king_y+1) {
                if(stone_x -'A' == 0 || stone_y == 8) continue;
                else {
                    stone_x --;
                    stone_y++;
                }
            }
            king_x--;
            king_y++;
        }
        else if(order == "RB"){
            //체스판 넘어갈 경우
            if(king_x - 'A' == 7 || king_y == 1) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x+1 && stone_y == king_y-1) {
                if(stone_x -'A' == 7||stone_y==1) continue;
                else {
                    stone_x ++;
                    stone_y --;
                }
            }
            king_x++;
            king_y--;
        }
        else if(order == "LB"){
            //체스판 넘어갈 경우
            if(king_x - 'A' == 0 || king_y == 1) continue;
            //이동 했는데 돌이랑 겹칠 경우
            if(stone_x == king_x-1 && stone_y == king_y-1) {
                if(stone_x -'A' == 0 || stone_y == 1) continue;
                else {
                    stone_x --;
                    stone_y --;
                }
            }
            king_x--;
            king_y--;

        }
    }
    cout << king_x << king_y << "\n" << stone_x << stone_y << "\n";

    return 0;
}
