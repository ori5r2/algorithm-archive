#include <bits/stdc++.h>
using namespace std;

string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    int tc = 1;
    while (1)
    {
        cin >> str;
        if (str[0] == '-')
            break;

        stack<char> s1, s2;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '{')
                s2.push(str[i]);
            else if (str[i] == '}')
            {
                if (!s2.empty())
                    s2.pop();
                else
                    s1.push(str[i]);
            }
        }
        int cnt1 = s1.size(), cnt2 = s2.size();
        int ans = 0;

        if (cnt1 == 0 && cnt2 == 0)
            ans = 0;
        else if (cnt1 == 0)
            ans = cnt2 / 2;
        else if (cnt2 == 0)
            ans = cnt1 / 2;
        else
        {
            if (cnt1 % 2 == 0)
            {
                ans += cnt1 / 2;
                ans += cnt2 / 2;
            }
            else
            {
                ans += cnt1 / 2;
                ans += cnt2 / 2;
                ans += (cnt1 % 2) + (cnt2 % 2);
            }
        }
        cout << tc << ". " << ans << "\n";
        tc++;
    }

    return 0;
}