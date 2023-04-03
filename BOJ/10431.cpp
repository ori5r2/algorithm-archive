#include <bits/stdc++.h>
using namespace std;

int N, tc, height;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;

    for (int t = 1; t <= N; t++)
    {
        cin >> tc;
        deque<int> dq;
        stack<int> sk;
        int ans = 0;

        for (int i = 0; i < 20; i++)
        {
            cin >> height;
            if (!dq.empty())
            {
                int idx = lower_bound(dq.begin(), dq.end(), height) - dq.begin();

                if (idx >= dq.size())
                    dq.push_back(height);
                else if (idx == 0)
                    ans += dq.size(), dq.push_front(height);
                else
                {
                    int num = dq.size() - idx;
                    ans += num;
                    while (num-- > 0)
                        sk.push(dq.back()), dq.pop_back();

                    dq.push_back(height);
                    while (!sk.empty())
                        dq.push_back(sk.top()), sk.pop();
                }
            }
            else
                dq.push_back(height);
        }
        cout << tc << " " << ans << "\n";
    }

    return 0;
}