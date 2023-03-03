#include <bits/stdc++.h>
using namespace std;

int N, M;
string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
map<string, int> m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    priority_queue<string, vector<string>, greater<string>> pq;
    for (int i = N; i <= M; i++)
    {
        string str = to_string(i);
        string str2 = "";
        for (int j = 0; j < str.size(); j++)
        {
            str2 += num[str[j] - '0'] + " ";
        }
        pq.push(str2);
        m.insert({str2, i});
    }

    int idx = 0;
    while (!pq.empty())
    {
        cout << m[pq.top()] << " ";
        idx++;
        if (idx % 10 == 0)
            cout << "\n";
        pq.pop();
    }

    return 0;
}