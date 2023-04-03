#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> egg[10]; // 내구도, 무게
pair<int, int> tmpEgg[10];
int arr[10];

void backTraking(int k)
{
    if (k == N)
    {
        // 초기화
        for (int i = 0; i < N; i++)
            tmpEgg[i] = egg[i];

        for (int i = 0; i < N; i++)
        {
            int eggIdx = arr[i];
            if (tmpEgg[i].first <= 0 || tmpEgg[eggIdx].first <= 0)
                continue;

            tmpEgg[i].first -= tmpEgg[eggIdx].second;
            tmpEgg[eggIdx].first -= tmpEgg[i].second;
        }

        int val = 0;
        for (int i = 0; i < N; i++)
            if (tmpEgg[i].first <= 0)
                val++;
        ans = max(val, ans);

        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (k == i)
            continue;

        arr[k] = i;
        backTraking(k + 1);
    }
}

void dfs(int k) // 시간 줄이기!
{
    // 종료 조건
    if (k == N)
    {
        int val = 0;
        for (int i = 0; i < N; i++)
            if (egg[i].first <= 0)
                val++;

        ans = max(val, ans);
        return;
    }

    if (egg[k].first <= 0)
        dfs(k + 1);
    else
    {
        bool flag = false;
        for (int i = 0; i < N; i++)
        {
            if (i == k)
                continue;
            if (egg[i].first <= 0)
                continue;

            egg[k].first -= egg[i].second;
            egg[i].first -= egg[k].second;
            flag = true;
            dfs(k + 1);

            // 되돌리기
            egg[k].first += egg[i].second;
            egg[i].first += egg[k].second;
        }
        if (!flag)
            dfs(k + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> egg[i].first >> egg[i].second;

    // backTraking(0);
    dfs(0);

    cout << ans;
    return 0;
}