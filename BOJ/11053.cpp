#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int A[MX];
int N;
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //  freopen("../input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), A[i]);
        if (it == v.end())
            v.push_back(A[i]);
        else
        {
            int idx = it - v.begin();
            v[idx] = A[i];
        }
    }

    cout << v.size();
    return 0;
}