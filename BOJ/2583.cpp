// #2583. 영역 구하기
// BFS

#include <bits/stdc++.h>
using namespace std;
#define MX 102

int M, N, K, X1, X2, Y1, Y2; // input
int board[MX][MX];
bool visited[MX][MX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int cnt, tmp;
priority_queue<int, vector<int>, greater<int>> pq;

void printBoard(int b[MX][MX])
{
    for (int i = M - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS()
{
    queue<pair<int, int>> q;
    for (int i = M - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false && board[i][j] == 0)
            {
                q.push({i, j}); // y x
                visited[i][j] = true, cnt++, tmp = 1;
            }
            else
                continue;

            while (!q.empty())
            {
                int y = q.front().first, x = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = y + dy[dir], nx = x + dx[dir];

                    if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                        continue;
                    if (visited[ny][nx] || board[ny][nx])
                        continue;

                    // cout << x << " " << y << " " << nx << " " << ny << endl;
                    q.push({ny, nx}), tmp++;
                    visited[ny][nx] = true;
                }
            }

            pq.push(tmp);
            // cout << i << " " << j << " " << tmp << endl;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2; // (X1, Y1): 왼쪽 아래 & (X2, Y2): 오른쪽 위
        for (int x = X1; x < X2; x++)
        {
            for (int y = Y1; y < Y2; y++)
            {
                board[y][x] = 1; // 1: 직사각형 있는 곳
            }
        }
    }

    BFS();

    cout << cnt << "\n";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}