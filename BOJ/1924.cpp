#include <bits/stdc++.h>
using namespace std;

string ans[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int x, y;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    int days = y;
    for (int i = 1; i < x; i++)
        days += month[i];

    cout << ans[days % 7];

    return 0;
}