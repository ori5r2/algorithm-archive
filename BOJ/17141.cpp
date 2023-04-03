#include <bits/stdc++.h>
using namespace std;
#define MX 50

int N, M, maxTime, minTime = -1;
int board[MX][MX];
int tmpBoard[MX][MX]; // -1: 벽, 0: 빈칸, 1: 바이러스
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!tmpBoard[i][j])
                return false;
            else
                maxTime = max(maxTime, tmpBoard[i][j]);
        }
    }
    return true;
}

void bfs()
{
    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        int t = tmpBoard[y][x];
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d], nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if (tmpBoard[ny][nx])
                continue;

            tmpBoard[ny][nx] = t + 1;
            q.push({ny, nx});
        }
    }
}

void comb()
{
    int n = virus.size();
    vector<int> tmpVec;
    for (int i = 0; i < M; i++)
        tmpVec.push_back(1);
    for (int i = M; i < n; i++)
        tmpVec.push_back(0);

    sort(tmpVec.begin(), tmpVec.end());

    do
    {
        // 초기화
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                tmpBoard[i][j] = board[i][j];
        maxTime = 0;

        for (int i = 0; i < tmpVec.size(); i++)
        {
            if (tmpVec[i])
            {
                int y = virus[i].first, x = virus[i].second;
                tmpBoard[y][x] = 1;
                q.push({y, x});
            }
        }
        bfs();
        if (check())
        {
            if (minTime == -1)
                minTime = maxTime - 1;
            else
                minTime = min(minTime, maxTime - 1);
        }
    } while (next_permutation(tmpVec.begin(), tmpVec.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                board[i][j] = -1;
            else if (board[i][j] == 2)
            {
                virus.push_back({i, j});
                board[i][j] = 0;
            }
        }
    }

    comb();
    cout << minTime;

    return 0;
}