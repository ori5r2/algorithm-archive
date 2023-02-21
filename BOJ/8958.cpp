#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> s;
        int x = 1, len = s.size(), score = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'O')
                score += x++;
            else if (s[i] == 'X')
                x = 1;
        }
        cout << score << "\n";
    }

    return 0;
}