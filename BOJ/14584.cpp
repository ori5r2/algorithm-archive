#include <bits/stdc++.h>
using namespace std;
#define MX 22

int N;
// char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // 26개
string s1, tmp;
string arr[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> s1;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    bool suc = false;
    for (int i = 0; i < 26; i++)
    {
        tmp = "";
        for (int j = 0; j < s1.size(); j++)
        {
            char idx = ((s1[j] - 'a') + i) % 26 + 'a';
            tmp += idx;
            // tmp += alpha[idx];
        }
        // cout << tmp << endl;

        for (int j = 0; j < N; j++)
        {
            if (tmp.find(arr[j]) != tmp.npos)
            {
                cout << tmp;
                suc = true;
            }
            if (suc)
                break;
        }
        if (suc)
            break;
    }

    return 0;
}