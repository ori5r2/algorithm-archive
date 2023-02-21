#include <bits/stdc++.h>
using namespace std;
#define MX 101

bool board[MX][MX]; // y x
int N;
int X, Y, D, G;
map<int, int> m; // 직선
map<int, int> r; // 90도 회전

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int dx2[] = {0, 0, 1, 1};
int dy2[] = {0, 1, 0, 1};

void dragonCurve()
{
    vector<int> v;      // 직선
    pair<int, int> pos; // end position

    int y = Y + dy[D], x = X + dx[D];
    v.push_back(m[D]);
    board[y][x] = 1;
    pos = {y, x};

    for (int g = 1; g <= G; g++)
    {
        int len = v.size();
        for (int k = len - 1; k >= 0; k--)
        {
            int y = pos.first, x = pos.second, d = v[k];
            int ny = y + dy[r[d]], nx = x + dx[r[d]], nd = m[r[d]];

            // cout << x << " " << y << " " << nx << " " << ny << endl;
            if (ny >= 0 && ny <= 100 && nx >= 0 && nx <= 100)
                board[ny][nx] = 1;

            pos = {ny, nx};
            v.push_back(nd);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    m.insert({3, 1}), m.insert({1, 3}), m.insert({0, 2}), m.insert({2, 0});
    r.insert({3, 2}), r.insert({2, 1}), r.insert({1, 0}), r.insert({0, 3});

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> X >> Y >> D >> G;
        board[Y][X] = 1;
        dragonCurve();
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            bool check = true;
            for (int d = 0; d < 4; d++)
            {
                int ny = i + dy2[d], nx = j + dx2[d];
                if (!board[ny][nx])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                cnt++;
        }
    }
    cout << cnt;

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //         cout << board[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}