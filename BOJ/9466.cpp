#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int T, N, tmp;
int visited[MX];
int student[MX];
// 시간초과 반례 > 사이클 생기면 무한루프
// Input)              Output) 3 1 2
// 3
// 5
// 2 3 4 5 4
// 4
// 2 3 4 2
// 3
// 2 3 3
void BFS()
{
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            int start = i, next = student[i];
            visited[i] = 2;
            int suc = 0;

            while (1)
            {
                if (start == next)
                { // 사이클
                    suc = 1;
                    break;
                }

                if (visited[next] == 1)
                {
                    suc = -1;
                    break;
                }
                else if (visited[next] == 2)
                {
                    suc = 2;
                    break;
                }
                else if (visited[next] == -1)
                {
                    suc = -1;
                    break;
                }
                else if (visited[next] == 0)
                {
                    visited[next] = 2;
                    next = student[next];
                }
            }

            //
            if (suc == 1)
            {
                visited[next] = 1;
                next = student[next];

                while (next != start)
                {
                    visited[next] = 1;
                    next = student[next];
                }
            }
            else if (suc == 2)
            {
                int tmp = next;
                visited[next] = 1;
                next = student[next];
                while (next != tmp)
                {
                    visited[next] = 1;
                    next = student[next];
                }

                next = student[start];
                visited[start] = -1;
                while (next != tmp)
                {
                    visited[next] = -1;
                    next = student[next];
                }
            }
            else if (suc == -1)
            {
                visited[start] = -1;
                next = student[start];
                while (visited[next] == 2)
                {
                    visited[next] = -1;
                    next = student[next];
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        memset(visited, 0, sizeof(visited));
        memset(student, 0, sizeof(student));
        int ans = 0;

        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> tmp;
            student[i] = tmp;
            if (tmp == i)
                visited[i] = 1;
        }

        BFS();
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == -1)
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}