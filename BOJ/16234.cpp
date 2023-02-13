#include <bits/stdc++.h>
using namespace std;
#define MX 52

struct unit
{
    int cities = 0;
    int population = 0;
    vector<pair<int, int>> v;
};

int N, L, R;
int board[MX][MX];
bool visited[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool BFS()
{
    memset(visited, false, sizeof(visited));
    vector<unit> unit_vector;
    bool check;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            queue<pair<int, int>> q;
            unit u;
            if (!visited[i][j])
            {
                q.push({i, j});
                visited[i][j] = true;
                u.cities++, u.population += board[i][j], u.v.push_back({i, j});
            }

            while (!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                int p = board[x][y];
                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    int np = board[nx][ny];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (visited[nx][ny])
                        continue;

                    int diff = abs(p - np);
                    if (diff >= L && diff <= R)
                    {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        u.cities++, u.population += board[nx][ny], u.v.push_back({nx, ny});
                    }
                }
            }

            if (u.cities > 1)
                unit_vector.push_back(u);
        }
    }

    if (unit_vector.empty())
        check = false;
    else
    {
        check = true;
        for (int i = 0; i < unit_vector.size(); i++)
        {
            unit u = unit_vector[i];
            int unit_p = u.population / u.cities;
            for (int j = 0; j < u.v.size(); j++)
            {
                int x = u.v[j].first, y = u.v[j].second;
                board[x][y] = unit_p;
            }
        }
    }

    return check;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int day = 0;
    while (BFS())
    {
        day++;
    }

    cout << day;
    return 0;
}