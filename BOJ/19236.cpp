#include <bits/stdc++.h>
using namespace std;

int a, b, ans = 0;
struct fish
{
    pair<int, int> pos;
    int dir;
    bool isAlive;
};
fish fishes[17]; // 1~16 물고기 정보

// num = 1~16 : 물고기  , num=-1 : 상어 num=0 : 빈칸
pair<int, int> board[4][4]; // num, dir
struct sk
{
    pair<int, int> pos;
    int weight;
};
sk shark;
// ofstream fout;

// ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void printBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << board[i][j].first << " " << board[i][j].second + 1 << "  ";
        cout << endl;
    }
    cout << endl;
}

void init() // (0, 0)에 있는 물고기 먹고 들어감 (먹으면 방향 똑같아짐)
{
    shark.pos = {0, 0}, shark.weight = board[0][0].first;
    fishes[board[0][0].first].isAlive = false;
    board[0][0].first = -1;
}

void mv() // 물고기 이동
{
    for (int i = 1; i <= 16; i++)
    {
        if (!fishes[i].isAlive)
        {
            // fout << i << " ";
            continue;
        }
        int y = fishes[i].pos.first, x = fishes[i].pos.second;
        for (int d = 0; d < 8; d++)
        {
            int dir = (fishes[i].dir + d) % 8;
            int ny = y + dy[dir], nx = x + dx[dir];

            // 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전
            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) // 벽
                continue;

            if (board[ny][nx].first == -1) // 상어
                continue;

            if (board[ny][nx].first == 0) // 빈칸
            {
                fishes[i] = {{ny, nx}, dir, true}; // 물고기 정보 변경
                board[ny][nx] = {i, dir};          // 보드판 변경 (빈칸 자리)
                board[y][x] = {0, -1};             // 보드판 변경 (원래 물고기 있던 자리)
                break;
            }
            else // 상어가 있다면
            {
                // 물고기 정보 바꾸기
                fishes[i] = {{ny, nx}, dir, true}; // 현재 물고기
                fishes[board[ny][nx].first].pos = {y, x};
                // 보드판 바꾸기
                board[y][x] = board[ny][nx]; // 다른 물고기가 현재 자리로 이동
                board[ny][nx] = {i, dir};    // 현재 물고기 이동
                break;
            }
        }
    }
    // fout << endl;
}

void eating(int a, int b)
{
    int num = board[a][b].first;
    pair<int, int> p = shark.pos;
    // shark 정보 변경
    shark.weight += num;
    shark.pos = {a, b};
    // fish 정보 변경
    fishes[num].isAlive = false;
    // 보드판 변경
    board[a][b].first = -1;             // 물고기 자리 > 상어
    board[p.first][p.second] = {0, -1}; // 상어 자리 > 빈칸
}

void func()
{
    // fout << "before MV" << endl;
    // printBoard();
    mv();
    // fout << "after MV" << endl;
    // printBoard();

    // 더이상 갈곳이 없다면 return
    int y = shark.pos.first, x = shark.pos.second;
    int d = board[y][x].second;

    pair<int, int> nowBoard[4][4]; // 저장
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            nowBoard[i][j] = board[i][j];
    fish nowFishes[17];
    for (int i = 1; i <= 16; i++)
        nowFishes[i] = fishes[i];

    for (int i = 1; i < 4; i++) // 최대 3칸 움직일 수 있음
    {
        int ny = y + dy[d] * i, nx = x + dx[d] * i;
        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
            continue;
        if (board[ny][nx].first == 0) // 물고기가 없는 칸
            continue;
        // fout << "before" << endl;
        // for (int i = 1; i <= 16; i++)
        //     fout << i << " " << fishes[i].pos.first << " " << fishes[i].pos.second << " " << fishes[i].dir << " " << fishes[i].isAlive << endl;

        // 물고기 먹기
        int num = board[ny][nx].first;
        // shark 정보 변경
        shark.weight += num;
        shark.pos = {ny, nx};
        // fish 정보 변경
        fishes[num].isAlive = false;
        // 보드판 변경
        board[ny][nx].first = -1; // 물고기 자리 > 상어
        board[y][x] = {0, -1};    // 상어 자리 > 빈칸

        func();

        // shark 정보 되돌리기
        shark.weight -= num;
        shark.pos = {y, x};
        // fish 정보 되돌리기
        for (int i = 1; i <= 16; i++)
            fishes[i] = nowFishes[i];

        // fout << "after" << endl;
        // for (int i = 1; i <= 16; i++)
        //     fout << i << " " << fishes[i].pos.first << " " << fishes[i].pos.second << " " << fishes[i].dir << " " << fishes[i].isAlive << endl;

        // 보드판 정보 되돌리기
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = nowBoard[i][j];
            }
        }
    }
    ans = max(ans, shark.weight);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // fout.open("test.txt");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a >> b;
            board[i][j] = {a, b - 1};
            fishes[a] = {{i, j}, b - 1, true}; // 물고기 정보 저장
        }
    }

    init();
    func();
    cout << ans;
    // fout.close();

    return 0;
}