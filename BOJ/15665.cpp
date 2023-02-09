#include <bits/stdc++.h>
using namespace std;
#define MX 10

int N, M;
int num[MX], arr[MX];

void backTrack(int k)
{
    if (k == M)
    {
        for (int idx = 0; idx < M; idx++)
            cout << num[idx] << " ";
        cout << "\n";
        return;
    }

    int prior = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != prior)
        {
            num[k] = arr[i], prior = arr[i];
            backTrack(k + 1);
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

    backTrack(0);
    return 0;
}