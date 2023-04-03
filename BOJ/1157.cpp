#include <bits/stdc++.h>
using namespace std;

string str;
int upper[26];
int lower[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
            upper[str[i] - 'A']++;
        else
            lower[str[i] - 'a']++;
    }

    int mx = -1, idx = -1;
    for (int i = 0; i < 26; i++)
    {
        if (upper[i] + lower[i] == 0)
            continue;
        if (mx < upper[i] + lower[i])
            mx = upper[i] + lower[i], idx = i;
        else if (mx == upper[i] + lower[i])
            idx = -1; // ⭐️ 반례: ABCC
    }

    if (idx == -1)
        cout << "?";
    else
        cout << char('A' + idx);
    return 0;
}