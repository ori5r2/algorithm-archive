#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    while (cin >> s1 >> s2)
    {
        int idx = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == s1[idx])
                idx++;
        }

        if (idx == s1.size())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}