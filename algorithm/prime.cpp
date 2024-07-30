#include <bits/stdc++.h>
using namespace std;
#define MX 100

bool isNotPrime[MX];
vector<int> prime;

void checkPrime1(int N)
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (isNotPrime[j])
                continue;

            if (j % i == 0)
                isNotPrime[j] = true;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (!isNotPrime[i])
            prime.push_back(i);
    }
}

// 에라토스테네스의 체
void checkPrime2(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (!isNotPrime[i])
            prime.push_back(i);

        // i배수 다 지우기
        for (int j = i; j <= N; j += i)
        {
            if (isNotPrime[j])
                continue;
            isNotPrime[j] = true;
        }
    }
}
