#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
bool fst = true;
ll ans;
string str;
vector<char> op;
vector<ll> num;
int arr[20];
bool visited[20];

void backTraking(int k, int K)
{
    if (k == K)
    { // 연산
        //  괄호 먼저 계산
        vector<ll> n;
        vector<char> p;
        bool pass = false;
        for (int i = 0; i < num.size(); i++)
        {
            if (visited[i])
            {
                ll x = num[i], y = num[i + 1];
                pass = true;
                if (op[i] == '+')
                    n.push_back(x + y);
                else if (op[i] == '-')
                    n.push_back(x - y);
                else if (op[i] == '*')
                    n.push_back(x * y);
            }
            else
            {
                if (pass)
                    pass = false;
                else
                    n.push_back(num[i]);

                if (i != num.size() - 1)
                    p.push_back(op[i]);
            }
        }

        ll val = n[0];
        for (int i = 0; i < p.size(); i++)
        {
            ll tmp = n[i + 1];
            if (p[i] == '+')
                val += tmp;
            else if (p[i] == '-')
                val -= tmp;
            else if (p[i] == '*')
                val *= tmp;
        }

        if (fst) // ⭐️ 음수가 처음에 나올수 있음ㅠㅠ
        {
            ans = val;
            fst = false;
        }
        else
            ans = max(val, ans);
        return;
    }

    for (int i = 0; i < op.size(); i++)
    {
        if (k >= 1 && arr[k - 1] + 1 >= i)
            continue;

        if (!visited[i])
        {
            arr[k] = i;
            visited[i] = true;
            backTraking(k + 1, K);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    cin >> str;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            op.push_back(str[i]);
        else
            num.push_back(str[i] - '0');
    }

    for (int t = 0; t <= (op.size() / 2); t++)
        backTraking(0, t);

    cout << ans;

    return 0;
}