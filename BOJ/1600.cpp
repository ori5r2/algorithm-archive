#include <bits/stdc++.h>
using namespace std;
#define MX 202

struct monkey
{
    pair<int, int> pos;
    int k;
};
int horX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horY[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int monX[] = {-1, 1, 0, 0};
int monY[] = {0, 0, -1, 1};
int K, W, H;
int board[MX][MX];
int visited[MX][MX][31];

void BFS()
{
    queue<monkey> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().pos.first, x = q.front().pos.second, cnt = q.front().k;
        int dist = visited[y][x][cnt];
        q.pop();

        // 말
        if (cnt < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int ny = y + horY[i], nx = x + horX[i], nk = cnt + 1;
                if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                    continue;
                if (visited[ny][nx][nk] || board[ny][nx])
                    continue;

                visited[ny][nx][nk] = dist + 1;
                // cout << "horse ";
                // cout << ny << " " << nx << " " << nk << " " << visited[ny][nx][nk] << endl;

                q.push({{ny, nx}, nk});
            }
        }

        // 원숭이
        for (int i = 0; i < 4; i++)
        {
            int ny = y + monY[i], nx = x + monX[i], nk = cnt;
            if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                continue;

            if (visited[ny][nx][nk] || board[ny][nx])
                continue;

            visited[ny][nx][nk] = dist + 1;
            // cout << "monkey ";
            // cout << ny << " " << nx << " " << nk << " " << visited[ny][nx][nk] << endl;

            q.push({{ny, nx}, nk});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    BFS();

    int minVal = INT_MAX;
    for (int k = 0; k <= K; k++)
    {
        if (visited[H - 1][W - 1][k] <= 0)
            continue;
        minVal = min(minVal, visited[H - 1][W - 1][k] - 1);
    }
    if (minVal == INT_MAX)
        cout << "-1";
    else
        cout << minVal;

    return 0;
}