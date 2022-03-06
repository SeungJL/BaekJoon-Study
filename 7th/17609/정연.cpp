#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
 
int t;
string s;
bool check;
 
bool isPalin(int fidx, int bidx)
{
    while (fidx < bidx)
    {
        if (s[fidx] == s[bidx])
        {
            fidx++;
            bidx--;
        }
        else
        {
            if (check)
                return false;
            check = true;
            return isPalin(fidx + 1, bidx) || isPalin(fidx, bidx - 1);
        }
    }
    return true;
}
 
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        check = false;
        bool isP = isPalin(0, s.size()-1);
        if (isP && !check)
            cout << 0 << '\n';
        else if(isP && check)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }
    return 0;
}