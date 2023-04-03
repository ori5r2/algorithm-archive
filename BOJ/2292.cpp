#include <bits/stdc++.h>
using namespace std;
int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int roomCnt = 1;
    for (int i = 1; N > 1; i++)
    {
        N -= i * 6;
        roomCnt++;
    }
    // int cnt = 0;
    // for (int i = 2; i <= N; i++)
    // {
    //     if (cnt == 6 * (roomCnt - 1))
    //         roomCnt++, cnt = 1;
    //     else
    //         cnt++;
    // }

    cout << roomCnt;
    return 0;
}