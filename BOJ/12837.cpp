#include <bits/stdc++.h>
using namespace std;
#define MX 1000002

int N, Q, num, p, x, q;
int height = 1, leafStart = 1;
long long iTree[1 << 21]; // height: 21

void update(int B, int C)
{
    int idx = leafStart - 1 + B;
    iTree[idx] += C, idx /= 2;
    while (idx > 0)
    {
        iTree[idx] = iTree[idx * 2] + iTree[idx * 2 + 1];
        idx /= 2;
    }
}

void query(int B, int C)
{
    int l = leafStart - 1 + B, r = leafStart - 1 + C;
    long long ret = 0;
    while (l <= r)
    {
        if (l % 2 == 1)
            ret += iTree[l++];
        if (r % 2 == 0)
            ret += iTree[r--];
        l /= 2, r /= 2;
    }
    cout << ret << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> Q;
    while (leafStart < N)
        height++, leafStart *= 2;

    for (int i = 0; i < Q; i++)
    {
        cin >> num;
        if (num == 1)
        {
            cin >> p >> x;
            update(p, x); // 변경이 아니라 추가!!
        }
        else
        {
            cin >> p >> q;
            query(p, q);
        }
    }

    return 0;
}