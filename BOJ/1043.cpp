#include <bits/stdc++.h>
using namespace std;
#define MX 52

int N, M, truthCnt, ans = 0;
int K, tmp;
int parent[MX];
bool truth[MX];
vector<int> party[MX];
vector<int> truer;

void init()
{
    for (int i = 0; i <= N; i++)
        parent[i] = i;
}

int findParent(int A)
{
    if (A == parent[A])
        return A;

    int ret = findParent(parent[A]);
    parent[A] = ret;
    return ret;
}

bool merge(int A, int B)
{
    A = findParent(A);
    B = findParent(B);

    if (A == B)
        return false;

    parent[B] = A;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> truthCnt;
    for (int i = 0; i < truthCnt; i++)
    {
        cin >> tmp;
        truth[tmp] = true;
        truer.push_back(tmp);
    }
    init();

    for (int i = 0; i < M; i++)
    {
        cin >> K;
        int p = 0;
        for (int j = 0; j < K; j++)
        {
            cin >> tmp;
            party[i].push_back(tmp);
            if (j == 0)
                p = tmp;
            else
                merge(p, tmp);
        }
    }

    // for (int i = 1; i <= N; i++)
    //     cout << parent[i] << " ";
    // cout << endl;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < truthCnt; j++)
        {
            int p1 = findParent(truer[j]);
            int p2 = findParent(i);

            if (p1 == p2)
                truth[i] = true;
        }
    }

    // for (int i = 1; i <= N; i++)
    //     cout << truth[i] << " ";
    // cout << endl;

    for (int i = 0; i < M; i++)
    {
        bool check = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (truth[party[i][j]])
            {
                check = false;
            }
        }
        if (check)
            ans++;
    }
    cout << ans;

    return 0;
}