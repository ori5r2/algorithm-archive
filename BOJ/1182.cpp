#include <bits/stdc++.h>
using namespace std;
#define MX 22

int N, S, cnt = 0;
int arr[MX], num[MX];

void backTrack(int k, int M, int start, int sum)
{
    if (k == M)
    {
        // for (int idx = 0; idx < M; idx++)
        //     cout << num[idx] << " ";
        // cout << "sum: " << sum << endl;
        if (sum == S)
            cnt++;
        return;
    }

    for (int i = start; i < N; i++)
    {
        num[k] = arr[i];
        backTrack(k + 1, M, i + 1, sum + arr[i]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int m = 1; m <= N; m++)
    {
        backTrack(0, m, 0, 0);
    }
    cout << cnt;
    return 0;
}