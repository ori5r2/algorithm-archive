#include <bits/stdc++.h>
using namespace std;

int cnt;
string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> str;

    int cont = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (cont)
        {
            cont--;
            continue;
        }

        string sub2 = str.substr(i, 2);
        if (sub2 == "c=" || sub2 == "c-" || sub2 == "d-" || sub2 == "lj" || sub2 == "nj" || sub2 == "s=" || sub2 == "z=")
            cont = 1;
        else if (str.substr(i, 3) == "dz=")
            cont = 2;

        cnt++;
    }

    cout << cnt;
    return 0;
}