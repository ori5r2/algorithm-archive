#include <bits/stdc++.h>
using namespace std;
#define MX 205

int N, M, tmp;
int parent[MX];
int path[1002];

void init()
{
    for (int i = 1; i <= N; i++)
        parent[i] = i;
}

int findParent(int a)
{
    if (parent[a] == a)
        return a;

    int ret = findParent(parent[a]);
    parent[a] = ret;
    return ret;
}

bool merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return false;

    parent[b] = a;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //

    cin >> N >> M;

    init();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                merge(i, j);
            }
        }
    }

    for (int i = 0; i < M; i++)
        cin >> path[i];

    for (int i = 0; i < M - 1; i++)
    {
        int a = findParent(path[i]);
        int b = findParent(path[i + 1]);

        if (a != b)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}