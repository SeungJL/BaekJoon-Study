#include <bits/stdc++.h>

using namespace std;

int S[20][20];
bool selected[21];
int N;

int minScore = INT_MAX;

void DFS(int index, int cnt) {
    if (N / 2 == cnt) {
        vector<int> startTeam;
        vector<int> linkTeam;
        for (int i = 1; i <= N; i++) {
            if (selected[i] == true) {
                startTeam.push_back(i);
            } else linkTeam.push_back(i);
        }


        int startScore = 0, linkScore = 0;
        for (int i = 0; i < (N / 2); i++)
            for (int j = 0; j < (N / 2); j++) {
                startScore += S[startTeam[i] - 1][startTeam[j] - 1];
                linkScore += S[linkTeam[i] - 1][linkTeam[j] - 1];
            }
        if (abs(startScore - linkScore) < minScore)
            minScore = abs(startScore - linkScore);

        return;
    }
    for (int i = index; i <= N; i++) {
        if (selected[i] == false) {
            selected[i] = true;
            DFS(i, cnt + 1);
            selected[i] = false;
        }
    }
}

/*
 * N = 4
 * selected
 * 1 2 3 4
 * t f f f
 *
 */


int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    DFS(1, 0);

    printf("%d\n", minScore);


    return 0;
}

/*
 * 1, 2 / 3, 4
 * 1, 3 / 2, 4
 * 1, 4 / 2, 3
 *
 * 4C2/2
 *
 * 1, 2, 3 / 4, 5, 6
 * 1, 2, 4 / 3, 5, 6
 * 1, 2, 5 / 3, 4, 6
 * 1, 2, 6 / 3, 4, 5
 * 1, 3, 4 / 2, 5, 6
 * 1, 3, 5 / 2, 4, 6
 * 1, 3, 6 / 2, 4, 5
 * 1, 4, 5 / 2, 3, 6
 * 1, 4, 6 / 2, 3, 5
 * 1, 5, 6 / 2, 3, 4
 * 6C3/2 = 10
 *
 *
 */