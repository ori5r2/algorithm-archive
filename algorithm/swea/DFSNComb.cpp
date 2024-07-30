// DFS + 조합 (중복 없음)
// N개 중 M개 골랐을 때 최소(최대) 구하기

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int arr[10];

void func()
{
}

void comb(int n) // nCm
{
    vector<int> tmpVec;
    for (int i = 0; i < M; i++)
        tmpVec.push_back(1);
    for (int i = M; i < n; i++)
        tmpVec.push_back(0);

    sort(tmpVec.begin(), tmpVec.end());

    do
    {
        for (int i = 0; i < tmpVec.size(); i++)
        {
            if (tmpVec[i])
            {
                // v[i];
            }
        }

        func();
    } while (next_permutation(tmpVec.begin(), tmpVec.end()));
}

void DFS(int k, int depth)
{
    if (k == M) // 종료 조건1: M개를 모두 선택했을 때
    {
        for (int i = 0; i < N; i++)
            cout << arr[i];

        func();
        return;
    }
    else if (depth == v.size()) // 종료 조건2: 벡터 마지막까지 탐색했을 떄
        return;

    if (1) // 조건 만족 시키면
    {
        arr[k] = v[k];
        DFS(k + 1, depth + 1);
    }
    else
    {
        DFS(k, depth + 1);
    }
}

// 문제
// https://www.acmicpc.net/problem/17142
// https://www.acmicpc.net/problem/15686
// https://www.acmicpc.net/problem/16987
