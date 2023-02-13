#include <bits/stdc++.h>
using namespace std;
#define MX 302

int N, M, height;
int board[MX][MX];
bool visited[MX][MX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int calc()
{
    memset(visited, false, sizeof(visited));
    int ret = 0;
    queue<pair<int, int>> calcQ;
    // ⭐️ 시간 초과 ⭐️
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            // ⭐️ 시간 초과 ⭐️
            // 여기서 계속 새로운 큐를 만들어주면 시간 많이 걸림
            if (board[n][m] > 0 && visited[n][m] == false)
            {
                ret++;
                visited[n][m] = true;
                calcQ.push({n, m});
            }

            while (!calcQ.empty())
            {
                int nowN = calcQ.front().first, nowM = calcQ.front().second;
                calcQ.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nextN = nowN + dx[d], nextM = nowM + dy[d];

                    if (nextN < 0 || nextM < 0 || nextN >= N || nextM >= M)
                        continue;

                    if (visited[nextN][nextM] || !board[nextN][nextM])
                        continue;

                    visited[nextN][nextM] = true;
                    calcQ.push({nextN, nextM});
                }
            }
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    queue<pair<int, int>> q;
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cin >> height;
            board[n][m] = height;
            if (height > 0)
                q.push({n, m});
        }
    }

    int year = 0, ans = 0;
    while (1)
    {
        int area = calc();
        if (area >= 2)
        {
            ans = year;
            break;
        }
        else if (area == 0)
        {
            ans = 0;
            break;
        }

        // 빙산 녹이기
        vector<pair<int, int>> melt;
        int len = q.size();

        for (int i = 0; i < len; i++)
        {
            int nowN = q.front().first, nowM = q.front().second;
            q.pop();
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int nextN = nowN + dx[d], nextM = nowM + dy[d];
                if (nextN < 0 || nextM < 0 || nextN >= N || nextM >= M)
                    continue;
                if (board[nextN][nextM] == 0)
                    cnt++;
            }

            if (cnt >= board[nowN][nowM])
                melt.push_back({nowN, nowM});
            else
            {
                board[nowN][nowM] -= cnt;
                q.push({nowN, nowM});
            }
        }

        for (int i = 0; i < melt.size(); i++)
        {
            int nowN = melt[i].first, nowM = melt[i].second;
            board[nowN][nowM] = 0;
        }

        year++;
    }

    cout << ans;
    return 0;
}