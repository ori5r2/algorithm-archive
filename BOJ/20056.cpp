#include <bits/stdc++.h>
using namespace std;
#define MX 52

// 1과 N이 이어지는 부분에서 계속 오류 😭

// 반례 1 >> 17
// 5 3 5
// 4 4 10 7 1
// 1 4 5 2 0
// 3 2 2 10 6

// 반례 2 >> 33
// 4 9 5
// 3 2 8 5 2
// 3 3 19 3 4
// 3 1 7 1 1
// 4 4 6 4 0
// 2 1 6 2 5
// 4 3 9 4 3
// 2 2 16 1 2
// 4 2 17 5 3
// 3 4 3 5 7

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int N, M, K;
int r, c, m, s, d;
struct fireBall
{
    int mass;
    int speed;
    int dir;
};
struct tempBall
{
    pair<int, int> pos;
    fireBall fb;
};
queue<fireBall> board[MX][MX];

void mv() // 1. 파이어볼 이동
{
    queue<tempBall> q;
    for (int r = 0; r < N; r++) // r == y
    {
        for (int c = 0; c < N; c++) // c == x
        {
            while (!board[r][c].empty())
            {
                fireBall fb = board[r][c].front();
                int ny = r + dy[fb.dir] * fb.speed, nx = c + dx[fb.dir] * fb.speed;

                // ⭐️  1과 N번째 칸을 이어주는 부분
                if (ny < 0 || ny >= N)
                    ny = ny % N;

                if (ny < 0)
                    ny += N;

                if (nx < 0 || nx >= N)
                    nx = (nx % N);

                if (nx < 0)
                    nx += N;

                // cout << r << " " << c << " : " << ny << " " << nx << endl;
                q.push({{ny, nx}, fb});
                board[r][c].pop();
            }
        }
    }

    while (!q.empty())
    {
        tempBall tB = q.front();
        board[tB.pos.first][tB.pos.second].push(tB.fb);
        q.pop();
    }
}

void merge() // 2. 2개 이상 파이어볼 있는 칸에서 일어남
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            int cnt = board[r][c].size();
            if (cnt > 1)
            {
                int totalM = 0, totalS = 0;
                int isOdd = true, isEven = true;
                while (!board[r][c].empty())
                {
                    fireBall fb = board[r][c].front();
                    totalM += fb.mass, totalS += fb.speed;
                    if (fb.dir % 2 == 0) //
                        isOdd = false;
                    else
                        isEven = false;
                    board[r][c].pop();
                }

                if (totalM / 5 == 0)
                    continue;
                else
                {
                    if (isOdd || isEven)
                    {
                        for (int d : {0, 2, 4, 6})
                            board[r][c].push({totalM / 5, totalS / cnt, d});
                    }
                    else
                    {
                        for (int d : {1, 3, 5, 7})
                            board[r][c].push({totalM / 5, totalS / cnt, d});
                    }
                }
            }
        }
    }
}

int sum()
{
    int ans = 0;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            while (!board[r][c].empty())
            {
                // cout << r << " " << c << " " << board[r][c].front().mass << endl;
                ans += board[r][c].front().mass;
                board[r][c].pop();
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> m >> s >> d;
        board[r - 1][c - 1].push({m, s, d});
    }

    for (int i = 0; i < K; i++)
    {
        // cout << "num: " << i + 1 << endl;
        mv();
        merge();
    }

    cout << sum();

    return 0;
}