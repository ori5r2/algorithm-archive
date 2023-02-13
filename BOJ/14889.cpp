#include <bits/stdc++.h>
using namespace std;
#define MX 22
#define INF 1987654321
int board[MX][MX];
int N;
vector<int> v;
int ans = INF;

int comb2(int n, int k, vector<int> tmp)
{
    vector<int> tempV;
    int ret = 0;
    for (int i = 0; i < n - k; i++)
        tempV.push_back(0);
    for (int i = n - k; i < n; i++)
        tempV.push_back(1);

    do
    {
        vector<int> s;
        for (int i = 0; i < tempV.size(); i++)
        {
            if (tempV[i] == 1)
                s.push_back(tmp[i]);
        }

        ret += board[s[0]][s[1]] + board[s[1]][s[0]];

    } while (next_permutation(tempV.begin(), tempV.end()));

    return ret;
}

void comb(int n, int k)
{
    vector<int> tempV;
    for (int i = 0; i < n - k; i++)
        tempV.push_back(0);
    for (int i = n - k; i < n; i++)
        tempV.push_back(1);

    do
    {
        int sum1 = 0, sum2 = 0;
        vector<int> tmp1, tmp2;
        for (int i = 0; i < tempV.size(); i++)
        {
            if (tempV[i] == 1)
                tmp1.push_back(v[i]);
            else
                tmp2.push_back(v[i]);
        }

        sort(tmp1.begin(), tmp1.end()), sort(tmp2.begin(), tmp2.begin());

        sum1 = comb2(k, 2, tmp1);
        sum2 = comb2(k, 2, tmp2);
        ans = min(ans, abs(sum1 - sum2));

    } while (next_permutation(tempV.begin(), tempV.end()));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }

    for (int i = 1; i <= N; i++)
        v.push_back(i);
    sort(v.begin(), v.end());

    comb(N, N / 2);

    cout << ans;
    return 0;
}