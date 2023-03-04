#include <bits/stdc++.h>
using namespace std;

string str1, str2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> str1 >> str2;
    int diff = str2.size() - str1.size();
    int minVal = str1.size();
    for (int i = 0; i <= diff; i++)
    {
        int cnt = 0;
        for (int j = 0; j < str1.size(); j++)
        {
            if (str2[j + i] != str1[j])
                cnt++;
        }
        minVal = min(minVal, cnt);
    }
    cout << minVal;

    return 0;
}