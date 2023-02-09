#include <bits/stdc++.h>
using namespace std;
#define MX 1000002

int N, M;
int A[MX], B[MX];
int idxA = 0, idxB = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    while (1)
    {
        if (idxA == N && idxB == M)
            break;

        if (idxA == N)
        {
            while (idxB < M)
                cout << B[idxB++] << " ";

            continue;
        }

        if (idxB == M)
        {
            while (idxA < N)
                cout << A[idxA++] << " ";

            continue;
        }

        if (A[idxA] < B[idxB])
            cout << A[idxA++] << " ";
        else if (A[idxA] > B[idxB])
            cout << B[idxB++] << " ";
        else if (A[idxA] == B[idxB])
            cout << A[idxA++] << " " << B[idxB++] << " ";
    }

    return 0;
}