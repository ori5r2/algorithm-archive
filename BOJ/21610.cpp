#include <bits/stdc++.h>
using namespace std;
#define MX 52

int N, M, d, s;
int A[MX][MX];
int cloud[MX][MX]; // 구름이 존재하는 위치
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

struct saveWater
{
    pair<int, int> pos;
    int water;
};

void printBoard(int b[MX][MX])
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
            cout << b[r][c] << " ";
        cout << endl;
    }
    cout << endl;
}

void cloudMV() // 모든 구름이 이동 + 구름있는 칸 물의 양 증가
{
    queue<pair<int, int>> removeCloud;
    queue<pair<int, int>> nowCloud;

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (cloud[r][c])
            {
                removeCloud.push({r, c});
                int ny = r + dy[d] * s, nx = c + dx[d] * s;

                // 1과 N번째 칸을 이어주는 부분
                if (ny < 0 || ny >= N)
                    ny = ny % N;
                if (ny < 0)
                    ny += N;

                if (nx < 0 || nx >= N)
                    nx = nx % N;
                if (nx < 0)
                    nx += N;

                nowCloud.push({ny, nx});
            }
        }
    }

    while (!removeCloud.empty())
    {
        int ny = removeCloud.front().first, nx = removeCloud.front().second;
        cloud[ny][nx] = 0;
        removeCloud.pop();
    }

    while (!nowCloud.empty())
    {
        int ny = nowCloud.front().first, nx = nowCloud.front().second;
        cloud[ny][nx] = 1;
        A[ny][nx] += 1;
        nowCloud.pop();
    }
}

void magic()
{
    queue<saveWater> q;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (cloud[r][c])
            {
                int cnt = 0;
                for (int dir : {2, 4, 6, 8}) // 대각선 확인
                {
                    int ny = r + dy[dir], nx = c + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                        continue;

                    if (A[ny][nx] > 0)
                        cnt++;
                }
                q.push({{r, c}, cnt});
            }
        }
    }

    while (!q.empty())
    {
        saveWater SW = q.front();
        A[SW.pos.first][SW.pos.second] += SW.water;
        q.pop();
    }
}

void cloudRM()
{
    queue<pair<int, int>> nowCloud;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (A[r][c] >= 2 && !cloud[r][c])
            {
                nowCloud.push({r, c});
            }
        }
    }

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (cloud[r][c])
                cloud[r][c] = 0;
        }
    }

    while (!nowCloud.empty())
    {
        int ny = nowCloud.front().first, nx = nowCloud.front().second;
        A[ny][nx] -= 2;
        cloud[ny][nx] = 1;
        nowCloud.pop();
    }
}

int cloudCnt()
{
    int ans = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            ans += A[r][c];

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> A[r][c];

    // 초기 구름 위치
    cloud[N - 1][0] = 1, cloud[N - 1][1] = 1, cloud[N - 2][0] = 1, cloud[N - 2][1] = 1;

    for (int i = 0; i < M; i++)
    {
        cin >> d >> s;
        cloudMV();
        magic();
        cloudRM();
    }

    cout << cloudCnt();
    return 0;
}