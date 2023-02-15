#include <bits/stdc++.h>
using namespace std;
#define MX 102
// BFS : 메모리 초과

typedef long long ll;
int N;
int board[MX][MX];
ll cnt[MX][MX];

void DP()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                cnt[i][j] = 1;
                continue;
            }

            ll tmp = 0; // ⭐️ int > long long
            for (int n = 0; n < i; n++)
            {
                if (board[n][j] == (i - n))
                    tmp += cnt[n][j];
            }
            for (int m = 0; m < j; m++)
            {
                if (board[i][m] == (j - m))
                    tmp += cnt[i][m];
            }

            cnt[i][j] = tmp;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    DP();

    cout << cnt[N - 1][N - 1];
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         cout << cnt[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}