#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[2];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> str;
    char ch = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        if (ch != str[i])
        {
            if (ch == '0')
                cnt[0]++;
            else
                cnt[1]++;

            ch = str[i];
        }
    }
    if (ch == '0')
        cnt[0]++;
    else
        cnt[1]++;

    cout << min(cnt[0], cnt[1]);

    return 0;
}