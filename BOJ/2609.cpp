#include <bits/stdc++.h>
using namespace std;

int A, B;
int ans1, ans2;

int gcd(int a, int b) // a>b
{
    int r = a % b;
    if (r == 0)
        return b;
    else
        return gcd(b, r);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> A >> B;
    if (A >= B)
        ans1 = gcd(A, B);
    else
        ans1 = gcd(B, A);

    ans2 = (B / ans1) * (A / ans1) * ans1;
    cout << ans1 << "\n"
         << ans2;

    return 0;
}