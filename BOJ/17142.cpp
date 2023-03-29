#include <bits/stdc++.h>
using namespace std;
#define MX 52

int N, M, ans = -1;
int board[MX][MX];
int visited[MX][MX];
vector<pair<int, int>> virus;
int arr[11];
queue<pair<int, int>> q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void backTracking(int k)
{
    memset(visited, 0, sizeof(visited));
    if (k == M) // 시간 재기
    {
        for (int i = 0; i < M; i++) // 활성 바이러스
        {
            q.push({virus[arr[i]].first, virus[arr[i]].second});
            visited[virus[arr[i]].first][virus[arr[i]].second] = 1;
        }
        int maxT = 1;
        bool suc = true;
        while (!q.empty())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                    continue;

                // ⭐️ 활성 바이러스가 비활성 바이러스 있는 칸으로 가면 활성으로 변함
                if (board[ny][nx] == 1 || visited[ny][nx])
                    continue;

                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }

        // 모든 칸에 퍼졌는지 확인
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!board[i][j])
                {
                    if (!visited[i][j])
                        suc = false;
                    else
                        maxT = max(visited[i][j], maxT);
                }
            }
        }
        // printBoard();
        if (suc)
        {
            if (ans == -1)
                ans = maxT - 1;
            else
                ans = min(ans, maxT - 1); // ⭐️ 활성 바이러스가 비활성 바이러스 있는 칸으로 가면 활성으로 변함
        }
        return;
    }

    for (int i = 0; i < virus.size(); i++)
    {
        if (k > 0)
        {
            if (i <= arr[k - 1])
                continue;
        }
        arr[k] = i;
        backTracking(k + 1);
    }
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
            if (board[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    backTracking(0);
    cout << ans;
    return 0;
}