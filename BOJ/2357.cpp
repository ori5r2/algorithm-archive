#include <bits/stdc++.h>
using namespace std;
#define MV 1000000001

int N, M, a, b, tmp;
int height, leafStart;
int minTree[1 << 18];
int maxTree[1 << 18]; // N:10000, height:18, leafStart:131072

void findMinMax(int A, int B)
{
    int minL = leafStart - 1 + A, minR = leafStart - 1 + B;
    int maxL = leafStart - 1 + A, maxR = leafStart - 1 + B;
    int minValue = MV, maxValue = 0;

    // min 찾기
    while (minL <= minR)
    {
        if (minL % 2 == 1)
            minValue = (minValue < minTree[minL]) ? minValue : minTree[minL], minL++;
        if (minR % 2 == 0)
            minValue = (minValue < minTree[minR]) ? minValue : minTree[minR], minR--;
        minL /= 2, minR /= 2;
    }

    // max 찾기
    while (maxL <= maxR)
    {
        if (maxL % 2 == 1)
            maxValue = (maxValue > maxTree[maxL]) ? maxValue : maxTree[maxL], maxL++;
        if (maxR % 2 == 0)
            maxValue = (maxValue > maxTree[maxR]) ? maxValue : maxTree[maxR], maxR--;
        maxL /= 2, maxR /= 2;
    }

    cout << minValue << " " << maxValue << "\n"; // 시간 초과나면 endl썼는지 확인!!
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // index tree 만들기
    memset(minTree, MV, sizeof(minTree));

    height = 1, leafStart = 1;
    while (leafStart < N)
    {
        height++, leafStart *= 2;
    }

    for (int i = leafStart; i < leafStart + N; i++)
    {
        cin >> tmp;
        maxTree[i] = tmp, minTree[i] = tmp;
    }

    // 부모노드 채우기
    for (int i = leafStart - 1; i > 0; i--)
    {
        minTree[i] = (minTree[i * 2] < minTree[i * 2 + 1]) ? minTree[i * 2] : minTree[i * 2 + 1];
        maxTree[i] = (maxTree[i * 2] > maxTree[i * 2 + 1] ? maxTree[i * 2] : maxTree[i * 2 + 1]);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        findMinMax(a, b);
    }

    return 0;
}