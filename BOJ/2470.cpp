#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, tmp;
vector<int> A, B; // A: 산성(양수), B: 알칼리성(음수)
int first, second, minVal = 2000000001;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (tmp < 0)
            B.push_back(tmp);
        else
            A.push_back(tmp);
    }

    sort(A.begin(), A.end()), sort(B.begin(), B.end());
    int lenA = A.size(), lenB = B.size();
    int idxA = lenA - 1, idxB = 0;

    while (1)
    {
        if (idxA < 0)
            break;
        if (idxB >= lenB)
            break;

        tmp = A[idxA] + B[idxB];
        if (abs(tmp) < minVal)
        {
            minVal = abs(tmp);
            first = B[idxB], second = A[idxA];
        }

        if (tmp < 0)
            idxB++;
        else if (tmp > 0)
            idxA--;
        else // tmp == 0
            break;
    }

    if (lenA >= 2)
    {
        tmp = A[0] + A[1];
        if (abs(tmp) < minVal)
        {
            minVal = abs(tmp);
            first = A[0], second = A[1];
        }
    }

    if (lenB >= 2)
    {
        tmp = B[lenB - 1] + B[lenB - 2];
        if (abs(tmp) < minVal)
        {
            minVal = abs(tmp);
            first = B[lenB - 2], second = B[lenB - 1];
        }
    }

    cout << first << " " << second;
    return 0;
}