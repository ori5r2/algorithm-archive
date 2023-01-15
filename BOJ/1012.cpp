#include <bits/stdc++.h>
using namespace std;
#define MX 55

int T, M, N, K, cnt; // M 가로길이 , N 세로길이
int X, Y;
int board[MX][MX];
bool vis[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void printBoard(int b[MX][MX])
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        // 초기화
        memset(board, 0, sizeof(board)), memset(vis, 0, sizeof(vis)), cnt = 0;

        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> X >> Y;
            board[X][Y] = 1;
        }
        // printBoard(board);

        for (int l = 0; l < N; l++)
        {
            for (int t = 0; t < M; t++)
            {
                if (board[t][l] == 1 && vis[t][l] == 0)
                {
                    q.push({t, l}), vis[t][l] = 1, cnt++;
                }

                while (!q.empty())
                {
                    int x = q.front().first, y = q.front().second;
                    q.pop();

                    for (int m = 0; m < 4; m++)
                    {
                        int nx = x + dx[m], ny = y + dy[m];

                        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                            continue;
                        if (vis[nx][ny] || !board[nx][ny])
                            continue;

                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}