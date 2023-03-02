#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, ans;
string str;
map<string, int> m;
bool isPass[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        m.insert({str, i});
    }

    int idx = 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        int now = m[str];
        if (now > idx)
        {
            ans++;
            isPass[now] = true;
        }
        else if (now == idx)
        {
            isPass[now] = true;
            while (1)
            {
                idx++;
                if (!isPass[idx])
                    break;
            }
        }
    }

    cout << ans;

    return 0;
}