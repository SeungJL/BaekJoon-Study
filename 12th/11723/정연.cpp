#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

set<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;

    while (m--)
    {
        string str;
        int n;

        cin >> str;

        if (str == "add")
        {
            cin >> n;
            s.insert(n);
        }
        else if (str == "remove")
        {
            cin >> n;
            s.erase(n);
        }
        else if (str == "check")
        {
            cin >> n;
            cout << s.count(n) << "\n";
        }
        else if (str == "toggle")
        {
            cin >> n;
            auto iter = s.find(n);
            if (iter == s.end())
                s.insert(n);
            else
                s.erase(iter);
        }
        else if (str == "all")
        {
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        }
        else if (str == "empty")
        {
            s.clear();
        }
    }

    return 0;
}