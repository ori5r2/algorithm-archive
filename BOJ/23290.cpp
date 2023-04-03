#include <bits/stdc++.h>
using namespace std;

// fstream fout;

struct fish
{
    pair<int, int> pos;
    int dir;
};
int M, S;
int r, c, d;
vector<int> board[5][5];
vector<int> tmpBoard[5][5];
int smell[5][5];
pair<int, int> shark;
queue<fish> fishes;

int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
// ⭐️ 상좌하우
int dx2[] = {0, 0, -1, 0, 1};
int dy2[] = {0, -1, 0, 1, 0};

// void printSmell()
// {
//     for (int i = 1; i <= 4; i++)
//     {
//         for (int j = 1; j <= 4; j++)
//         {
//             fout << smell[i][j] << " ";
//         }
//         fout << endl;
//     }
//     fout << endl;
// }

// void printBoard(vector<int> b[5][5])
// {
//     for (int i = 1; i <= 4; i++)
//     {
//         for (int j = 1; j <= 4; j++)
//         {
//             if (b[i][j].empty())
//                 continue;
//             fout << i << " " << j << endl;
//             for (int t = 0; t < b[i][j].size(); t++)
//                 fout << b[i][j][t] << " ";
//             fout << endl;
//         }
//         fout << endl;
//     }
//     fout << endl;
// }

void mvFish()
{
    while (!fishes.empty())
    {
        int y = fishes.front().pos.first, x = fishes.front().pos.second, dir = fishes.front().dir;
        fishes.pop();
        bool suc = false;
        for (int d = 0; d < 8; d++)
        {
            int nowDir = dir - d; // 반시계!!
            if (nowDir <= 0)
                nowDir += 8;

            int ny = y + dy[nowDir], nx = x + dx[nowDir];

            if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4) // 격자 범위 넘어가는 칸
                continue;
            if (smell[ny][nx]) // 물고기 냄새 있는 칸
                continue;
            if (ny == shark.first && nx == shark.second) // 상어 있는 칸
                continue;

            tmpBoard[ny][nx].push_back(nowDir);
            suc = true;
            break;
        }
        if (!suc)
        {
            tmpBoard[y][x].push_back(dir);
            // int nowDir = dir + 1;
            // if (nowDir > 8)
            //     nowDir %= 8;
            // tmpBoard[y][x].push_back(nowDir);
        }
    }
}

int check(int a)
{
    int ret = 0;
    while ((a % 10))
    {
        ret += 1;
        a /= 10;
    }
    return ret;
}

void mvShark()
{ // 수정 필요!
    vector<int> mv;
    int mx = 0;

    for (int l : {1, 2, 3, 4})
    {
        int y = shark.first + dy2[l], x = shark.second + dx2[l];
        if (y <= 0 || x <= 0 || y > 4 || x > 4)
            continue;

        int val1 = tmpBoard[y][x].size();
        for (int m : {1, 2, 3, 4})
        {
            int ny = y + dy2[m], nx = x + dx2[m];
            if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4)
                continue;

            int val2 = 0;
            // 중복 거르기
            if (y == ny && x == nx)
                val2 = 0;
            else
                val2 = tmpBoard[ny][nx].size();

            for (int n : {1, 2, 3, 4})
            {
                int nny = ny + dy2[n], nnx = nx + dx2[n];
                if (nny <= 0 || nnx <= 0 || nny > 4 || nnx > 4)
                    continue;

                int val3 = 0;

                if (nny == ny && nnx == nx)
                    val3 = 0;
                else if (nny == y && nnx == x)
                    val3 = 0;
                else
                    val3 = tmpBoard[nny][nnx].size();

                int val = val1 + val2 + val3;

                if (mv.empty())
                {
                    mx = val;
                    mv.push_back(l), mv.push_back(m), mv.push_back(n);
                    continue;
                }

                if (mx < val)
                {
                    mx = val;
                    mv.clear();
                    mv.push_back(l), mv.push_back(m), mv.push_back(n);
                }
                else if (mx == val)
                {

                    if (l < mv[0])
                    {
                        mv.clear();
                        mv.push_back(l), mv.push_back(m), mv.push_back(n);
                    }
                    else if (l == mv[0])
                    {
                        if (m < mv[1])
                        {
                            mv.clear();
                            mv.push_back(l), mv.push_back(m), mv.push_back(n);
                        }
                        else if (m == mv[1])
                        {
                            if (n < mv[2])
                            {
                                mv.clear();
                                mv.push_back(l), mv.push_back(m), mv.push_back(n);
                            }
                        }
                    }
                }
            }
        }
    }

    int y = shark.first, x = shark.second;
    for (int d = 0; d < 3; d++)
    {
        y = y + dy2[mv[d]], x = x + dx2[mv[d]];
        if (!tmpBoard[y][x].empty())
        {
            tmpBoard[y][x].clear();
            smell[y][x] = 2;
        }
    }
    shark = {y, x};
}

void rmSmell()
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            if (smell[i][j])
                smell[i][j] -= 1;
        }
}

void cp()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (!board[i][j].empty())
            {
                for (int l = 0; l < board[i][j].size(); l++)
                    fishes.push({{i, j}, board[i][j][l]});
            }

            while (!tmpBoard[i][j].empty())
            {
                board[i][j].push_back(tmpBoard[i][j].back());
                fishes.push({{i, j}, tmpBoard[i][j].back()});
                tmpBoard[i][j].pop_back();
            }
        }
    }
}

int count()
{
    int ret = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            ret += board[i][j].size();
        }
    }
    return ret;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> M >> S;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> d;
        board[r][c].push_back(d);
        fishes.push({{r, c}, d});
    }
    cin >> shark.first >> shark.second;

    for (int s = 0; s < S; s++)
    {
        // 모든 물고기에게 복제 마법 시전
        // 물고기 한 칸 이동
        mvFish();
        // 물고기 냄새 사라짐
        rmSmell();
        // 상어 연속 3칸 이동 + 물고기 냄새
        mvShark();
        // 복제 완료
        cp();
    }

    cout << count();

    // fout.close();
    return 0;
}