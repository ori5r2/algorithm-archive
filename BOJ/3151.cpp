#include <bits/stdc++.h>
using namespace std;
#define MX 10002

typedef long long ll;
int N;
int A[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);
    ll ans = 0; // ⭐️ overflow 조심

    // for (int i = 0; i < N; i++)
    //     cout << A[i] << " ";
    // cout << endl;

    // int ans2 = 0;
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = i + 1; j < N; j++)
    //     {
    //         for (int k = j + 1; k < N; k++)
    //         {
    //             int tmp = A[i] + A[j] + A[k];
    //             // cout << A[i] << " " << A[j] << " " << A[k] << " " << tmp << endl;
    //             if (tmp == 0)
    //             {
    //                 // cout << A[i] << " " << A[j] << " " << A[k] << endl;
    //                 ans2++;
    //             }
    //         }
    //     }
    // }
    // cout << ans2 << endl;

    for (int i = 0; i <= N - 3; i++)
    {
        int a = A[i];
        int idx1 = i + 1;
        int idx2 = N - 1;

        while (idx1 < idx2)
        {
            int tmp = a + A[idx1] + A[idx2];
            if (tmp > 0)
                idx2--;
            else if (tmp < 0)
                idx1++;
            else if (tmp == 0)
            {
                if (A[idx1] != A[idx2])
                {
                    // 중복 확인
                    ll cnt1 = 1, cnt2 = 1;
                    int X1 = A[idx1], X2 = A[idx2];
                    bool check1 = false, check2 = false;
                    while (1)
                    {
                        if (check1 == true && check2 == true)
                            break;

                        if (check1 == false)
                            idx1++;
                        if (check2 == false)
                            idx2--;

                        if (idx1 > idx2)
                            break;

                        if (X1 == A[idx1])
                            cnt1++;
                        else
                            check1 = true;

                        if (X2 == A[idx2])
                            cnt2++;
                        else
                            check2 = true;
                    }
                    // cout << a << " " << X1 << ": " << cnt1 << " & " << X2 << ": " << cnt2 << endl;
                    ans += (cnt1 * cnt2);
                }
                else // ⭐️ 반례:  0 0 0 0
                {
                    ll cnt = 2;
                    int X = A[idx1];
                    while (1)
                    {
                        idx1++, idx2--;

                        if (idx1 > idx2)
                            break;
                        else if (idx1 == idx2)
                        {
                            cnt += 1;
                            break;
                        }
                        else if (idx1 < idx2)
                            cnt += 2;
                    }

                    int c = (cnt) * (cnt - 1) / 2;
                    ans += c;
                }
            }
        }
    }

    cout << ans;

    return 0;
}