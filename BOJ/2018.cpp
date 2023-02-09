#include <bits/stdc++.h>
using namespace std;

int N, sum = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int front = 1, back = 2, cnt = 1;
    sum = 1;

    while (back < N)
    {
        if (sum < N)
            sum += back++;
        else if (sum > N)
            sum -= front++;

        if (sum == N)
            cnt++, sum += back++;
    }

    cout << cnt;
    return 0;
}