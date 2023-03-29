#include <bits/stdc++.h>
using namespace std;
#define MX 55

// fstream fout;

int N, M, K;
int r, c, s, ans = -1;
int board[MX][MX];
int tmpBoard[MX][MX];
pair<pair<int, int>, int> op[6];
queue<int> q;
int arr[6];
bool visited[6];

// 오 아 왼 위
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// void printBoard()
// {
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= M; j++)
//             fout << board[i][j] << " ";
//         fout << endl;
//     }
//     fout << endl;
// }

void init()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            tmpBoard[i][j] = board[i][j];
}

void calc()
{
    int minVal = -1;
    for (int i = 1; i <= N; i++)
    {
        int val = 0;
        for (int j = 1; j <= M; j++)
            val += tmpBoard[i][j];

        if (minVal == -1)
            minVal = val;
        else
            minVal = min(minVal, val);
    }

    if (ans == -1)
        ans = minVal;
    else
        ans = min(ans, minVal);
}

void rotate(int R, int C, int S)
{
    for (int i = S; i > 0; i--)
    {
        // 줍기
        int y = R - i, x = C - i;
        for (int d : {0, 1, 2, 3})
        {
            for (int j = 0; j < 2 * i; j++)
            {
                q.push(tmpBoard[y][x]);
                y = y + dy[d], x = x + dx[d];
            }
        }

        // 넣기
        for (int d : {0, 1, 2, 3})
        {
            for (int j = 0; j < 2 * i; j++)
            {
                y = y + dy[d], x = x + dx[d];
                tmpBoard[y][x] = q.front();
                q.pop();
            }
        }
    }
}

void backTracking(int k)
{
    if (k == K)
    { // 연산 수행
        init();
        for (int i = 0; i < K; i++)
        {
            int num = arr[i];
            r = op[num].first.first, c = op[num].first.second, s = op[num].second;
            rotate(r, c, s);
        }
        calc();
    }

    for (int i = 0; i < K; i++)
    {
        if (!visited[i])
        {
            arr[k] = i;
            visited[i] = true;
            backTracking(k + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    for (int i = 0; i < K; i++)
    {
        cin >> r >> c >> s;
        op[i] = {{r, c}, s};
    }

    backTracking(0);
    cout << ans;

    // fout.close();
    return 0;
}