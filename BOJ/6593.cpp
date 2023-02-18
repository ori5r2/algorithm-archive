#include <bits/stdc++.h>
using namespace std;
#define MX 32

struct block
{
    int height, row, col;
};

int L, R, C;
string s;
char board[MX][MX][MX];
int visited[MX][MX][MX];
block start, finish;

int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

void BFS()
{
    queue<block> q;
    q.push(start), visited[start.height][start.row][start.col] = 1;
    int min = 0;

    while (!q.empty())
    {
        if (min)
            break;

        block now = q.front();
        int nowH = now.height, nowR = now.row, nowC = now.col;
        int nowV = visited[nowH][nowR][nowC];
        q.pop();

        for (int d = 0; d < 6; d++)
        {
            int nextH = nowH + dh[d], nextR = nowR + dy[d], nextC = nowC + dx[d];

            if (nextH < 0 || nextR < 0 || nextC < 0 || nextH >= L || nextR >= R || nextC >= C)
                continue;
            if (visited[nextH][nextR][nextC] || board[nextH][nextR][nextC] == '#')
                continue;

            if (nextH == finish.height && nextR == finish.row && nextC == finish.col)
                min = nowV;

            q.push({nextH, nextR, nextC});
            visited[nextH][nextR][nextC] = nowV + 1;
        }
    }

    if (min)
        cout << "Escaped in " << min << " minute(s).\n";
    else
        cout << "Trapped!\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("../input.txt", "r", stdin);

    while (1)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            break;

        // 초기화
        memset(visited, 0, sizeof(visited));
        memset(board, 0, sizeof(board));
        // 입력
        for (int l = 0; l < L; l++)
        {
            for (int r = 0; r < R; r++)
            {
                cin >> s;
                for (int c = 0; c < C; c++)
                {
                    board[l][r][c] = s[c];
                    if (s[c] == 'S')
                        start = {l, r, c};
                    if (s[c] == 'E')
                        finish = {l, r, c};
                }
            }
        }

        BFS();
    }

    return 0;
}