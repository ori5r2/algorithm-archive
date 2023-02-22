#include <bits/stdc++.h>
using namespace std;
#define MX 500002

int N, M, num;
map<int, int> m;
int A[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        int idx = m[num];
        if (idx)
        {
            A[idx]++;
            continue;
        }
        else
        {
            m[num] = i;
            A[i]++;
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;

        int idx = m[num];
        if (idx)
            cout << A[idx] << " ";
        else
            cout << "0 ";
    }

    return 0;
}