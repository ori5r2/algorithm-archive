#include <bits/stdc++.h>
using namespace std;
#define MX 100002
#define INF 1987654321

priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
int N, K;
int dist[MX];

void dijk()
{
    for (int i = 0; i < MX; i++)
        dist[i] = INF;
    pq.push(N);
    dist[N] = 0;

    while (!pq.empty())
    {
        int nowVertex = pq.top();
        int nowCost = dist[nowVertex];
        pq.pop();

        int arr[] = {nowVertex * 2, nowVertex + 1, nowVertex - 1};
        for (int i = 0; i < 3; i++)
        {
            int nextVertex = arr[i];
            if (nextVertex < 0 || nextVertex >= MX)
                continue;
            int nextCost;

            if (i == 0)
                nextCost = nowCost;
            else
                nextCost = nowCost + 1;

            if (dist[nextVertex] > nextCost)
            {
                // cout << nextVertex << endl;
                dist[nextVertex] = nextCost;
                pq.push(nextVertex);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    dijk();
    cout << dist[K];

    return 0;
}