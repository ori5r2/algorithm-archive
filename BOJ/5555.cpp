#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int N, cnt;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> str1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str2;
        bool suc = false;
        for (int j = 0; j < str2.size(); j++)
        {
            for (int k = 0; k < str1.size(); k++)
            {
                int idx = (j + k) % str2.size();
                if (str2[idx] != str1[k])
                    break;
                else
                {
                    if (k == str1.size() - 1)
                        suc = true;
                }
            }
        }
        if (suc)
            cnt++;
    }
    cout << cnt;

    return 0;
}