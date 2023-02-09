#include <bits/stdc++.h>
using namespace std;
#define MX 1000000001

int N;
int height = 1, leafStart = 1;
int iTree[1 << 21]; // height: 21

void printTree()
{
    for (int i = 1; i < 2 * leafStart; i++)
        cout << i << " " << iTree[i] << endl;
}

void update(int B, int C) // B번쨰를 C로 바꿈
{
    int idx = leafStart - 1 + B;
    iTree[idx] = C, idx /= 2;
    while (idx > 0)
    {
        iTree[idx] = iTree[idx * 2] + iTree[idx * 2 + 1];
        idx /= 2;
    }
}

void query(int B, int C) // B부터 C구간 사이 합 구하기
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
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> N;
    while (leafStart < N)
        height++, leafStart *= 2;

    for (int i = leafStart; i < leafStart + N; i++)
        cin >> iTree[i];

    // 2. 인덱스 트리 채우기
    for (int i = leafStart - 1; i > 0; i--)
        iTree[i] = iTree[i * 2] + iTree[i * 2 + 1];

    return 0;
}