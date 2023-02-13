#include <bits/stdc++.h>
using namespace std;
#define MX 1000002

int N;
double A[MX];
double B, C;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> B >> C;

    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] <= B)
        {
            sum += 1;
            continue;
        }

        long long tmp = 1 + ceil((A[i] - B) / C);
        sum += tmp;
    }
    cout << sum;

    return 0;
}