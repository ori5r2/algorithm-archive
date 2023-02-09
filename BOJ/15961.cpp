#include <bits/stdc++.h>
using namespace std;
#define MX 3000002
#define MX2 3002

int N, d, k, c;
int A[MX], susi[MX2]; // A: 벨트 위 초밥 & susi: 스시 가짓수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    // 초기화
    for (int i = 0; i < k; i++)
        susi[A[i]]++;
    susi[c]++;

    int cnt = 0;
    for (int i = 1; i <= d; i++)
    {
        if (susi[i])
            cnt++;
    }
    // cout << cnt;

    int maxCnt = cnt;
    int front = 0, back = k;
    for (int i = 1; i < N; i++)
    {

        if (back == N)
            back = 0;

        int frontVal = A[front++], backVal = A[back++];

        if (susi[backVal] == 0)
            cnt++;
        susi[frontVal]--, susi[backVal]++;
        if (susi[frontVal] == 0)
            cnt--;

        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt;
    return 0;
}