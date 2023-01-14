#include <bits/stdc++.h>
using namespace std;
#define RM 1000000007

int N, M, K; // N: 수의 개수(<=1000000),  M: 수의 변경이 일어나는 횟수, K: 구간의 곱을 구하는 횟수
int a, b, c;
long long ans, height = 1, leafStart = 1;
long long iTree[1 << 21]; // H: 21 // 애매하면 무조건 long long

void printTree()
{
    for (int i = 1; i < 2 * leafStart; i++)
        cout << i << " " << iTree[i] << endl;
}

void update(int B, int C) // B를 C로 바꿈
{
    int idx = leafStart - 1 + B;
    iTree[idx] = C, idx /= 2;
    while (idx > 0)
    {
        long long tmp = (iTree[idx * 2] * iTree[idx * 2 + 1]) % RM;
        iTree[idx] = tmp;
        idx /= 2;
    }
}

void mulQuery(int B, int C) // B~C구간 곱
{
    int l, r;
    if (B <= C)
        l = leafStart - 1 + B, r = leafStart - 1 + C;
    else
        l = leafStart - 1 + C, r = leafStart - 1 + B;

    long long ret = 1;
    while (l <= r)
    {
        if (l % 2 == 1)
            ret = ((ret % RM) * (iTree[l++] % RM)) % RM;
        if (r % 2 == 0)
            ret = ((ret % RM) * iTree[r--] % RM) % RM;
        l /= 2, r /= 2;
    }
    cout << ret << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for (int i = 0; i < 2 * leafStart; i++)
        iTree[i] = 1; // 배열 초기화

    while (N > leafStart)
        height++, leafStart *= 2;
    for (int i = leafStart; i < leafStart + N; i++)
        cin >> iTree[i];

    for (int i = leafStart - 1; i > 0; i--)
    {
        long long tmp = ((iTree[i * 2] % RM) * (iTree[i * 2 + 1] % RM)) % RM;
        iTree[i] = tmp;
    }
    // printTree();
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c);
        else
            mulQuery(b, c);
    }

    return 0;
}