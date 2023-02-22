#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
string s;
char ch[] = {'I', 'O'};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    cin >> s;
    int idx = 0;
    for (int i = 0; i <= M; i++)
    {
        if (idx == 2 * N + 1)
        {
            ans++;
            idx = 2 * (N - 1) + 1;
        }

        if (i == M)
            break;

        if (s[i] == ch[idx % 2])
        {
            idx++;
        }
        else
        {
            idx = 0;
            if (s[i] == ch[idx % 2])
            {
                idx++;
            }
        }
    }
    cout << ans;

    return 0;
}