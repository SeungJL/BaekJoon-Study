#include <iostream>
#include <vector>

using namespace std;

struct Pipe {
    int hor, ver, dia;
    Pipe(int _d, int _h=0, int _v=0) : hor(_h), ver(_v), dia(_d) {};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    // init
    vector< vector<Pipe> > map(N+1, vector<Pipe>(1, Pipe(-1)));
    for (int r=0; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (r == 0) map[0].push_back(Pipe(-1));
            else {
                int input;
                cin >> input;
                map[r].push_back(Pipe(input * -1));
            }
        }
    }
    map[1][2].hor = 1;

    // solve
    // if (N, N) is not blank
    if (map[N][N].dia < 0) {
        cout << "0\n";
        return (0);
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 3; c <= N; c++) {
            // if (r, c) is not blank
            if (map[r][c].dia < 0) continue;

            // three cases where the pipe can come to (r, c)
            // vertical
            if (map[r-1][c].dia >= 0)
                map[r][c].ver = (map[r-1][c].ver + map[r-1][c].dia);
            // diagonal
            if (map[r-1][c].dia >= 0 && map[r][c-1].dia >= 0 && map[r-1][c-1].dia >= 0)
                map[r][c].dia = (map[r-1][c-1].dia + map[r-1][c-1].hor + map[r-1][c-1].ver);
            // horizontal
            if (map[r][c-1].dia >= 0)
                map[r][c].hor = (map[r][c-1].hor + map[r][c-1].dia);                        
        }
    }
    
    cout << map[N][N].hor + map[N][N].ver + map[N][N].dia << "\n";
}