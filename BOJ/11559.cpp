#include <bits/stdc++.h>
using namespace std;

string s;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
deque<char> dq[6];

void printBoard()
{
    for (int m = 0; m < 6; m++)
    {
        for (int n = 0; n < 12; n++)
            cout << dq[m][n] << " ";
        cout << endl;
    }
}

bool playGame()
{
    char ch;
    queue<pair<int, int>> q;
    bool visited_tmp[6][12], visited_true[6][12];
    int visited[6];
    memset(visited, 0, sizeof(visited));
    memset(visited_true, 0, sizeof(visited_true));

    bool endGame = true;

    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 12; i++)
        {
            int cnt = 0;
            memset(visited_tmp, false, sizeof(visited_tmp));

            if (dq[j][i] != '.' && !visited_true[j][i])
            {
                ch = dq[j][i];
                q.push({j, i}), visited_tmp[j][i] = true, cnt = 1;
            }

            while (!q.empty())
            {
                int y = q.front().first, x = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (ny < 0 || ny >= 6 || nx < 0 || nx >= 12)
                        continue;
                    if (visited_tmp[ny][nx])
                        continue;
                    if (dq[ny][nx] == ch)
                    {
                        q.push({ny, nx}), visited_tmp[ny][nx] = true, cnt++;
                    }
                }
            }

            // 4개 이상 같은 색이면
            if (cnt >= 4)
            {
                endGame = false;
                for (int m = 0; m < 6; m++)
                {
                    int a = 0;
                    for (int n = 0; n < 12; n++)
                    {
                        if (visited_tmp[m][n])
                        {
                            a++;
                            visited_true[m][n] = true;
                        }
                    }
                    visited[m] = a;
                }
            }
        }
    }

    for (int j = 0; j < 6; j++)
    {
        for (int i = 11; i >= 0; i--)
        {
            if (visited_true[j][i])
            {
                dq[j].pop_back();
            }
            else
            {
                dq[j].push_front(dq[j].back());
                dq[j].pop_back();
            }
        }

        for (int k = 0; k < visited[j]; k++)
        {
            dq[j].push_front('.');
        }
    }

    return endGame;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);

    for (int i = 0; i < 12; i++)
    {
        cin >> s;
        for (int j = 0; j < 6; j++)
        {
            dq[j].push_back(s[j]);
        }
    }

    int ans = 0;

    bool isEnd = false;
    while (!isEnd)
    {

        isEnd = playGame();
        ans++;
    }

    cout << ans - 1;

    return 0;
}