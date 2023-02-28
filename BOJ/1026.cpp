#include <bits/stdc++.h>
using namespace std;
#define MX 55

int N, S;
int A[MX], B[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A + N);
    sort(B, B + N, greater<int>());

    for (int i = 0; i < N; i++)
        S += A[i] * B[i];

    cout << S;

    return 0;
}