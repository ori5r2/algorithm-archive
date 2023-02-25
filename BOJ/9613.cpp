#include <bits/stdc++.h>
using namespace std;

int T, N, tmp;
long long ret; // ⭐️

int gcd(int A, int B)
{
    int r = A % B;
    if (r == 0)
        return B;
    else
        return gcd(B, r);
}

void comb(int n, int k, vector<int> vec)
{
    vector<int> tempV;
    for (int i = 0; i < k; i++)
        tempV.push_back(1);
    for (int i = k; i < n; i++)
        tempV.push_back(0);
    sort(tempV.begin(), tempV.end());

    do
    {
        vector<int> num;
        for (int i = 0; i < tempV.size(); i++)
        {
            if (tempV[i])
                num.push_back(vec[i]);
        }
        sort(num.begin(), num.end());
        ret += gcd(num[1], num[0]);

    } while (next_permutation(tempV.begin(), tempV.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;
        vector<int> v;
        ret = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        comb(N, 2, v);

        cout << ret << "\n";
    }

    return 0;
}