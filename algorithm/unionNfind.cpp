#include <bits/stdc++.h>
using namespace std;
#define MX 100

int N;          // 집합 개수
int parent[MX]; // 부모 노드

void init()
{
    for (int i = 0; i <= N; i++)
        parent[i] = i; // 처음에는 자기 자신이 루트
}

int findParent(int a)
{
    if (parent[a] = a)
        return a;

    int ret = findParent(parent[a]);
    parent[a] = ret; // 부모 찾으면서 갱신
    return ret;
}

bool merge(int a, int b) // union
{
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return false; // 같은 트리(집합)에 있음

    parent[b] = a; // 부모를 같게 함
    return true;
}
