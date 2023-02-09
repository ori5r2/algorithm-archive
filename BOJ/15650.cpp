#include <bits/stdc++.h>
using namespace std;
#define MX 10

int N, M;
int num[MX];
bool visited[MX];

void backFunc(int k, int start)
{

    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << num[i] << " ";
        cout << "\n";
    }

    for (int i = start; i <= N; i++)
    {
        if (!visited[i])
        {
            num[k] = i;
            visited[i] = true;
            backFunc(k + 1, i + 1);
            visited[i] = false;
        }
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