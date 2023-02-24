#include <bits/stdc++.h>
using namespace std;
#define MX 100

bool isNotPrime[MX];

int main(void)
{

    for (int i = 2; i <= sqrt(MX); i++)
    {
        for (int j = i; j <= MX; j++)
        {
            if (isNotPrime[j])
                continue;

            if (j % i == 0)
                isNotPrime[j] = true;
        }
    }
}