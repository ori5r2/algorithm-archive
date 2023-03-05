#include <bits/stdc++.h>
using namespace std;

int N;
string str, str2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    while (1)
    {
        cin >> N;
        if (N == 0)
            break;

        priority_queue<pair<string, string>, vector<pair<string, string>>, greater<pair<string, string>>> pq;
        for (int i = 0; i < N; i++)
        {
            cin >> str;
            str2 = str;
            transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
            pq.push({str2, str});
        }
        cout << pq.top().second << "\n";
    }

    return 0;
}