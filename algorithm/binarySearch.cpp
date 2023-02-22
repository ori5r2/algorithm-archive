#include <bits/stdc++.h>
using namespace std;
#define MX 100

int N, M, ans;
int low, mid, high;
int tree[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int low = 0, high = *max_element(tree, tree + N);

    while (low < high)
    {
        mid = (high + low) / 2;
        int length = tree[mid];

        if (length == M)
        {
            ans = mid;
            break;
        }
        else if (length > M)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid;
    }

    return 0;
}