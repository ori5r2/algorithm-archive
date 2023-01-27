#include <bits/stdc++.h>
using namespace std;
#define MX 52

int W, H;
int board[MX][MX];
bool visited[MX][MX];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void printBoard()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int BFS()
{
    queue<pair<int, int>> q; // x, y
    int cnt = 0;

    for (int i = 0; i < H; i++) // i : y
    {
        for (int j = 0; j < W; j++) // j : x
        {
            if (board[i][j] == 1 && visited[i][j] == false)
            {
                cnt++;
                q.push({j, i}), visited[i][j] = true;
            }

            while (!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int d = 0; d < 8; d++)
                {
                    int nx = x + dx[d], ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= W || ny >= H)
                        continue;
                    if (board[ny][nx] == 0 || visited[ny][nx] == true)
                        continue;

                    q.push({nx, ny}), visited[ny][nx] = true;
                }
            }
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    while (1)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
            return 0;

        // 초기화
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                board[i][j] = 0, visited[i][j] = false;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> board[i][j];

        cout << BFS() << "\n";
    }

    return 0;
}