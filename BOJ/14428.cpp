#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, M, tmp;
int num, i, v, j;
int INF = 1e9 + 1;
int height = 1, leafStart = 1;
pair<int, int> iTree[1 << 18]; // max_height=18 / pair<val, idx>

void update(int B, int C)
{
    int idx = leafStart - 1 + B;
    iTree[idx] = {C, B};
    idx /= 2;

    while (idx > 0)
    {
        iTree[idx] = min(iTree[idx * 2], iTree[idx * 2 + 1]);
        idx /= 2;
    }
}

void query(int B, int C)
{
    int l = leafStart - 1 + B, r = leafStart - 1 + C;
    pair<int, int> p = {INF, 0};

    while (l <= r)
    {
        if (l % 2 == 1)
            p = min(iTree[l++], p);
        if (r % 2 == 0)
            p = min(iTree[r--], p);
        l /= 2, r /= 2;
    }
    cout << p.second << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    while (leafStart < N)
        height++, leafStart *= 2;

    // 초기화
    int idx = 0;
    for (int i = 1; i < leafStart * 2; i++)
        iTree[i] = {INF, idx};

    idx++;
    for (int i = leafStart; i < leafStart + N; i++)
    {
        cin >> tmp;
        iTree[i] = {tmp, idx++};
    }

    // 인덱스 트리 채우기
    for (int i = leafStart - 1; i > 0; i--)
        iTree[i] = min(iTree[i * 2], iTree[i * 2 + 1]);

    cin >> M;
    for (int tc = 0; tc < M; tc++)
    {
        cin >> num;
        if (num == 1)
        {
            cin >> i >> v;
            update(i, v);
        }
        else
        {
            cin >> i >> j;
            query(i, j);
        }
    }
    return 0;
}