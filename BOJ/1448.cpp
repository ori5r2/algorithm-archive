#include <bits/stdc++.h>
using namespace std;

int N, tmp;
vector<int> straw;
int ans;

void comb(int n, int k)
{
    vector<int> tempVec;
    for (int i = 0; i < k; i++)
        tempVec.push_back(1);
    for (int i = k; i < n; i++)
        tempVec.push_back(0);
    sort(tempVec.begin(), tempVec.end());

    do
    {
        vector<int> tri;
        int sum = 0;
        int maxVal = 0;
        for (int i = 0; i < tempVec.size(); i++)
        {
            if (tempVec[i])
            {
                sum += straw[i];
                maxVal = max(maxVal, straw[i]);
            }
        }

        if (sum - maxVal > maxVal)
        {
            ans = sum;
            break;
        }

    } while (next_permutation(tempVec.begin(), tempVec.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        straw.push_back(tmp);
    }

    sort(straw.begin(), straw.end(), less<int>());

    comb(N, 3);
    if (ans == 0)
        cout << "-1";
    else
        cout << ans;

    return 0;
}