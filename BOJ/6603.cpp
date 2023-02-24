#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int K, tmp;
bool visited[14];
int arr[6];

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
        vector<int> ans;
        for (int i = 0; i < tempVec.size(); i++)
        {
            if (tempVec[i])
                ans.push_back(v[i]);
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    } while (next_permutation(tempVec.begin(), tempVec.end()));
}

void backTrack(int k)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int j = 0; j < K; j++)
    {
        if (!visited[j] && arr[k - 1] <= v[j])
        {
            arr[k] = v[j];
            visited[j] = true;
            backTrack(k + 1);
            visited[j] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    while (1)
    {
        cin >> K;
        if (K == 0)
            break;

        v.clear();
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < K; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }

        // sort(v.begin(), v.end(), greater<int>());
        // comb(K, 6);
        backTrack(0);

        cout << "\n";
    }

    return 0;
}