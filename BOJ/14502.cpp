#include <bits/stdc++.h>
using namespace std;

int N, M, maxVal;
int board[12][12];
bool visited[12][12];
vector<pair<int, int>> space;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int calcSafe()
{
    int ret = 0;
    memset(visited, false, sizeof(visited));

    for (int t = 0; t < virus.size(); t++) // 바이러스 터트리기
    {
        q.push({virus[t].first, virus[t].second});

        while (!q.empty())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;
                if (board[ny][nx] != 0 || visited[ny][nx])
                    continue;

                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    // 안전 구역 정하기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 && visited[i][j] == false)
                ret++;
        }
    }
    return ret;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void comb()
{
    vector<int> tmpVec;
    for (int i = 0; i < 3; i++)
        tmpVec.push_back(1);
    for (int i = 3; i < space.size(); i++)
        tmpVec.push_back(0);
    sort(tmpVec.begin(), tmpVec.end());

    do
    {
        vector<pair<int, int>> wall;
        for (int i = 0; i < tmpVec.size(); i++)
        {
            if (tmpVec[i] == 1)
                wall.push_back({space[i].first, space[i].second});
        }
        // 벽 세우기
        for (int i = 0; i < wall.size(); i++)
        {
            board[wall[i].first][wall[i].second] = 1;
        }

        // 안전영역 크기 구하기
        int val = calcSafe();
        maxVal = max(maxVal, val);
        // 벽 없애기
        for (int i = 0; i < wall.size(); i++)
            board[wall[i].first][wall[i].second] = 0;

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
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                space.push_back({i, j});
            else if (board[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    sort(space.begin(), space.end());
    comb();
    cout << maxVal;
    return 0;
}