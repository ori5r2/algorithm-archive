#include <bits/stdc++.h>
using namespace std;
#define MX 12

int N, M, K, x, y, z, ans;
int A[MX][MX], board[MX][MX];
// vector<pair<int, bool>> trees[MX][MX];
vector<int> trees[MX][MX];
queue<pair<pair<int, int>, int>> delTree;
queue<pair<int, int>> newTree;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

void season()
{
    // spring
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int l = trees[i][j].size() - 1; l >= 0; l--)
            {
                // if (!trees[i][j][l].second) // 죽은거면
                //     continue;

                if (trees[i][j][l] <= board[i][j]) // 양분 먹음
                {
                    board[i][j] -= trees[i][j][l];
                    trees[i][j][l] += 1;
                    if (trees[i][j][l] % 5 == 0)
                        newTree.push({i, j});
                }
                else // 양분 못 먹음
                {
                    delTree.push({{i, j}, l});
                }
            }
        }
    }
    // summer
    while (!delTree.empty())
    {
        int ny = delTree.front().first.first, nx = delTree.front().first.second, idx = delTree.front().second;
        board[ny][nx] += (trees[ny][nx][idx] / 2);
        trees[ny][nx].erase(trees[ny][nx].begin() + idx);
        delTree.pop();
    }
    // fall
    while (!newTree.empty())
    {
        int y = newTree.front().first, x = newTree.front().second;
        newTree.pop();

        for (int d = 0; d < 8; d++)
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            trees[ny][nx].push_back(1);
        }
    }
    // winter
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)

            board[i][j] += A[i][j];
}

void calcTree()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans += trees[i][j].size();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            board[i][j] = 5;
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back(z);
    }

    for (int k = 0; k < K; k++)
    {
        season();
    }

    calcTree();
    cout << ans;

    return 0;
}