#include <bits/stdc++.h>
using namespace std;
#define MX 10

int N, M;
int num[MX];
bool visited[MX];

void backTracking(int k) // k: num index
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << num[i] << " ";
        cout << "\n";
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            num[k] = i;
            visited[i] = true;
            backTracking(k + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    backTracking(0);
    return 0;
}