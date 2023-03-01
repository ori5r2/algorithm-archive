#include <bits/stdc++.h>
using namespace std;
#define MX 1002

struct room
{
    pair<int, int> pos;
    int breakCnt;
};

int N, M, K;
string str;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int board[MX][MX];
int visited[MX][MX][11];

void BFS()
{
    queue<room> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().pos.first, x = q.front().pos.second, k = q.front().breakCnt;
        int dist = visited[y][x][k];
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d], nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (board[ny][nx] == 0 && !visited[ny][nx][k])
            {
                visited[ny][nx][k] = dist + 1;
                q.push({{ny, nx}, k});
                // cout << ny << " " << nx << " " << visited[ny][nx][k] << endl;
            }

            if (board[ny][nx] == 1 && k < K && !visited[ny][nx][k + 1])
            {
                visited[ny][nx][k + 1] = dist + 1;
                q.push({{ny, nx}, k + 1});
                // cout << ny << " " << nx << " " << visited[ny][nx][k + 1] << endl;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
            board[i][j] = str[j] - '0';
    }

    BFS();
    int minDist = INT_MAX;
    for (int k = 0; k <= K; k++)
    {
        if (!visited[N - 1][M - 1][k])
            continue;
        minDist = min(minDist, visited[N - 1][M - 1][k]);
    }

    if (minDist == INT_MAX)
        cout << "-1";
    else
        cout << minDist;

    return 0;
}