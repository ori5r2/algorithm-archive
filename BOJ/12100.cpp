#include <bits/stdc++.h>
using namespace std;
#define MX 25

// fstream fout;
int N, tmp, ans;
int board[MX][MX];
int initBoard[MX][MX];
int arr[10];

// void printBoard()
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             fout << board[i][j] << " ";
//         fout << endl;
//     }
//     fout << endl;
// }

void up()
{
    for (int j = 0; j < N; j++)
    {
        // 빈칸 없애기
        int idx = -1;
        for (int i = 0; i < N; i++)
        {
            if (!board[i][j])
            {
                if (idx == -1)
                    idx = i;
            }
            else
            {
                if (idx == -1)
                    continue;
                else
                {
                    board[idx][j] = board[i][j];
                    board[i][j] = 0;

                    while (idx < N)
                    {
                        idx++;
                        if (!board[idx][j])
                            break;
                    }
                }
            }
        }

        // 같은 수끼리 합치기
        int n = -1;
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (!board[i][j])
                break;
            else
            {
                if (n == -1)
                {
                    n = board[i][j];
                    continue;
                }

                if (n == board[i][j])
                {
                    q.push(2 * n);
                    n = -1;
                }
                else
                {
                    q.push(n);
                    n = board[i][j];
                }
            }
        }
        if (n != -1)
            q.push(n);

        // 보드에 적기
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            board[i][j] = q.front();
            q.pop();
        }
        for (int i = s; i < N; i++)
            board[i][j] = 0;
    }
}

void down()
{
    for (int j = 0; j < N; j++)
    {
        // 빈칸 없애기
        int idx = -1;
        for (int i = N - 1; i >= 0; i--)
        {
            if (!board[i][j])
            {
                if (idx == -1)
                    idx = i;
            }
            else
            {
                if (idx == -1)
                    continue;
                else
                {
                    board[idx][j] = board[i][j];
                    board[i][j] = 0;

                    while (idx >= 0)
                    {
                        idx--;
                        if (!board[idx][j])
                            break;
                    }
                }
            }
        }

        // 같은 수끼리 합치기
        int n = -1;
        queue<int> q;
        for (int i = N - 1; i >= 0; i--)
        {
            if (!board[i][j])
                break;
            else
            {
                if (n == -1)
                {
                    n = board[i][j];
                    continue;
                }

                if (n == board[i][j])
                {
                    q.push(2 * n);
                    n = -1;
                }
                else
                {
                    q.push(n);
                    n = board[i][j];
                }
            }
        }
        if (n != -1)
            q.push(n);

        // 보드에 적기
        int s = q.size();
        for (int i = N - 1; i >= N - s; i--)
        {
            board[i][j] = q.front();
            q.pop();
        }
        for (int i = N - s - 1; i >= 0; i--)
            board[i][j] = 0;
    }
}

void left()
{
    for (int i = 0; i < N; i++)
    {
        // 빈칸 없애기
        int idx = -1;
        for (int j = 0; j < N; j++)
        {
            if (!board[i][j])
            {
                if (idx == -1)
                    idx = j;
            }
            else
            {
                if (idx == -1)
                    continue;
                else
                {
                    board[i][idx] = board[i][j];
                    board[i][j] = 0;

                    while (idx < N)
                    {
                        idx++;
                        if (!board[i][idx])
                            break;
                    }
                }
            }
        }

        // 같은 수끼리 합치기
        int n = -1;
        queue<int> q;
        for (int j = 0; j < N; j++)
        {
            if (!board[i][j])
                break;
            else
            {
                if (n == -1)
                {
                    n = board[i][j];
                    continue;
                }

                if (n == board[i][j])
                {
                    q.push(2 * n);
                    n = -1;
                }
                else
                {
                    q.push(n);
                    n = board[i][j];
                }
            }
        }
        if (n != -1)
            q.push(n);

        // 보드에 적기
        int s = q.size();
        for (int j = 0; j < s; j++)
        {
            board[i][j] = q.front();
            q.pop();
        }
        for (int j = s; j < N; j++)
            board[i][j] = 0;
    }
}

void right()
{
    for (int i = 0; i < N; i++)
    {
        // 빈칸 없애기
        int idx = -1;
        for (int j = N - 1; j >= 0; j--)
        {
            if (!board[i][j])
            {
                if (idx == -1)
                    idx = j;
            }
            else
            {
                if (idx == -1)
                    continue;
                else
                {
                    board[i][idx] = board[i][j];
                    board[i][j] = 0;

                    while (idx >= 0)
                    {
                        idx--;
                        if (!board[i][idx])
                            break;
                    }
                }
            }
        }

        // 같은 수끼리 합치기
        int n = -1;
        queue<int> q;
        for (int j = N - 1; j >= 0; j--)
        {
            if (!board[i][j])
                break;
            else
            {
                if (n == -1)
                {
                    n = board[i][j];
                    continue;
                }

                if (n == board[i][j])
                {
                    q.push(2 * n);
                    n = -1;
                }
                else
                {
                    q.push(n);
                    n = board[i][j];
                }
            }
        }
        if (n != -1)
            q.push(n);

        // 보드에 적기
        int s = q.size();
        for (int j = N - 1; j >= N - s; j--)
        {
            board[i][j] = q.front();
            q.pop();
        }
        for (int j = N - s - 1; j >= 0; j--)
            board[i][j] = 0;
    }
}

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = initBoard[i][j];
}

void playGame(int a)
{
    if (a == 1)
        up();
    else if (a == 2)
        down();
    else if (a == 3)
        left();
    else if (a == 4)
        right();
}

void findMax()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans = max(ans, board[i][j]);
}

void backTraking(int k)
{
    if (k == 5)
    {
        init();
        for (int i = 0; i < 5; i++)
        {
            playGame(arr[i]);
        }
        findMax();
        return;
    }

    for (int i = 1; i <= 4; i++)
    {
        arr[k] = i;
        backTraking(k + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> initBoard[i][j];

    backTraking(0);
    cout << ans;

    // fout.close();
    return 0;
}