#include <bits/stdc++.h>
using namespace std;

int N, Q, L;
int board[1 << 6][1 << 6];
bool visited[1 << 6][1 << 6];
int x, y;
// 오 아 왼 위
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<int> q;
queue<pair<int, int>> del;
queue<pair<int, int>> qice;

void printBoard()
{
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < (1 << N); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void rotate(int idx, int dir)
{
    for (int t = 0; t < idx; t++) // 아래
    {
        y = y + dy[dir], x = x + dx[dir];
        q.push(board[y][x]);
    }
}

void rotate2(int idx, int dir)
{
    for (int t = 0; t < idx; t++) // 아래
    {
        y = y + dy[dir], x = x + dx[dir];
        board[y][x] = q.front();
        q.pop();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> Q;
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < (1 << N); j++)
            cin >> board[i][j];

    while (Q-- > 0)
    {
        cin >> L;
        // 2^L로 나눠서 시계방향 90도 회전
        // printBoard();
        if (L != 0)
        {
            for (int i = 0; i < (1 << N); i += (1 << L))
            {
                for (int j = 0; j < (1 << N); j += (1 << L))
                {
                    q.push(board[i][j]);
                    // 왼쪽으로 2^L-1만큼
                    int idx = (1 << L) - 1;
                    y = i, x = j;
                    rotate(idx, 0);

                    // 중간 2^(L-1)-1만큼
                    for (int l = 0; l < (1 << (L - 1)) - 1; l++)
                    {
                        rotate(idx, 1); // 아래
                        rotate(idx, 2); // 왼쪽
                        idx -= 1;
                        rotate(idx, 3); // 위
                        rotate(idx, 0); // 오른쪽
                        idx -= 1;
                    }
                    // 아래 왼
                    rotate(1, 1);
                    rotate(1, 2);

                    // 90도 회전 //
                    y = i, x = j + (1 << L) - 1;
                    board[y][x] = q.front();
                    q.pop();
                    idx = (1 << L) - 1;
                    rotate2(idx, 1); // 아래

                    // 중간 2^(L-1)-1만큼
                    for (int l = 0; l < (1 << (L - 1)) - 1; l++)
                    {
                        rotate2(idx, 2); // 왼
                        rotate2(idx, 3); // 위
                        idx -= 1;
                        rotate2(idx, 0); // 오
                        rotate2(idx, 1); // 아
                        idx -= 1;
                    }
                    // 왼 위
                    rotate2(1, 2);
                    rotate2(1, 3);
                }
            }
        }
        // printBoard();
        //  얼음 있는 칸 3 미만 > 1줄어들기
        for (int i = 0; i < (1 << N); i++)
        {
            for (int j = 0; j < (1 << N); j++)
            {
                int cnt = 0;
                if (!board[i][j])
                    continue;
                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (ny < 0 || nx < 0 || ny >= (1 << N) || nx >= (1 << N))
                        continue;
                    if (board[ny][nx] > 0)
                        cnt++;
                }
                if (cnt < 3)
                    del.push({i, j});
            }
        }

        while (!del.empty())
        {
            int ny = del.front().first, nx = del.front().second;
            board[ny][nx] -= 1;
            del.pop();
        }
    }

    // 출력
    // 남아있는 얼음 A[r][c]
    int ice = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            if (board[i][j])
                ice += board[i][j];
        }
    }
    // 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
    int maxIce = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            int tmpIce = 0;
            if (board[i][j] && !visited[i][j])
            {
                qice.push({i, j});
                tmpIce = 1;
                visited[i][j] = true;
            }
            while (!qice.empty())
            {
                int y = qice.front().first, x = qice.front().second;
                qice.pop();
                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (ny < 0 || nx < 0 || ny >= (1 << N) || nx >= (1 << N))
                        continue;
                    if (visited[ny][nx] || !board[ny][nx])
                        continue;
                    qice.push({ny, nx});
                    tmpIce++;
                    visited[ny][nx] = true;
                }
            }
            maxIce = max(maxIce, tmpIce);
        }
    }
    cout << ice << "\n";
    cout << maxIce;
    return 0;
}