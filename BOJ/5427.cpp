#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int T, W, H;
char board[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> sang;
queue<pair<int, int>> fire;
bool isFire[MX][MX];
bool visited[MX][MX];

void printBoard(bool b[MX][MX])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void BFS()
{
    bool finish = false, suc = false;
    int sec = 0;

    while (!finish)
    {
        sec++;

        // 불 먼저 번짐
        int len1 = fire.size();
        for (int f = 0; f < len1; f++)
        {
            int y = fire.front().first, x = fire.front().second;
            fire.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];

                if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                    continue;

                if (board[ny][nx] == '#' || isFire[ny][nx] == true)
                    continue;

                isFire[ny][nx] = true, fire.push({ny, nx});
            }
        }
        // printBoard(isFire);

        // 상근이가 움직임
        if (sang.empty())
            finish = true, suc = false;

        int len2 = sang.size();
        for (int s = 0; s < len2; s++)
        {
            int y = sang.front().first, x = sang.front().second;
            sang.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];

                if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                {
                    finish = true, suc = true;
                    continue;
                }

                if (visited[ny][nx] == true || board[ny][nx] == '#')
                    continue;
                if (isFire[ny][nx] == true)
                    continue;

                visited[ny][nx] = true, sang.push({ny, nx});
            }
        }
        // printBoard(visited);
    }

    if (suc)
        cout << sec << "\n";
    else
        cout << "IMPOSSIBLE\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        // 초기화
        memset(isFire, false, sizeof(isFire));
        memset(visited, false, sizeof(visited));
        memset(board, 0, sizeof(board));
        while (!sang.empty())
            sang.pop();
        while (!fire.empty())
            fire.pop();

        // 입력
        cin >> W >> H;
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                cin >> board[h][w];
                if (board[h][w] == '@')
                    sang.push({h, w}), visited[h][w] = 1;
                else if (board[h][w] == '*')
                    fire.push({h, w}), isFire[h][w] = 1;
            }
        }

        BFS();
    }

    return 0;
}