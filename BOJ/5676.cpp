#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, K, tmp, a, b;
char op;
int height = 1, leafStart = 1;
int iTree[1 << 18]; // max_height=18
string p;

void update(int A, int B)
{
    int idx = leafStart - 1 + A;
    if (B > 0)
        iTree[idx] = 1;
    else if (B == 0)
        iTree[idx] = 0;
    else if (B < 0)
        iTree[idx] = -1;
    idx /= 2;

    while (idx > 0)
    {
        iTree[idx] = iTree[idx * 2] * iTree[idx * 2 + 1];
        idx /= 2;
    }
}

void query(int A, int B)
{
    int l = leafStart - 1 + A, r = leafStart - 1 + B;
    int ret = 1;

    while (l <= r)
    {
        if (l % 2 == 1)
            ret *= iTree[l++];
        if (r % 2 == 0)
            ret *= iTree[r--];
        l /= 2, r /= 2;
    }

    if (ret > 0)
        p += "+";
    else if (ret == 0)
        p += "0";
    else if (ret < 0)
        p += "-";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    while (cin >> N >> K) // ⭐️ 무한 입력 ⭐️
    {
        // 초기화
        p = "";
        memset(iTree, 1, sizeof(iTree));
        leafStart = 1, height = 1;
        while (leafStart < N)
            height++, leafStart *= 2;

        // 입력
        for (int i = leafStart; i < leafStart + N; i++)
        {
            cin >> tmp;
            if (tmp > 0)
                iTree[i] = 1;
            else if (tmp < 0)
                iTree[i] = -1;
            else if (tmp == 0)
                iTree[i] = 0;
        }

        // 트리 채우기
        for (int i = leafStart - 1; i > 0; i--)
            iTree[i] = iTree[i * 2] * iTree[i * 2 + 1];

        for (int tc = 0; tc < K; tc++)
        {
            cin >> op;
            if (op == 'C') // 변경 명령
            {
                cin >> a >> b;
                update(a, b);
            }
            else // 곱셈 명령
            {
                cin >> a >> b;
                query(a, b);
            }
        }
        cout << p << "\n";
    }

    return 0;
}