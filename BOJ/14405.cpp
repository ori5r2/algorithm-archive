#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> str;

    int idx = 0;
    bool suc = true;
    while (1)
    {
        if (idx == str.size())
            break;

        if (str.substr(idx, 2) == "pi" || str.substr(idx, 2) == "ka")
            idx += 2;
        else if (str.substr(idx, 3) == "chu")
            idx += 3;
        else
        {
            suc = false;
            break;
        }
    }

    if (!suc)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}