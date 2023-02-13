#include <bits/stdc++.h>
using namespace std;
#define MX 102

int T, N, x, y;
pair<int, int> house, festival;
pair<int, int> cv[MX];
bool ans = false;
bool visited[MX];

void BFS()
{
    queue<pair<int, int>> q;
    q.push(house);

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        int x = now.first, y = now.second;

        int toFest = abs(x - festival.first) + abs(y - festival.second);
        if (toFest <= 1000)
        {
            ans = true;
            break;
        }

        for (int i = 0; i < N; i++)
        {
            int nx = cv[i].first, ny = cv[i].second;

            if (visited[i])
                continue;

            int diff = abs(x - nx) + abs(y - ny);
            if (diff <= 1000)
            {
                visited[i] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        // 초기화
        memset(cv, 0, sizeof(cv));
        memset(visited, false, sizeof(visited));
        ans = false;

        cin >> N;
        cin >> x >> y;
        house = {x, y}; // 상근이네
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            cv[i] = {x, y}; // 편의점
        }
        cin >> x >> y;
        festival = {x, y}; // 락페

        BFS();
        if (ans == true)
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;
}