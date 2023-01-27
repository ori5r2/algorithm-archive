#include <bits/stdc++.h>
using namespace std;
#define MX 127
#define INF 1987654321

int board[MX][MX], cost[MX][MX];
int N, idx = 1;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push({0, 0}), cost[0][0] = board[0][0];

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        int nowCost = cost[x][y];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            if (cost[nx][ny] > nowCost + board[nx][ny])
            {
                cost[nx][ny] = nowCost + board[nx][ny];
                q.push({nx, ny});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;

        // 초기화
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cost[i][j] = INF;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> board[i][j];

        BFS();
        cout << "Problem " << idx << ": " << cost[N - 1][N - 1] << "\n";
        idx++;
    }
    return 0;
}