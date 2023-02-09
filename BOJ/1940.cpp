#include <bits/stdc++.h>
using namespace std;
#define MX 15002

int N, M;
int material[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> material[i];

    sort(material, material + N);
    int front = 0, back = N - 1, cnt = 0;

    while (front < back)
    {
        int sum = material[front] + material[back];

        if (sum < M)
            front++;
        else if (sum > M)
            back--;
        else if (sum == M)
            cnt++, back--;
    }

    cout << cnt;
    return 0;
}