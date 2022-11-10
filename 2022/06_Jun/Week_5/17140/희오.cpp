#include <iostream>
#include <vector>
#include <algorithm> // sort()

using namespace std;

struct Set {
    int num, cnt;
    Set (int _n) : num(_n), cnt(0) {};
};

vector< vector<int> > A(100, vector<int>(100, 0));

// compare function to sort by the number of integer(first) and the integer(second) in the ascending order
bool my_cmp (const Set a, const Set b) {
    if (a.cnt == b.cnt) return (a.num < b.num);
    return (a.cnt < b.cnt);
}

int R_cmd(int r_N, int c_N) {
    int max_size = 0;
    for (int r=0; r<r_N; r++) {
        vector<int> cnt_arr(101, 0); // to count the number of integer
        vector<Set> sort_arr;        // to sort by the number of int and the int
        
        // given the row, count the number of integer
        for (int c=0; c<c_N; c++) {
            int num = A[r][c];
            if (num == 0) continue;
            A[r][c] = 0;
            if (cnt_arr[num] == 0) 
                sort_arr.push_back(Set(num));
            cnt_arr[num]++;
        }

        // update the number of int and sort
        for (auto &e : sort_arr) 
            e.cnt = cnt_arr[e.num];
        sort(sort_arr.begin(), sort_arr.end(), my_cmp);

        // update the row of 'A' with sort_arr
        int i = 0;
        for (auto e : sort_arr) {
            if (i <= 100) A[r][i++] = e.num;
            if (i <= 100) A[r][i++] = e.cnt;
        }

        // update row size of the 'A'
        if (max_size < i) max_size = i;
    }
    
    return (max_size);
}

int C_cmd(int r_N, int c_N) {
    int max_size = 0;
    for (int c=0; c<c_N; c++) {
        vector<int> cnt_arr(101, 0);
        vector<Set> sort_arr;

        // given the column, count the number of integer
        for (int r=0; r<r_N; r++) {
            int num = A[r][c];
            if (num == 0) continue;
            A[r][c] = 0;
            if (cnt_arr[num] == 0) 
                sort_arr.push_back(Set(num));
            cnt_arr[num]++;
        }

        // update the number of int and sort
        for (auto &e : sort_arr) 
            e.cnt = cnt_arr[e.num];
        sort(sort_arr.begin(), sort_arr.end(), my_cmp);

        // update the column of 'A' with sort_arr
        int i = 0;
        for (auto e : sort_arr) {
            if (i <= 100) A[i++][c] = e.num;
            if (i <= 100) A[i++][c] = e.cnt;
        }

        // update the column size of  'A'
        if (max_size < i) max_size = i;
    }
    
    return (max_size);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    // init
    int R, C, K;
    cin >> R >> C >> K;

    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            cin >> A[r][c];
        }
    }

    // solve
    int r_N = 3, c_N = 3;
    int timer = 0;
    while (A[R-1][C-1] != K && timer++ < 100) {
        if (r_N >= c_N) c_N = R_cmd(r_N, c_N);
        else r_N = C_cmd(r_N, c_N); 
    }

    if (timer > 100) cout << "-1\n";
    else cout << timer << "\n";
}  
