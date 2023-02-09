#include <bits/stdc++.h>
using namespace std;
#define MX 10

int N, M;
int num[MX];

void backFunc(int k, int start)
{
    if (k == M)
    {
        for (int idx = 0; idx < M; idx++)
            cout << num[idx] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++)
    {
        num[k] = i;
        backFunc(k + 1, i);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    backFunc(0, 1);

    return 0;
}