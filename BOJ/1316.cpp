#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string str;
bool isAppear[27];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;

        char ch = str[0];
        bool suc = true;
        memset(isAppear, false, sizeof(isAppear));

        for (int i = 1; i < str.size(); i++)
        {
            int idx = str[i] - 'a';
            if (isAppear[idx])
            {
                suc = false;
                break;
            }

            if (ch != str[i])
            {
                isAppear[ch - 'a'] = true;
                ch = str[i];
            }
            else
                continue;
        }
        if (suc)
            cnt++;
    }
    cout << cnt;

    return 0;
}