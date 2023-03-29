#include <bits/stdc++.h>
using namespace std;

double A, B;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    double x = A / B;
    cout << fixed;
    cout.precision(9);
    cout << x;

    return 0;
}