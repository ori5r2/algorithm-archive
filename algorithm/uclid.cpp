#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B) // A >= B
{
    int r = A % B;
    if (r == 0)
        return B;
    else
        return gcd(B, r);
}