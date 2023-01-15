#include <bits/stdc++.h>
using namespace std;
#define MX 305

int T, I, x, y, nx, ny;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int vis[MX][MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        // 초기화
        memset(vis, -1, sizeof(vis));
        queue<pair<int, int>> q;

        cin >> I;
        cin >> x >> y;
        cin >> nx >> ny;

        q.push({x, y}), vis[x][y] = 0;

        while (1)
        {
            int qx = q.front().first, qy = q.front().second, qd = vis[qx][qy];
            q.pop();

            if (nx == qx && ny == qy)
                break;

            for (int k = 0; k < 8; k++)
            {
                int X = qx + dx[k], Y = qy + dy[k], D = qd + 1;
                if (X < 0 || Y < 0 || X >= I || Y >= I)
                    continue;
                if (vis[X][Y] >= 0)
                    continue;

                // cout << X << " " << Y << " " << D << endl;
                vis[X][Y] = D, q.push({X, Y});
            }
        }

        cout << vis[nx][ny] << "\n";
    }

    return 0;
}
