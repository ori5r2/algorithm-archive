#include <bits/stdc++.h>
using namespace std;
#define MX 1000005

int N, M, op, tmp1, tmp2;
int height = 1, leafStart = 1;
long long iTree[1 << 21]; // 합은 long long

void sumQuery(int a, int b) // a에서 b까지 합을 구하는 함수
{
    int l = leafStart - 1 + a;
    int r = leafStart - 1 + b;
    long long sum = 0;
    while (l <= r)
    {
        if (l % 2 == 1)
            sum += iTree[l++];
        if (r % 2 == 0)
            sum += iTree[r--];
        l /= 2, r /= 2;
    }
    cout << sum << "\n";
}

void modQuery(int a, int b) // a를 b로 바꾸는 함수
{
    int idx = leafStart - 1 + a;
    iTree[idx] = b, idx /= 2;
    while (idx > 0)
    {
        iTree[idx] = iTree[idx * 2] + iTree[idx * 2 + 1];
        idx /= 2;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); // ***주석처리***

    cin >> N >> M;
    while (leafStart < N)
        height++, leafStart *= 2;

    for (int i = 0; i < M; i++)
    {
        cin >> op >> tmp1 >> tmp2;
        if (op == 0) // sum
        {
            if (tmp1 > tmp2)
                sumQuery(tmp2, tmp1);
            else
                sumQuery(tmp1, tmp2);
        }
        else // modify
            modQuery(tmp1, tmp2);
    }

    return 0;
}