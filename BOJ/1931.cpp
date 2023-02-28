#include <bits/stdc++.h>
using namespace std;
#define MX 100000

int N, startT, endT, cnt;
pair<int, int> info[MX]; // 끝나는 시간 & 시작 시간

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> startT >> endT;
        info[i] = {endT, startT};
    }

    sort(info, info + N);
    endT = info[0].first, startT = info[0].second;
    cnt++;

    for (int i = 1; i < N; i++)
    {
        int nowE = info[i].first, nowS = info[i].second;
        if (nowS < endT)
            continue;

        cnt++;
        endT = nowE, startT = nowS;
    }
    cout << cnt;

    return 0;
}