#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
map<int, int> m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        m.insert({tmp, i});
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (m.find(tmp) != m.end())
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}