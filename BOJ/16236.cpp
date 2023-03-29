#include <bits/stdc++.h>
using namespace std;
#define MX 22

struct babyShrk
{
    pair<int, int> pos;
    int weight;
    int cnt;
};
babyShrk bs;

vector<pair<pair<int, int>, bool>> fishes[7];
int N, ans;
int board[MX][MX];
int dist[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void calcDist(void) // bs.pos 에서부터 (a, b까지 거리)
{
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({bs.pos.first, bs.pos.second});
    dist[bs.pos.first][bs.pos.second] = 1;

    while (!q.empty())
    {
        int Y = q.front().first, X = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int ny = Y + dy[d], nx = X + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (dist[ny][nx])
                continue;

            if (board[ny][nx] <= bs.weight)
            {
                q.push({ny, nx});
                dist[ny][nx] = dist[Y][X] + 1;
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
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                continue;
            else if (board[i][j] == 9)
            {
                bs.pos = {i, j};
                board[i][j] = 0;
                continue;
            }
            else
            {
                fishes[board[i][j]].push_back({{i, j}, true});
            }
        }
    }
    bs.cnt = 0, bs.weight = 2;

    while (1)
    {
        // 물고기 찾기
        calcDist();
        int minDist = INT_MAX;
        vector<pair<pair<int, int>, pair<int, int>>> v;
        for (int w = 1; w < bs.weight; w++)
        {
            if (w > 6)
                break;
            // weight = w 인 물고기 찾기
            for (int l = 0; l < fishes[w].size(); l++)
            {
                if (!fishes[w][l].second)
                    continue;
                int ny = fishes[w][l].first.first, nx = fishes[w][l].first.second;
                if (!dist[ny][nx]) // ⭐️ 갈 수 없는 곳은 제외!!
                    continue;
                if (dist[ny][nx] < minDist)
                {
                    if (!v.empty())
                        v.clear();
                    minDist = dist[ny][nx];
                    v.push_back({{ny, nx}, {w, l}});
                }
                else if (dist[ny][nx] == minDist)
                    v.push_back({{ny, nx}, {w, l}});
            }
        }

        if (!v.size())
            break;
        else
        {
            int ny = v[0].first.first, nx = v[0].first.second, wght = v[0].second.first, idx = v[0].second.second;
            if (v.size() > 1)
            {
                for (int t = 1; t < v.size(); t++)
                {
                    int yy = v[t].first.first, xx = v[t].first.second;
                    if (yy < ny)
                        ny = yy, nx = xx, wght = v[t].second.first, idx = v[t].second.second;
                    else if (yy == ny)
                    {
                        if (xx < nx)
                            ny = yy, nx = xx, wght = v[t].second.first, idx = v[t].second.second;
                    }
                }
            }
            board[ny][nx] = 0;
            ans += (dist[ny][nx] - 1);
            fishes[wght][idx].second = false;

            bs.cnt++;
            bs.pos = {ny, nx};
            if (bs.cnt == bs.weight)
            {
                bs.weight++;
                bs.cnt = 0;
            }
            // printBoard();
        }
    }
    cout << ans;

    return 0;
}