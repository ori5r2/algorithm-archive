#include <bits/stdc++.h>
using namespace std;
#define MX 25

// ofstream fout;
struct sharkInfo // 상어정보
{
    pair<int, int> pos; // 위치
    int dir;            // 방향
    bool isAlive;       // 격자 밖으로 나갔는지
    int priority[5][5]; // 우선 순위
};
struct mvInfo
{
    pair<int, int> pos;
    int dir;
};
// input
int N, M, k, num, ans;

// 상어 번호, 시간
pair<int, int> board[MX][MX];
sharkInfo shark[405];

// 위 아래 왼 오
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, -1, 1, 0, 0};

// void printBoard()
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             fout << board[i][j].first << " " << board[i][j].second << "  ";
//         fout << endl;
//     }
//     fout << endl;
// }

// void printShark()
// {
//     for (int i = 1; i <= M; i++)
//     {
//         if (shark[i].isAlive)
//         {
//             fout << i << " pos: " << shark[i].pos.first << " " << shark[i].pos.second << " & dir: " << shark[i].dir << endl;
//         }
//     }
// }

void mv() // 상어 이동
{
    mvInfo info[405];

    // 상어 이동할 공간 확인
    for (int i = 1; i <= M; i++)
    {
        sharkInfo tmp = shark[i];
        if (!tmp.isAlive)
            continue;

        int y = tmp.pos.first, x = tmp.pos.second, dir = tmp.dir;
        mvInfo self = {{-1, -1}, 0};
        bool emt = false;

        for (int p = 0; p < 4; p++)
        {
            int d = tmp.priority[dir][p];
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (board[ny][nx].first == 0) // 아무냄새 없는 칸
            {
                info[i] = {{ny, nx}, d};
                emt = true;
                break;
            }
            else if (board[ny][nx].first == i)
            {
                if (self.dir == 0)
                    self = {{ny, nx}, d};
            }
        }
        if (!emt)
            info[i] = self;
    }

    // 1초씩 줄임
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j].second)
            {
                board[i][j].second -= 1;
                if (board[i][j].second == 0)
                    board[i][j].first = 0;
            }
        }
    }

    // for (int i = 1; i <= M; i++)
    // {
    //     if (!shark[i].isAlive)
    //         fout << i << " : dead" << endl;
    //     else
    //         fout << i << " : " << info[i].pos.first << " " << info[i].pos.second << " " << info[i].dir << endl;
    // }
    // fout << endl;

    // 상어 이동
    for (int i = 1; i <= M; i++)
    {
        if (shark[i].isAlive)
        {
            int y = info[i].pos.first, x = info[i].pos.second, d = info[i].dir;
            if (board[y][x].first == 0 || board[y][x].first == i)
            {
                board[y][x] = {i, k};
                shark[i].pos = {y, x}, shark[i].dir = d;
            }
            else
            {
                shark[i].isAlive = false;
            }
        }
    }
}

bool check()
{
    if (!shark[1].isAlive)
        return false;

    for (int i = 2; i <= M; i++)
    {
        if (shark[i].isAlive)
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    //  fout.open("output.txt");

    cin >> N >> M >> k;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (num == 0) // 빈칸
                board[i][j] = {0, 0};
            else // 상어
            {
                board[i][j] = {num, k};
                shark[num].pos = {i, j};
                shark[num].isAlive = true;
            }
        }
    }
    for (int t = 1; t <= M; t++)
        cin >> shark[t].dir;

    for (int t = 1; t <= M; t++)
        for (int i = 1; i <= 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> shark[t].priority[i][j];

    while (1)
    {
        // printBoard();
        mv();
        ans++;

        if (check())
        {
            cout << ans;
            break;
        }
        if (ans >= 1000) // ⭐️ 1000초 넘어도 ??
        {
            cout << -1;
            break;
        }
    }

    // fout.close();
    return 0;
}