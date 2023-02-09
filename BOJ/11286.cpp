#include <bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int> maxPq;                            // 최대힙(음수)
priority_queue<int, vector<int>, greater<int>> minPq; // 최소힙(양수)

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x < 0)
            maxPq.push(x);
        else if (x > 0)
            minPq.push(x);
        else if (x == 0)
        {
            if (maxPq.size() == 0 && minPq.size() == 0)
                cout << "0\n";
            else if (maxPq.size() == 0 && minPq.size() != 0)
            {
                cout << minPq.top() << "\n";
                minPq.pop();
            }
            else if (maxPq.size() != 0 && minPq.size() == 0)
            {
                cout << maxPq.top() << "\n";
                maxPq.pop();
            }
            else
            {
                int a = minPq.top();
                int b = maxPq.top(); // 음수
                if (abs(a) < abs(b))
                {
                    cout << a << "\n";
                    minPq.pop();
                }
                else if (abs(a) >= abs(b))
                {
                    cout << b << "\n";
                    maxPq.pop();
                }
            }
        }
    }

    return 0;
}