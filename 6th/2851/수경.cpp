#include <bits/stdc++.h>

using namespace std;

int mushroom[10];

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> mushroom[i];
    }
    int sum = 0;
    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (abs(sum + mushroom[i] - 100) <= abs(sum - 100)) sum += mushroom[i];
        else break;
    }
    cout << sum;

    return 0;
}