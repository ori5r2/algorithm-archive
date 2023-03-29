#include <bits/stdc++.h>
using namespace std;
#define MX 52

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, T, tmp, x, d, k;
deque<int> board[MX];
bool visited[MX][MX];

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

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            board[i].push_back(tmp);
        }

    for (int t = 0; t < T; t++)
    {
        cin >> x >> d >> k;

        for (int i = 0; i < N; i++) // x배수인 원판 k칸 회전시킴
        {
            if ((i + 1) % x == 0)
            {
                if (d == 0) // 시계 방향
                {
                    for (int l = 0; l < k; l++)
                    {
                        board[i].push_front(board[i].back());
                        board[i].pop_back();
                    }
                }
                else // 반시계 방향
                {
                    for (int l = 0; l < k; l++)
                    {
                        board[i].push_back(board[i].front());
                        board[i].pop_front();
                    }
                }
            }
        }
        // printBoard();

        // 인접하면서 수가 같은 것을 찾음
        bool adj = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j])
                {
                    for (int l = 0; l < 4; l++)
                    {
                        int ny = i + dy[l], nx = j + dx[l];

                        if (ny < 0 || ny >= N)
                            continue;

                        if (nx < 0 || nx >= M)
                            nx %= M;
                        if (nx < 0)
                            nx += M;

                        if (board[ny][nx] == board[i][j])
                        {
                            adj = true;
                            visited[i][j] = true;
                            visited[ny][nx] = true;
                        }
                    }
                }
            }
        }

        if (!adj) // 인접한 게 없는 경우
        {
            int cnt = 0, totalSum = 0;
            queue<pair<int, int>> q;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (board[i][j])
                    {
                        totalSum += board[i][j];
                        cnt++;
                        q.push({i, j});
                    }
                }
            }

            if (cnt)
            {
                double avg = (double)totalSum / (double)cnt;

                while (!q.empty())
                {
                    int ny = q.front().first, nx = q.front().second;
                    if (board[ny][nx] < avg)
                        board[ny][nx] += 1;
                    else if (board[ny][nx] > avg)
                        board[ny][nx] -= 1;
                    q.pop();
                }
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (visited[i][j])
                    {
                        board[i][j] = 0;
                    }
                }
            }
            memset(visited, false, sizeof(visited));
        }
        // printBoard();
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans += board[i][j];

    cout << ans;
    return 0;
}