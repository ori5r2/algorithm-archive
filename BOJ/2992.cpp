#include <bits/stdc++.h>
using namespace std;

int N;
string str;
vector<int> num;

int permu()
{
    do
    {
        string s = "";
        for (int i = 0; i < num.size(); i++)
        {
            s += (num[i] + '0');
        }
        int x = stoi(s);

        if (x > N)
        {
            return x;
        }
    } while (next_permutation(num.begin(), num.end()));

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> str;
    N = stoi(str);
    for (int i = 0; i < str.size(); i++)
    {
        num.push_back(str[i] - '0');
    }

    cout << permu();

    return 0;
}