#include <bits/stdc++.h>
using namespace std;
#define MX 250002

int N, X;
int visited[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> X;
    for (int i = 0; i < N; i++)
        cin >> visited[i];

    int front = 0, back = X, maxVal = 0, cnt = 0;

    int tmp = 0;
    for (int i = front; i < back; i++)
        tmp += visited[i];

    if (tmp > 0)
        maxVal = tmp, cnt = 1;

    for (int i = X - 1; i < N; i++)
    {
        int frontVal = visited[front++], backVal = visited[back++];
        tmp = tmp + backVal - frontVal;

        if (tmp > maxVal)
            cnt = 1, maxVal = tmp;
        else if (tmp == maxVal)
            cnt++;
    }

    // 정답 출력
    if (maxVal == 0)
        cout << "SAD";
    else
        cout << maxVal << "\n"
             << cnt;

    return 0;
}