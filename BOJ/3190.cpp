#include <bits/stdc++.h>
using namespace std;
#define MX 102
#define X first
#define Y second

int N, K, r, c, L, s;
char ch;
int board[MX][MX];

// 오 아 왼 위 (시계방향)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int rotateInfo[10002];
int boardRotate[MX][MX];

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin); //

    cin >> N >> K;
    // 사과 위치
    for (int i = 0; i < K; i++)
    {
        cin >> r >> c;
        board[r][c] = -1; // 사과
    }
    // 뱀의 방향 정보
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> s;
        cin >> ch;
        if (ch == 'D') // 시계 방향
            rotateInfo[s] = 1;
        else if (ch == 'L') // 반시계 방향
            rotateInfo[s] = -1;
    }

    pair<int, int> head = {1, 1}, tail = {1, 1};
    board[1][1] = 1, boardRotate[1][1] = 0;
    int sec = 0;

    while (1)
    {
        sec++;
        int dir = boardRotate[head.X][head.Y];
        int x = head.X + dx[dir], y = head.Y + dy[dir];

        // 벽에 부딪히면
        if (x <= 0 || y <= 0 || x > N || y > N)
            break;

        if (board[x][y] == 1) // 자기자신과 부딪히면
            break;
        else if (board[x][y] == -1) // 사과라면
        {
            board[x][y] = 1, boardRotate[x][y] = dir;
            head = {x, y};
        }
        else
        {
            board[x][y] = 1, boardRotate[x][y] = dir;
            head = {x, y};

            // 꼬리 줄여줌
            int tailX = tail.X, tailY = tail.Y;
            board[tailX][tailY] = 0;
            int tailDir = boardRotate[tailX][tailY];
            tail = {tailX + dx[tailDir], tailY + dy[tailDir]};
        }

        // 방향
        if (rotateInfo[sec] == 1)
        {
            if (dir == 3)
                boardRotate[x][y] = 0;
            else
                boardRotate[x][y] = dir + 1;
        }
        else if (rotateInfo[sec] == -1)
        {
            if (dir == 0)
                boardRotate[x][y] = 3;
            else
                boardRotate[x][y] = dir - 1;
        }
    }

    cout << sec;
    return 0;
}