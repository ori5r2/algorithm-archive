// #2667. 단지번호 붙이기
// BFS : 시작점 여러개
#include <bits/stdc++.h>
using namespace std;
#define MX 27

int N;
string str;
int board[MX][MX];
bool visited[MX][MX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
priority_queue<int, vector<int>, greater<int>> pq;

void BFS()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cnt = 0;
            if (board[i][j] && !visited[i][j])
            {
                q.push({i, j}), cnt++;
                visited[i][j] = true;
            }
            else
                continue;

            while (!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d], ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (visited[nx][ny] || !board[nx][ny])
                        continue;

                    q.push({nx, ny}), cnt++;
                    visited[nx][ny] = true;
                }
            }

            pq.push(cnt);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < N; j++)
            board[i][j] = str[j] - '0';
    }

    BFS();

    cout << pq.size() << "\n";
    while (!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
    return 0;
}