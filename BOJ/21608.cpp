#include <bits/stdc++.h>
using namespace std;
#define MX 25

int N, student;
int like_students[402][4];
int board[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int score[] = {0, 1, 10, 100, 1000};

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int checkStudents(int X, int Y, int num)
{
    int ret = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = X + dx[dir], ny = Y + dy[dir];
        int s = board[nx][ny];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        for (int l = 0; l < 4; l++)
        {
            if (like_students[num][l] == s)
                ret++;
        }
    }
    return ret;
}

int checkEmpty(int X, int Y)
{
    int ret = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = X + dx[dir], ny = Y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        if (!board[nx][ny])
            ret++;
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N * N; i++)
    {
        cin >> student;
        for (int j = 0; j < 4; j++)
            cin >> like_students[student][j];

        // 1. 비어있는 칸 중 좋아하는 학생이 가장 많은 칸으로 자리 정함
        vector<pair<int, int>> v;
        int maxVal = -1;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (board[x][y])
                    continue;

                int tmp = checkStudents(x, y, student);
                if (maxVal < tmp)
                {
                    maxVal = tmp;
                    v.clear(), v.push_back({x, y});
                }
                else if (maxVal == tmp)
                    v.push_back({x, y});
            }
        }

        if (v.size() == 1)
        {
            int x = v[0].first, y = v[0].second;
            board[x][y] = student;
            continue;
        }

        // 2. 1번 만족시키는 칸 중에서 비어있는 칸이 가장 많은 칸
        vector<pair<int, int>> v2;
        int maxVal2 = -1;
        for (int idx = 0; idx < v.size(); idx++)
        {
            int x = v[idx].first, y = v[idx].second;
            int tmp = checkEmpty(x, y);

            if (maxVal2 < tmp)
            {
                maxVal2 = tmp;
                v2.clear(), v2.push_back({x, y});
            }
            else if (maxVal2 == tmp)
                v2.push_back({x, y});
        }

        if (v2.size() == 1)
        {
            int x = v2[0].first, y = v2[0].second;
            board[x][y] = student;
            continue;
        }

        // 3. 2번 만족시키는 칸 중에서 행의 번호가 가장 작은 칸
        // 4. 3번 만족시키는 칸 중에서 열의 번호가 가장 작은 칸
        pair<int, int> p = {21, 21};
        for (int idx = 0; idx < v2.size(); idx++)
            p = min(v2[idx], p);

        int x = p.first, y = p.second;
        board[x][y] = student;
    }

    // 만족도 계산
    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            int tmp = checkStudents(x, y, board[x][y]);
            ans += score[tmp];
        }
    }
    cout << ans;

    return 0;
}