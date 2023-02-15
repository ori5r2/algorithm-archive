#include <bits/stdc++.h>
using namespace std;
#define MX 102

typedef unsigned long long ull;
// ⭐️ ull 보다 큰 값은 문자열로 해결

int N, M;
string dp[MX][MX];

string add(string num1, string num2)
{
    string ret = "";
    int sum = 0;
    int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
    int size = max(num1.size(), num2.size());

    int i = 0;
    while (1)
    {
        if (sum == 0 && size <= i)
            break;

        if (idx1 >= i)
            sum += num1[idx1 - i] - '0';

        if (idx2 >= i)
            sum += num2[idx2 - i] - '0';

        string num = "";
        num += sum % 10 + '0';
        ret = num + ret;
        sum /= 10;

        i++;
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = "1", dp[i][i] = "1";
        for (int j = 1; j < i; j++)
            dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
    }

    // cout << dp[97][17] << endl;
    // cout << dp[97][18] << endl;
    // cout << dp[98][18] << endl;
    // cout << dp[N][M];

    cout << dp[N][M];
    return 0;
}