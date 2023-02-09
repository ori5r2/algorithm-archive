#include <bits/stdc++.h>
using namespace std;
#define MX 20002

int N, S;
int cow[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> cow[i];

    sort(cow, cow + N);

    int cnt = 0;
    for (int front = 0; front < N - 1; front++)
    {
        int frontVal = cow[front];
        for (int back = front + 1; back < N; back++)
        {
            int backVal = cow[back];
            if (frontVal + backVal <= S)
                cnt++;
            else
                break;
        }
    }

    cout << cnt;
    return 0;
}