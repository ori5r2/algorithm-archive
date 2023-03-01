#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
string str;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int cnt = 0;
    while (getline(cin, str)) // 한줄씩 입력 받기
    {
        m[str] += 1;
        cnt += 1;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << fixed;
        cout.precision(4);
        double ratio = ((double)it->second / (double)cnt) * 100;
        cout << it->first << " " << ratio << endl;
    }

    return 0;
}