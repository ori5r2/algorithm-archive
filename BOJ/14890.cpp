#include <bits/stdc++.h>
using namespace std;
#define MX 102

int N, L, ans, cnt, h;
int board[MX][MX];
bool suc, tmp;

bool func() // 처리하지 못한 거
{
    if (cnt >= L)
    {
        cnt -= L;
        tmp = false;
        return true;
    }
    else
        return false;
}
// 규칙
void rule(int nextH)
{
    if (!suc)
        return;
    if (nextH == h) // 높이가 같을 떄
    {
        cnt++;
        if (tmp)
            func();
    }
    else if (nextH == h - 1) // 높이가 낮아질 때
    {
        if (tmp) // 일단 처리
        {
            if (!func())
                suc = false;
        }

        if (suc) // 처리했으면 다음거 진행
        {
            cnt = 1;
            h -= 1;
            tmp = true;
        }
    }
    else if (nextH == h + 1) // 높이가 높아질 때
    {
        if (tmp) // 일단 처리
        {
            if (!func())
                suc = false;
        }

        if (suc)
        {
            if (cnt >= L) // 처리했으면 다음 거 진행
            {
                h = nextH;
                cnt = 1;
            }
            else
                suc = false;
        }
    }
    else // 높이 차이가 1이상일 떄
    {
        suc = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    // 세로부터 확인
    for (int i = 0; i < N; i++)
    {
        h = board[i][0], cnt = 1;
        suc = true, tmp = false;
        for (int j = 1; j < N; j++)
        {
            rule(board[i][j]);
            if (!suc)
                break;
        }

        func();
        if (suc && !tmp)
            ans++;
    }

    // 가로부터 확인
    for (int j = 0; j < N; j++)
    {
        h = board[0][j];
        cnt = 1;
        suc = true, tmp = false;
        for (int i = 1; i < N; i++)
        {
            rule(board[i][j]);
            if (!suc)
                break;
        }
        func();
        if (suc && !tmp)
            ans++;
    }

    cout << ans;
    return 0;
}