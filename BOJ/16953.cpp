#include <bits/stdc++.h>
using namespace std;

long long A, B;
queue<pair<long long, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> A >> B;

    q.push({A, 1});

    while (!q.empty())
    {
        long long front = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            long long x;
            if (i == 0)
                x = front * 2;
            else
                x = front * 10 + 1;

            if (x < B)
                q.push({x, cnt + 1});
            else if (x == B)
            {
                cout << cnt + 1;
                return 0;
            }
        }
    }

    cout << "-1";
    return 0;
}