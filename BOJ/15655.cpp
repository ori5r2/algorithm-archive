#include <bits/stdc++.h>
using namespace std;
#define MX 10

int N, M;
int num[MX], arr[MX];
bool visited[MX];

void backTrack(int k, int start)
{
    if (k == M)
    {
        for (int idx = 0; idx < M; idx++)
            cout << num[idx] << " ";
        cout << "\n";
    }

    for (int i = start; i < N; i++)
    {
        if (!visited[i])
        {
            num[k] = arr[i], visited[i] = true;
            backTrack(k + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    backTrack(0, 0);

    return 0;
}