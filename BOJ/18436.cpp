#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, M, tmp;
int i, x, l, r, num;
int height = 1, leafStart = 1;
int iTree[1 << 18]; // max_height= 18

void update(int B, int C)
{
    int idx = leafStart - 1 + B;
    if (C % 2 == 0)
        iTree[idx] = 1;
    else
        iTree[idx] = 0;
    idx /= 2;
    while (idx > 0)
    {
        iTree[idx] = iTree[idx * 2] + iTree[idx * 2 + 1];
        idx /= 2;
    }
}

int query(int B, int C)
{
    int left = leafStart - 1 + B, right = leafStart - 1 + C;
    int ret = 0;

    while (left <= right)
    {
        if (left % 2 == 1)
            ret += iTree[left++];
        if (right % 2 == 0)
            ret += iTree[right--];
        left /= 2, right /= 2;
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    while (leafStart < N)
        height++, leafStart *= 2;

    for (int i = leafStart; i < leafStart + N; i++)
    {
        cin >> tmp;
        if (tmp % 2 == 0) // 짝수
            iTree[i] = 1;
    }
    for (int i = leafStart - 1; i > 0; i--)
        iTree[i] = iTree[i * 2] + iTree[i * 2 + 1];

    cin >> M;
    for (int tc = 0; tc < M; tc++)
    {
        cin >> num;
        if (num == 1) //
        {
            cin >> i >> x;
            update(i, x);
        }
        else if (num == 2) // 짝수 개수
        {
            cin >> l >> r;
            cout << query(l, r) << "\n";
        }
        else if (num == 3) // 홀수 개수
        {
            cin >> l >> r;
            cout << (r - l + 1) - query(l, r) << "\n";
        }
    }

    return 0;
}