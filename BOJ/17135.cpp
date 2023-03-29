#include <bits/stdc++.h>
using namespace std;
#define MX 20

int N, M, D, val, ans;
int board[MX][MX];
int initBoard[MX][MX];
vector<pair<int, int>> attackers;

// 왼 위 오
int dx[] = {-1, 0, 1};
int dy[] = {0, -1, 0};

struct enemy
{
    pair<int, int> pos;
    int dist;
};

bool isEnd()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j])
                return false;
    return true;
}

void playGame()
{
    // 공격
    queue<pair<int, int>> dead;
    for (int i = 0; i < 3; i++)
    {
        bool suc = false;
        queue<enemy> q;
        q.push({attackers[i], 0});

        while (!q.empty())
        {
            if (suc)
                break;
            int y = q.front().pos.first, x = q.front().pos.second, dist = q.front().dist;
            q.pop();
            if (dist >= D)
                continue;

            for (int d = 0; d < 3; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;

                if (board[ny][nx] == 1)
                {
                    dead.push({ny, nx});
                    suc = true;
                    break;
                }
                else if (board[ny][nx] == 0)
                {
                    q.push({{ny, nx}, dist + 1});
                }
            }
        }
    }

    while (!dead.empty())
    {
        int y = dead.front().first, x = dead.front().second;
        if (board[y][x])
        {
            board[y][x] = 0;
            val++;
        }
        dead.pop();
    }
    // 이동
    for (int i = N - 2; i >= 0; i--)
    {
        vector<int> v;
        for (int j = 0; j < M; j++)
            v.push_back(board[i][j]);

        for (int j = 0; j < M; j++)
            board[i + 1][j] = v[j];
    }
    for (int j = 0; j < M; j++)
        board[0][j] = 0;

    if (isEnd())
        return;
    else
        playGame();
}

void comb()
{
    vector<int> tempV;
    for (int i = 0; i < 3; i++)
        tempV.push_back(1);
    for (int i = 3; i < M; i++)
        tempV.push_back(0);
    sort(tempV.begin(), tempV.end());

    do
    {
        attackers.clear();
        for (int i = 0; i < tempV.size(); i++)
        {
            if (tempV[i])
            {
                attackers.push_back({N, i});
            }
        }
        // 초기화
        val = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board[i][j] = initBoard[i][j];
        playGame();
        ans = max(ans, val);
    } while (next_permutation(tempV.begin(), tempV.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> initBoard[i][j];

    // M개 중 3개 자리 고르기
    comb();
    cout << ans;

    return 0;
}