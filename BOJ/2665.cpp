#include <bits/stdc++.h>
using namespace std;
#define MX 52
#define INF 1987654321

string str;
int N, board[MX][MX], cost[MX][MX]; // cost[x][y] : xy까지 색 바꿔야하는 최소 수
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[j][i] << " ";
        cout << endl;
    }
}

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cost[j][i] = INF;
}

void BFS()
{
    init(); // 초기화
    queue<pair<int, int>> q;
    q.push({0, 0}), cost[0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        int nowCost = cost[x][y];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            if (board[nx][ny] == 1) // 흰방
            {
                if (cost[nx][ny] > nowCost)
                {
                    cost[nx][ny] = nowCost;
                    q.push({nx, ny});
                }
            }
            else // 검은방
            {
                if (cost[nx][ny] > nowCost + 1)
                {
                    cost[nx][ny] = nowCost + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < N; j++)
            board[j][i] = str[j] - '0';
    }

    BFS();
    cout << cost[N - 1][N - 1];
    return 0;
}