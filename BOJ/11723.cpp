#include <bits/stdc++.h>
using namespace std;

int N, x;
string op;
set<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> op;

        if (op == "add")
        {
            cin >> x;
            s.insert(x);
        }
        else if (op == "remove")
        {
            cin >> x;
            s.erase(x);
        }
        else if (op == "check")
        {
            cin >> x;

            if (s.find(x) != s.end()) // found
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (op == "toggle")
        {
            cin >> x;
            if (s.find(x) != s.end())
                s.erase(x);
            else
                s.insert(x);
        }
        else if (op == "all")
        {
            for (int i = 1; i <= 20; i++)
                s.insert(i);
        }
        else if (op == "empty")
        {
            s.clear();
        }
    }

    return 0;
}