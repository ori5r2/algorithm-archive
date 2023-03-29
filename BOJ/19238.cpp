#include <bits/stdc++.h>
using namespace std;
#define MX 25

int N, M;
int a, b, c, d;
int board[MX][MX];
int visited[MX][MX];
// taxi
pair<int, int> taxi_pos;
int taxi_oil;

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

// passenger
struct passenger
{
    pair<int, int> start;
    pair<int, int> arrive;
};
passenger passengers[MX * MX];

bool isEnd()
{ // false: 승객이 남아 있음, true: 승객이 없음
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (board[i][j] > 1) // 승객이 남아 있음
                return false;
    return true;
}

void findP()
{
    // 초기화
    int y = taxi_pos.first, x = taxi_pos.second;
    int dist = -1, idx = -1;
    pair<int, int> pos = {-1, -1};
    memset(visited, 0, sizeof(visited));

    if (board[y][x] > 1)
    { // 택시와 승객이 같은 위치에 서 있으면 최단 거리=0
        dist = 0, idx = board[y][x];
        pos = {y, x};
    }
    else
    {
        queue<pair<int, int>> q;
        q.push({y, x});
        visited[y][x] = 1;

        while (!q.empty())
        {
            int Y = q.front().first, X = q.front().second;
            int D = visited[Y][X];
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = Y + dy[d], nx = X + dx[d];

                if (ny <= 0 || nx <= 0 || ny > N || nx > N)
                    continue;
                if (board[ny][nx] == 1 || visited[ny][nx])
                    continue;

                if (board[ny][nx] == 0)
                    visited[ny][nx] = D + 1, q.push({ny, nx});
                else if (board[ny][nx] > 1)
                {
                    visited[ny][nx] = D + 1, q.push({ny, nx});

                    if (dist == -1)
                    {
                        dist = visited[ny][nx] - 1, idx = board[ny][nx], pos = {ny, nx};
                        continue;
                    }
                    // ⭐️ 위 왼 오 아래 순서로 BFS X
                    // 반례: 왼왼왼 < 오오위

                    // 최단거리가 가장 짧은 승객
                    if (visited[ny][nx] - 1 < dist)
                    {
                        dist = visited[ny][nx] - 1, idx = board[ny][nx], pos = {ny, nx};
                    }
                    else if (visited[ny][nx] - 1 == dist)
                    {
                        // 행 번호가 가장 작은 승객
                        if (ny < pos.first)
                            dist = visited[ny][nx] - 1, idx = board[ny][nx], pos = {ny, nx};
                        else if (ny == pos.first)
                        {
                            // 열 번호가 가장 작은 승객
                            if (nx < pos.second)
                                dist = visited[ny][nx] - 1, idx = board[ny][nx], pos = {ny, nx};
                        }
                    }
                }
            }
        }
    }

    // 만약 승객을 태울 수 없으면
    if (dist == -1)
    {
        taxi_oil = -1;
        return;
    }

    // 승객을 태울 연료가 없으면
    if (taxi_oil - dist < 0)
    {
        taxi_oil = -1;
        return;
    }

    // 승객 태움
    taxi_oil -= dist;
    taxi_pos = pos;
    board[pos.first][pos.second] = 0;

    pair<int, int> dest = passengers[idx].arrive;
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.first][pos.second] = 1;

    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        int nowDist = visited[y][x];
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d], nx = x + dx[d];

            if (ny <= 0 || nx <= 0 || ny > N || nx > N)
                continue;
            if (board[ny][nx] == 1 || visited[ny][nx])
                continue;

            q.push({ny, nx});
            visited[ny][nx] = nowDist + 1;
        }
    }

    // 목적지까지 못간다면
    if (visited[dest.first][dest.second] <= 0)
    {
        taxi_oil = -1;
        return;
    }

    // 목적지까지 갈 수 있는 연료가 없으면
    if (visited[dest.first][dest.second] - 1 > taxi_oil)
    {
        taxi_oil = -1;
        return;
    }

    // 목적지까지 도달
    taxi_oil -= visited[dest.first][dest.second] - 1;
    taxi_oil += (visited[dest.first][dest.second] - 1) * 2;
    taxi_pos = dest;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> taxi_oil;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j]; // 0: 빈칸, 1: 벽
    // 운전을 시작하는 칸
    cin >> taxi_pos.first >> taxi_pos.second;
    // 승객 정보
    for (int i = 2; i < M + 2; i++)
    {
        // 출발지 행, 열 & 목적지 행, 열
        cin >> a >> b >> c >> d;
        passengers[i] = {{a, b}, {c, d}};
        board[a][b] = i; // 2~M+1: 승객
    }

    while (1)
    {
        // ⭐️ 승객이 있는지 확인
        if (isEnd()) // 승객이 없으면
            break;

        findP();

        if (taxi_oil == -1)
            break;
    }
    cout << taxi_oil;

    return 0;
}