#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> s;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += s[i] - '0';
    }
    cout << sum;
    return 0;
}