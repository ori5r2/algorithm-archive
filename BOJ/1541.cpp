#include <bits/stdc++.h>
using namespace std;

string str;
deque<int> num;
deque<char> op;

void func(int x)
{
    if (op.empty())
    {
        num.push_back(x);
    }
    else
    {
        char ch = op.back();
        if (ch == '-')
        {
            num.push_back(x);
        }
        else
        {
            op.pop_back();
            int y = num.back();
            num.pop_back();
            num.push_back(x + y);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> str;
    string s = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            // s
            int x = stoi(s);
            func(x);
            //
            s = "";
            op.push_back(str[i]);
        }
        else
        {
            s += str[i];
        }
    }
    func(stoi(s));

    int ans = num[0];
    if (!op.empty())
    {
        for (int i = 1; i < num.size(); i++)
        {
            ans -= num[i];
        }
    }
    cout << ans;

    return 0;
}