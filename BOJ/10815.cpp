#include <bits/stdc++.h>
using namespace std;
#define MX 500005

int N, M, tmp;
map<int, int> m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        m.insert({tmp, i});
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        int idx = m[tmp];

        if (idx)
            cout << "1 ";
        else
            cout << "0 ";
    }
    return 0;
}