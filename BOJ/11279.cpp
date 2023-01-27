#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x > 0)
            q.push(x);
        else if (x == 0)
        {
            if (q.empty())
                cout << "0\n";
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}