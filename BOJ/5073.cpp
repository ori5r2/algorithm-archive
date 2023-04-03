#include <bits/stdc++.h>
using namespace std;

int x, y, z;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    while (1)
    {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0)
            break;

        int cnt = 0;
        if ((x == y) && (y == z) && (x == z))
            cnt = 3;
        else if ((x == y) || (y == z) || (x == z))
            cnt = 2;

        int mx = max(x, y);
        mx = max(mx, z);

        if (mx < x + y + z - mx)
        {
            if (cnt == 3)
                cout << "Equilateral\n";
            else if (cnt == 2)
                cout << "Isosceles\n";
            else
                cout << "Scalene\n";
        }
        else
            cout << "Invalid\n";
    }

    return 0;
}