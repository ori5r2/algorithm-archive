#include <bits/stdc++.h>
using namespace std;

string str;
int len;

bool isPal(int s)
{
    bool check = true;
    int e = len - 1;
    while (s <= e)
    {
        if (str[s] == str[e])
        {
            s++, e--;
            continue;
        }
        else
            return false;
    }

    return check;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> str;
    len = str.size();

    for (int i = 0; i < len; i++)
    {
        if (isPal(i))
        {
            cout << len + i;
            break;
        }
    }
    return 0;
}