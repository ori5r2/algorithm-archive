#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, tmp, ans = 0;
int isNotPrime[MX];

void checkPrime()
{
    isNotPrime[1] = true, isNotPrime[0] = true;
    for (int i = 2; i <= sqrt(1000); i++)
    {
        for (int j = i + 1; j <= 1000; j++)
        {
            if (isNotPrime[j])
                continue;
            if (j % i == 0)
                isNotPrime[j] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //     freopen("input.txt", "r", stdin);
    cin >> N;
    checkPrime();

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (!isNotPrime[tmp])
            ans++;
    }

    cout << ans;

    return 0;
}