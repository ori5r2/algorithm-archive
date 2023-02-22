#include <bits/stdc++.h>
using namespace std;
#define MX 12

string k, crypt, k2;
int m[MX];
bool visited[MX];
vector<string> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> k >> crypt;
    k2 = "";
    for (int i = 0; i < k.size(); i++)
        k2 += k[i];

    int len = crypt.size() / k.size();

    sort(k.begin(), k.end());

    for (int i = 0; i < k2.size(); i++)
    {
        for (int j = 0; j < k.size(); j++)
        {
            if (!visited[j])
            {
                if (k2[i] == k[j])
                {
                    m[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < k2.size(); i++)
    {
        string tmp = "";
        for (int j = i * len; j < (i + 1) * len; j++)
        {
            tmp += crypt[j];
        }
        v.push_back(tmp);
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < k.size(); j++)
        {
            cout << v[m[j]][i];
        }
    }

    return 0;
}