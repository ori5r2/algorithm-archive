#include <bits/stdc++.h>
using namespace std;

int topnis[5][10];
int dir[5][102];
string s;
int K, topni, d;
int score[] = {1, 2, 4, 8};

bool check(int A, int B, int k) // 톱니 A와 톱니 B가 마주치는 지 확인 (A<B)
{
    bool ret = false;
    int dir_beforeA = (2 - dir[A][k - 1]) % 8;
    int dir_beforeB = (6 - dir[B][k - 1]) % 8;

    if (dir_beforeA < 0)
        dir_beforeA += 8;
    if (dir_beforeB < 0)
        dir_beforeB += 8;

    if (topnis[A][dir_beforeA] != topnis[B][dir_beforeB])
        ret = true;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    for (int i = 1; i <= 4; i++)
    {
        cin >> s;
        for (int j = 0; j < 8; j++)
            topnis[i][j] = s[j] - '0';
    }

    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> topni >> d;
        for (int j = 1; j <= 4; j++)
            dir[j][i] = dir[j][i - 1];

        if (topni == 1) // 1번 톱니를 돌릴 때
        {
            dir[1][i] = dir[1][i - 1] + d;
            if (check(1, 2, i))
            {
                dir[2][i] = dir[2][i - 1] - d;
                if (check(2, 3, i))
                {
                    dir[3][i] = dir[3][i - 1] + d;
                    if (check(3, 4, i))
                        dir[4][i] = dir[4][i - 1] - d;
                }
            }
        }
        else if (topni == 2) // 2번 톱니를 돌릴 때
        {
            dir[2][i] = dir[2][i - 1] + d;
            if (check(1, 2, i))
                dir[1][i] = dir[1][i - 1] - d;
            if (check(2, 3, i))
            {
                dir[3][i] = dir[3][i - 1] - d;
                if (check(3, 4, i))
                    dir[4][i] = dir[4][i - 1] + d;
            }
        }
        else if (topni == 3) // 3번 톱니를 돌릴 때
        {
            dir[3][i] = dir[3][i - 1] + d;
            if (check(2, 3, i))
            {
                dir[2][i] = dir[2][i - 1] - d;
                if (check(1, 2, i))
                {
                    dir[1][i] = dir[1][i - 1] + d;
                }
            }
            if (check(3, 4, i))
                dir[4][i] = dir[4][i - 1] - d;
        }
        else if (topni == 4) // 4번 톱니를 돌릴 때
        {
            dir[4][i] = dir[4][i - 1] + d;
            if (check(3, 4, i))
            {
                dir[3][i] = dir[3][i - 1] - d;
                if (check(2, 3, i))
                {
                    dir[2][i] = dir[2][i - 1] + d;
                    if (check(1, 2, i))
                    {
                        dir[1][i] = dir[1][i - 1] - d;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        int dir_topni = (0 - dir[i][K]) % 8;
        if (dir_topni < 0)
            dir_topni += 8;

        if (topnis[i][dir_topni] == 1)
            ans += score[i - 1];
    }

    cout << ans;

    return 0;
}