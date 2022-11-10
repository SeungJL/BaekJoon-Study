// BOJ 9205 맥주 마시면서 걸아가기

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point(int _x=0, int _y=0) : x(_x), y(_y) {}
}; 

int my_abs(int n) {
    if (n < 0)
        return (-n);
    return (n);
}

int get_dis(Point a, Point b) {
    return (my_abs(a.x - b.x) + my_abs(a.y - b.y));
}

bool solve(Point s, Point e, vector<Point> midpoints) {
    if (get_dis(s, e) <= 1000)
        return  (true);
    
    queue<Point> Q;
    int n = midpoints.size();
    vector<bool> ch(n, false);
    
    Q.push(Point(s.x, s.y));
    while (!Q.empty()) {
        Point cur = Q.front();
        Q.pop();

        for (size_t i=0; i < n; i++) {
            if (!ch[i] && get_dis(cur, midpoints[i]) <= 1000) {
                if (get_dis(midpoints[i], e) <= 1000)
                    return (true);
                Q.push(Point(midpoints[i].x, midpoints[i].y));
                ch[i] = true;
            }
        }
    }
    return (false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int TC;
    cin >> TC;

    while (TC--) {
        int n, x, y;
        Point start_point, end_point;
        queue<Point> Q;
        vector<Point> midpoints;

        cin >> n >> start_point.x >> start_point.y;
        while (n--) {
            cin >> x >> y;
            midpoints.push_back(Point(x, y));            
        }
        cin >> end_point.x >> end_point.y;

        solve(start_point, end_point, midpoints) ? cout << "happy\n" : cout << "sad\n";
    }

}