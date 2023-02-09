#include <bits/stdc++.h>
using namespace std;
#define MX 100002
#define NMX 200002

int N, K;
int cnts[MX], A[NMX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int front = 0, back = 0, maxLen = 0;
    while (back < N)
    {
        int now = A[back];
        int cnt = cnts[now];

        if (cnt < K)
        {
            cnts[now]++;
            maxLen = max(maxLen, back - front + 1);
            back++;
        }
        else
        {
            int frontVal = A[front++];
            cnts[frontVal]--;
        }
    }

    cout << maxLen;

    return 0;
}