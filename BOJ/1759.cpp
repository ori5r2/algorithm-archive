#include <bits/stdc++.h>
using namespace std;

int L, C;
char ch;
vector<char> v;
vector<string> s;

void comb(int n, int k)
{
    vector<int> tempV;
    for (int i = 0; i < k; i++)
        tempV.push_back(1);
    for (int i = k; i < n; i++)
        tempV.push_back(0);
    sort(tempV.begin(), tempV.end());

    do
    {
        string str;
        int cnt1 = 0, cnt2 = 0; // 자음 모음
        for (int i = 0; i < tempV.size(); i++)
        {
            if (tempV[i])
            {
                str += v[i];
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
                    cnt1++;
                else
                    cnt2++;
            }
        }

        // str 체크
        if (cnt1 >= 1 && cnt2 >= 2)
            s.push_back(str);
    } while (next_permutation(tempV.begin(), tempV.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> ch;
        v.push_back(ch);
    }
    sort(v.begin(), v.end());
    comb(C, L);

    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << "\n";

    return 0;
}