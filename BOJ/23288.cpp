#include <bits/stdc++.h>
using namespace std;
#define MX 25

// fstream fout;
int N, M, K, ans;
int A, B, C;
int board[MX][MX];
bool visited[MX][MX];

// 동 남 서 북
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<pair<int, int>, int> info;   // pos, dir
int dice[6] = {2, 4, 1, 3, 5, 6}; // dice[5] : 아랫면
int tmp[6];
queue<pair<int, int>> q;

void east()
{
    for (int i = 0; i < 6; i++)
        tmp[i] = dice[i];

    dice[1] = tmp[5];
    dice[2] = tmp[1];
    dice[3] = tmp[2];
    dice[5] = tmp[3];
}

void south()
{
    for (int i = 0; i < 6; i++)
        tmp[i] = dice[i];

    dice[0] = tmp[5];
    dice[2] = tmp[0];
    dice[4] = tmp[2];
    dice[5] = tmp[4];
}

void west()
{
    for (int i = 0; i < 6; i++)
        tmp[i] = dice[i];

    dice[1] = tmp[2];
    dice[2] = tmp[3];
    dice[3] = tmp[5];
    dice[5] = tmp[1];
}

void north()
{
    for (int i = 0; i < 6; i++)
        tmp[i] = dice[i];

    dice[0] = tmp[2];
    dice[2] = tmp[4];
    dice[4] = tmp[5];
    dice[5] = tmp[0];
}

void mvDice(int k)
{
    if (k == 0)
        east();
    else if (k == 1)
        south();
    else if (k == 2)
        west();
    else if (k == 3)
        north();
}

// void printDice()
// {
//     fout << "  " << dice[0] << endl;
//     fout << dice[1] << " " << dice[2] << " " << dice[3] << endl;
//     fout << "  " << dice[4] << endl;
//     fout << "  " << dice[5] << endl;
//     fout << endl;
// }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    // init
    info = {{0, 0}, 0};

    for (int k = 0; k < K; k++)
    {
        memset(visited, false, sizeof(visited));
        int y = info.first.first, x = info.first.second, dir = info.second;
        int ny = y + dy[dir], nx = x + dx[dir];
        // fout << y << " " << x << " " << ny << " " << nx << " " << dir << endl;

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) // 이동방향에 칸이 없다면, 이동방향을 반대로 함
        {
            dir = (dir + 2) % 4;
            ny = y + dy[dir], nx = x + dx[dir];
        }

        mvDice(dir);
        A = dice[5];
        B = board[ny][nx];
        C = 1;
        q.push({ny, nx});
        visited[ny][nx] = true;

        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dy[d], nc = c + dx[d];
                if (nr < 0 || nc < 0 || nr >= N || nc >= M)
                    continue;
                if (visited[nr][nc])
                    continue;

                if (board[nr][nc] == B)
                {
                    C++;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        if (A > B)
            dir = (dir + 1) % 4;
        else if (A < B)
            dir = (dir + 3) % 4;

        info = {{ny, nx}, dir};
        ans += (B * C);

        // fout << A << " " << B << " " << C << endl;
        // fout << endl;
        // printDice();
    }
    cout << ans;
    // fout.close();
    return 0;
}