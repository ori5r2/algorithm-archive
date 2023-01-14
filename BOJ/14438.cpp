#include <bits/stdc++.h>
using namespace std;
#define MX 100005
#define INF 1000000001

int N, M, op, A, B;
int height = 1, leafStart = 1;
long long iTree[1 << 18];

void modify(int pos, int val)
{
    int idx = leafStart - 1 + pos;
    iTree[idx] = val, idx /= 2;
    while (idx > 0)
    {
        iTree[idx] = min(iTree[idx * 2], iTree[idx * 2 + 1]);
        idx /= 2;
    }
}

void findMin(int a, int b)
{
    int l = leafStart - 1 + a, r = leafStart - 1 + b;
    long long minV = INF;
    while (l <= r)
    {
        if (l % 2 == 1)
            minV = min(minV, iTree[l]), l++;
        if (r % 2 == 0)
            minV = min(minV, iTree[r]), r--;
        l /= 2, r /= 2;
    }
    cout << minV << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin); // ** 주석

    cin >> N;
    while (leafStart < N)
        height++, leafStart *= 2;
    memset(iTree, INF, sizeof(iTree));

    for (int i = leafStart; i < leafStart + N; i++)
        cin >> iTree[i];
    for (int i = leafStart - 1; i > 0; i--)
        iTree[i] = min(iTree[i * 2], iTree[i * 2 + 1]);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> op >> A >> B;
        if (op == 1)
            modify(A, B);
        else
            findMin(A, B);
    }

    return 0;
}