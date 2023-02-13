#include <bits/stdc++.h>
using namespace std;
#define MX 15

vector<int> v;
int A[MX];
int N, a, b, c, d;
int INFP = 1e9;
int INFM = -1 * 1e9;
int minVal = INFP, maxVal = INFM;

void perm()
{
    do
    {
        int ret = A[0];
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
                ret += A[i + 1];
            else if (v[i] == 2)
                ret -= A[i + 1];
            else if (v[i] == 3)
                ret *= A[i + 1];
            else if (v[i] == 4)
                ret /= A[i + 1];
        }
        minVal = min(ret, minVal);
        maxVal = max(ret, maxVal);
    } while (next_permutation(v.begin(), v.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> a >> b >> c >> d;
    for (int i = 0; i < a; i++)
        v.push_back(1);
    for (int i = 0; i < b; i++)
        v.push_back(2);
    for (int i = 0; i < c; i++)
        v.push_back(3);
    for (int i = 0; i < d; i++)
        v.push_back(4);

    sort(v.begin(), v.end());

    perm();
    cout << maxVal << "\n";
    cout << minVal << "\n";

    return 0;
}