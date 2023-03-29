#include <bits/stdc++.h>
using namespace std;
#define MX 22

int N, r, c, ans = -1;
int A[MX][MX];
int cnt[6];

// void printBoard()
// {
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= N; j++)
//             cout << visited[i][j] << " ";
//         cout << endl;
//     }
//     cout << endl;
// }
// 기준점 (r, c) 일때
void func()
{
    int d1 = 1;
    while (1)
    {
        int d2 = 1;
        if (r + d1 + d2 > N || c - d1 < 1 || c + d2 > N)
            break;

        while (1)
        {

            if (r + d1 + d2 > N || c - d1 < 1 || c + d2 > N)
                break;
            // 선거구 나누기
            memset(cnt, 0, sizeof(cnt));
            // memset(visited, 0, sizeof(visited));
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (i >= 1 && i < r + d1) // 1번 선거구
                    {
                        if (i < r)
                        {
                            if (j >= 1 && j <= c)
                            {
                                cnt[1] += A[i][j];
                                continue;
                            }
                        }
                        else
                        {
                            if (j >= 1 && j < c - (i - r))
                            {
                                cnt[1] += A[i][j];
                                continue;
                            }
                        }
                    }

                    if (i >= 1 && i <= r + d2) // 2번 선거구
                    {
                        if (i < r)
                        {
                            if (j > c && j <= N)
                            {
                                cnt[2] += A[i][j];
                                continue;
                            }
                        }
                        else
                        {
                            if (j > c + (i - r) && j <= N)
                            {
                                cnt[2] += A[i][j];
                                continue;
                            }
                        }
                    }

                    if (r + d1 <= i && i <= N) // 3번 선거구
                    {
                        if (i > r + d1 + d2)
                        {
                            if (1 <= j && j < c - d1 + d2)
                            {
                                cnt[3] += A[i][j];
                                continue;
                            }
                        }
                        else
                        {
                            if (1 <= j && j < (c - d1 + d2) - ((r + d1 + d2) - i))
                            {
                                cnt[3] += A[i][j];
                                continue;
                            }
                        }
                    }

                    if (r + d2 < i && i <= N) // 4번 선거구
                    {
                        if (i > r + d1 + d2)
                        {
                            if (c - d1 + d2 <= j && j <= N)
                            {
                                cnt[4] += A[i][j];
                                continue;
                            }
                        }
                        else
                        {
                            if (j > (c - d1 + d2) + ((r + d1 + d2) - i) && j <= N)
                            {
                                cnt[4] += A[i][j];
                                continue;
                            }
                        }
                    }
                    // 5번 선거구
                    cnt[5] += A[i][j];
                }
            }
            // printBoard();
            //  차이 구하기
            // for (int i = 1; i <= 5; i++)
            //     cout << cnt[i] << " ";
            // cout << endl;
            int minVal = *min_element(begin(cnt) + 1, end(cnt));
            int maxVal = *max_element(begin(cnt) + 1, end(cnt));
            // cout << minVal << " " << maxVal << " " << maxVal - minVal << endl;
            if (ans == -1)
                ans = maxVal - minVal;
            else
                ans = min(ans, maxVal - minVal);
            d2 += 1;
        }
        d1 += 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            r = i, c = j;
            func();
        }
    }
    cout << ans << endl;
    return 0;
}