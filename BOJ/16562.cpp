#include <bits/stdc++.h>
using namespace std;
#define MX 10002

int N, M, K, A, B, tmp;
int parent[MX], friendCost[MX];

void init()
{
    for (int i = 0; i <= N; i++)
        parent[i] = i;
}

int findParent(int a)
{
    if (parent[a] == a)
        return a;

    int ret = findParent(parent[a]);
    parent[a] = ret;
    return ret;
}

bool merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return false;

    parent[b] = a;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> K;

    init();
    for (int i = 1; i <= N; i++)
        cin >> tmp, friendCost[i] = tmp;

    for (int i = 0; i < M; i++)
    { // 친구의 친구끼리 집합 만들어줌
        cin >> A >> B;
        merge(A, B);
    }

    int cost = 0;
    for (int i = 1; i <= N; i++) // 같은 집합끼리 가장 작은 비용으로 바꾸기
    {
        int p = findParent(i);
        int minVal = min(friendCost[i], friendCost[p]);
        friendCost[i] = minVal, friendCost[p] = minVal;
    }

    int sum = 0;
    for (int i = 1; i <= N; i++)
    { // root들의 비용 구하기
        if (parent[i] == i)
            sum += friendCost[i];
    }

    // 출력
    if (sum <= K)
        cout << sum;
    else
        cout << "Oh no";

    return 0;
}