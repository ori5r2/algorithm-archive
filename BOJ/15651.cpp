#include <bits/stdc++.h>
using namespace std;
#define MX 10

int N, M;
int num[MX];

void backFunc(int K)
{
    if (K == M)
    {
        for (int k = 0; k < M; k++)
            cout << num[k] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        num[K] = i;
        backFunc(K + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    backFunc(0);

    return 0;
}