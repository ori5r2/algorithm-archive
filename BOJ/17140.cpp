#include <bits/stdc++.h>
using namespace std;
#define MX 100

int r, c, k, R, C, t;
int A[MX][MX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void printBoard()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    R = 3, C = 3;

    while (t <= 100)
    {
        if (A[r - 1][c - 1] == k)
        {
            cout << t;
            break;
        }
        else if (t == 100)
        {
            cout << -1;
            break;
        }

        if (R >= C) // R연산
        {
            int maxVal = 0;
            for (int i = 0; i < R; i++)
            {
                map<int, int> m;
                int cnt = 0;
                for (int j = 0; j < C; j++)
                {
                    int a = A[i][j];
                    if (a == 0)
                        continue;

                    if (!m[a])
                        cnt++;
                    m[a]++;
                }
                maxVal = max(maxVal, cnt * 2);

                int idx = 0;
                for (auto it = m.begin(); it != m.end(); it++)
                    pq.push({it->second, it->first});

                // 정렬한 결과 넣기
                while (!pq.empty())
                {
                    if (idx == 100)
                        break;

                    A[i][idx++] = pq.top().second;
                    A[i][idx++] = pq.top().first;
                    pq.pop();
                }
                while (idx < C)
                {
                    if (idx == 100)
                        break;
                    A[i][idx++] = 0;
                }
            }

            C = min(maxVal, 100);
        }
        else // C연산
        {
            int maxVal = 0;
            for (int j = 0; j < C; j++)
            {
                map<int, int> m;
                int cnt = 0;

                // 정렬
                for (int i = 0; i < R; i++)
                {
                    int a = A[i][j];
                    if (a == 0)
                        continue;

                    if (!m[a])
                        cnt++;
                    m[a]++;
                }
                maxVal = max(maxVal, cnt * 2);

                int idx = 0;
                for (auto it = m.begin(); it != m.end(); it++)
                    pq.push({it->second, it->first});

                while (!pq.empty())
                {
                    if (idx == 100)
                        break;

                    A[idx++][j] = pq.top().second;
                    A[idx++][j] = pq.top().first;
                    pq.pop();
                }

                while (idx < C)
                {
                    if (idx == 100)
                        break;

                    A[idx++][j] = 0;
                }
            }
            R = min(maxVal, 100);
        }

        // printBoard();
        t++;
    }

    return 0;
}