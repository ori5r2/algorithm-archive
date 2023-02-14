#include <bits/stdc++.h>
using namespace std;
#define MX 102

int M, N, H;
int box[MX][MX][MX]; // H N M
int visited[MX][MX][MX];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

struct tomato
{
    int h, n, m;
};

bool checkAll()
{
    bool ret = true;
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (box[h][n][m] == 0 && visited[h][n][m] == 0)
                {
                    ret = false;
                } // 익지 않은 토마토가 visit하지 않았다면
            }
        }
    }
    return ret;
}

int BFS()
{
    queue<tomato> q;
    int maxVal = 0;

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (box[h][n][m] == 1) // 방문 안 한 토마토
                {
                    q.push({h, n, m});
                    visited[h][n][m] = 0;
                }
            }
        }
    }

    while (!q.empty())
    {
        tomato now = q.front();
        int days = visited[now.h][now.n][now.m];
        q.pop();

        maxVal = max(days, maxVal);

        for (int d = 0; d < 6; d++)
        {
            int nh = now.h + dh[d], nn = now.n + dx[d], nm = now.m + dy[d];

            if (nh < 0 || nn < 0 || nm < 0 || nh >= H || nn >= N || nm >= M)
                continue;

            if (visited[nh][nn][nm])
                continue;

            if (box[nh][nn][nm] == 0) // 익지 않은 토마토라면
            {
                visited[nh][nn][nm] = days + 1;
                q.push({nh, nn, nm});
            }
        }
    }

    return maxVal;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> M >> N >> H;
    for (int h = 0; h < H; h++)
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
                cin >> box[h][n][m];

    int ans = BFS();

    // 익지 못한 토마토가 있는지 확인
    if (checkAll())
        cout << ans;
    else
        cout << "-1";

    return 0;
}