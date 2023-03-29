#include <bits/stdc++.h>
using namespace std;

int ladder[35][15];
int N, M, H;
int a, b;
pair<int, int> p[3];
bool isEnd = false;
// fstream fout;

bool check()
{
    for (int j = 1; j <= N; j++)
    {
        int n = j;
        for (int h = 1; h <= H; h++)
        {
            if (ladder[h][n])
                n++;
            else if (ladder[h][n - 1])
                n--;
        }
        if (j != n)
            return false;
        // cout << j << " " << n << endl;
    }
    return true;
}

void backTracking(int k, int K)
{
    if (isEnd)
        return;

    if (k == K)
    {
        if (check())
            isEnd = true;

        return;
    }

    // int tmpLadder[35][15];
    // for (int h = 0; h < 35; h++)
    //     for (int n = 0; n < 15; n++)
    //         tmpLadder[h][n] = ladder[h][n];

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (ladder[i][j])
                continue;

            if (ladder[i][j - 1] || ladder[i][j + 1])
                continue;

            // ⭐️ tmpVector 쓰지 말기 > 시간 초과 해결
            // for (int t = 0; t < k; t++)
            // {
            //     if (p[t].first == i && p[t].second == j)
            //         continue;
            // }

            if (k >= 1)
            {
                if (i <= p[k - 1].first && j <= p[k - 1].second)
                    continue;
            }

            ladder[i][j] = 1;
            p[k] = {i, j};
            backTracking(k + 1, K);

            ladder[i][j] = 0;
            //
            // for (int h = 0; h < 35; h++)
            //     for (int n = 0; n < 15; n++)
            //         ladder[h][n] = tmpLadder[h][n];
        }
    }
}

void dfs(int k, int K, int i, int j)
{
    if (isEnd)
        return;

    if (k == K)
    {
        if (check())
            isEnd = true;

        return;
    }

    for (int h = i; h <= H; h++) // ⭐️ 시간 줄이기!!
    {
        for (int n = j; n < N; n++)
        {
            if (!ladder[h][n] && !ladder[h][n - 1] && !ladder[h][n + 1])
            {
                ladder[h][n] = 1;
                dfs(k + 1, K, h, n);
                ladder[h][n] = 0;
            }
            j = 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    for (int l = 0; l <= 3; l++)
    {
        // backTracking(0, l);
        dfs(0, l, 1, 1);
        if (isEnd)
        {
            cout << l;
            return 0;
        }
    }

    cout << -1;

    // fout.close();
    return 0;
}