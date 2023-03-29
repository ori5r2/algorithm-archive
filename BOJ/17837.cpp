#include <bits/stdc++.h>
using namespace std;
#define MX 15

// fstream fout;

struct horse
{
    pair<int, int> pos;
    int idx;
    int dir;
};

bool suc = false;
int N, K;
int a, b, c;
int board[MX][MX]; // 0:흰색, 1:빨간색, 2:파란색
deque<int> horseMap[MX][MX];
horse horses[MX];

// 오 왼 위 아
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int changeDir(int x)
{
    int ret = 0;
    if (x == 1)
        ret = 2;
    else if (x == 2)
        ret = 1;
    else if (x == 3)
        ret = 4;
    else if (x == 4)
        ret = 3;

    return ret;
}

// void printBoard()
// {
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= N; j++)
//         {
//             fout << i << " " << j << ": ";
//             for (int s = 0; s < horseMap[i][j].size(); s++)
//             {
//                 fout << horseMap[i][j][s] << " ";
//             }
//             fout << endl;
//         }
//         fout << endl;
//     }
// }

// void printHorse()
// {
//     for (int i = 1; i <= K; i++)
//     {
//         fout << i << " : " << horses[i].pos.first << " " << horses[i].pos.second << endl;
//         fout << horses[i].idx << " " << horses[i].dir << endl;
//     }
//     fout << endl;
// }

bool isEnd()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (horseMap[i][j].size() >= 4)
            {
                suc = true;
                return true;
            }
        }
    }
    return false;
}

void mvWhite(int y, int x, int idx, int ny, int nx)
{

    deque<int> dq;

    int size = horseMap[y][x].size() - idx;
    for (int t = 0; t < size; t++) // 위에 있는거
    {
        dq.push_back(horseMap[y][x].back());
        horseMap[y][x].pop_back();
    }

    // horseMap에 반영
    while (!dq.empty())
    {
        int h = dq.back();
        // horse 정보 변경
        horses[h].pos = {ny, nx};
        horses[h].idx = horseMap[ny][nx].size();

        horseMap[ny][nx].push_back(h);
        dq.pop_back();
    }
}

void mvRed(int y, int x, int idx, int ny, int nx)
{
    deque<int> dq;

    int size = horseMap[y][x].size() - idx;
    for (int t = 0; t < size; t++)
    {
        dq.push_back(horseMap[y][x].back());
        horseMap[y][x].pop_back();
    }

    while (!dq.empty())
    {
        int h = dq.front();
        // horse 정보 변경
        horses[h].pos = {ny, nx};
        horses[h].idx = horseMap[ny][nx].size();

        horseMap[ny][nx].push_back(h);
        dq.pop_front();
    }
}

void round()
{
    for (int i = 1; i <= K; i++)
    {
        // ⭐️ 턴이 진행되는 동안 말이 4개 이상 쌓이면 게임 종료!!
        if (isEnd())
            break;
        int y = horses[i].pos.first, x = horses[i].pos.second, d = horses[i].dir, idx = horses[i].idx;
        int ny = y + dy[d], nx = x + dx[d];
        deque<int> dq;

        if (ny <= 0 || nx <= 0 || ny > N || nx > N)
        {
            horses[i].dir = changeDir(d);
            ny = y + dy[horses[i].dir], nx = x + dx[horses[i].dir];
            if (ny <= 0 || nx <= 0 || ny > N || nx > N)
                continue;

            if (board[ny][nx] == 2) // 또 파란색이면 가만히
                continue;
            else if (board[ny][nx] == 1)
                mvRed(y, x, idx, ny, nx);
            else if (board[ny][nx] == 0)
                mvWhite(y, x, idx, ny, nx);

            // printBoard();
            continue;
        }

        int color = board[ny][nx];

        if (color == 0) // 흰색인 경우
            mvWhite(y, x, idx, ny, nx);
        else if (color == 1) // 빨간색인 경우
            mvRed(y, x, idx, ny, nx);
        else if (color == 2) // 파란색인 경우
        {
            horses[i].dir = changeDir(d);
            ny = y + dy[horses[i].dir], nx = x + dx[horses[i].dir];

            if (ny <= 0 || nx <= 0 || ny > N || nx > N)
                continue;

            if (board[ny][nx] == 2) // 또 파란색이면 가만히
                continue;
            else if (board[ny][nx] == 1)
                mvRed(y, x, idx, ny, nx);
            else if (board[ny][nx] == 0)
                mvWhite(y, x, idx, ny, nx);
        }
        // printBoard();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    for (int i = 1; i <= K; i++)
    {
        cin >> a >> b >> c;
        int idx = horseMap[a][b].size();
        horseMap[a][b].push_back(i);
        horses[i] = {{a, b}, idx, c};
    }

    int ans = 0;
    while (1)
    {
        if (isEnd())
            break;

        if (ans > 1000)
        {
            ans = -1;
            break;
        }
        ans++;
        round();
        if (suc)
            break;
    }

    cout << ans;

    // fout.close();
    return 0;
}