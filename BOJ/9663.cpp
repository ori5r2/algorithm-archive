#include <bits/stdc++.h>
using namespace std;
#define MX 15

int N, ret;
bool visited[MX][MX];
// 오른쪽 대각선, 왼쪽 대각선
int dx[] = {1, -1};
int dy[] = {-1, -1};

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
}

bool check(int y, int x)
{
    // 세로
    for (int ny = 0; ny < y; ny++)
    {
        if (visited[ny][x])
            return true;
    }
    // 오른쪽 대각선
    int ny = y, nx = x;
    for (int i = 0; i < y; i++)
    {
        ny = ny + dy[0], nx = nx + dx[0];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            break;
        if (visited[ny][nx])
            return true;
    }

    // 왼쪽 대각선
    ny = y, nx = x;
    for (int i = 0; i < y; i++)
    {
        ny = ny + dy[1], nx = nx + dx[1];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            break;
        if (visited[ny][nx])
            return true;
    }

    return false;
}

void nqueen(int k)
{
    if (k == N)
    {
        // printBoard();
        // cout << endl;
        ret++;
    }

    for (int j = 0; j < N; j++)
    {
        if (visited[k][j])
            continue;
        if (check(k, j))
            continue;

        visited[k][j] = true;
        nqueen(k + 1);
        visited[k][j] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    nqueen(0);
    cout << ret;

    return 0;
}