// 1022

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int y, x;
    Point(int _y, int _x) : y(_y), x(_x) {}
};

void set_points(int center, Point cur, vector<Point> &points, int diff) {
    int YY[5] = {0, -1, -1, 1, 1};
    int XX[5] = {0, 1, -1, -1, 1};

    points.push_back(Point(cur.y, cur.x+1));
    for(int i=1; i<5; i++)
        points.push_back(Point(center + (YY[i]*diff), center + (XX[i]*diff)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int input[4], center = 0;
    for (int i=0; i<4; i++) {
        cin >> input[i];
        int tmp = (input[i] >= 0) ? input[i] : -input[i];
        if (tmp > center) center = tmp;
    }
    Point p1(input[0]+center, input[1]+center), p2(input[2]+center, input[3]+center);


    // set grid
    vector<vector<int>> grid(p2.y - p1.y + 1, vector<int>(p2.x - p1.x + 1, 0));
    int YY[5] = {0, -1, 0, 1, 0};
    int XX[5] = {1, 0, -1, 0, 1};

    Point cur(center, center);
    int num = 1, diff = 1, max_num = 0, cnt = 0;
    if (center >= p1.y && center <= p2.y && center >= p1.x && center <= p2.x) {
        grid[center - p1.y][center - p1.x] = num;
        max_num = num;
    }

    while (!(cur.y == center*2 && cur.x == center*2)) {
        vector<Point> points;
        set_points(center, cur, points, diff++);
        
        for (int i=0; i<5; i++) {
            while (!(cur.y == points[i].y && cur.x == points[i].x)) {
                cur.y += YY[i]; cur.x += XX[i];
                num++;
                if (cur.y >= p1.y && cur.y <= p2.y && cur.x >= p1.x && cur.x <= p2.x) {
                    grid[cur.y - p1.y][cur.x - p1.x] = num;
                    if (num > max_num) max_num = num;
                    cnt++;
                }
            }
        }
        if (cnt >= (p2.y - p1.y + 1) * (p2.x - p1.x + 1)) break;
    }

    // print res
    int w = 0;
    while (max_num) {
        w++;
        max_num /= 10;
    }
    
    for (auto r_it = grid.begin(); r_it < grid.end(); r_it++) {
        for (auto c_it = (*r_it).begin(); c_it < (*r_it).end(); c_it++) {
            cout.width(w);
            cout.fill(' ');
            cout << *c_it << " ";
        }
        cout << endl;
    }

}