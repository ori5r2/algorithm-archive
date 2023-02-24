#include <bits/stdc++.h>
using namespace std;

int T, K, num;
char op;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> K;
        priority_queue<int> maxH1, maxH2;
        priority_queue<int, vector<int>, greater<int>> minH1, minH2;

        for (int k = 0; k < K; k++)
        {
            cin >> op;
            if (op == 'I')
            {
                cin >> num;
                maxH1.push(num), minH1.push(num);
            }
            else if (op == 'D')
            {
                cin >> num;
                if ((maxH1.size() - maxH2.size()) == 0)
                    continue;

                if (num == 1)
                {
                    while (!maxH2.empty())
                    {
                        int max1 = maxH1.top(), max2 = maxH2.top();
                        if (max1 == max2)
                            maxH1.pop(), maxH2.pop();
                        else
                            break;
                    }
                    minH2.push(maxH1.top());
                    maxH1.pop();
                }
                else if (num == -1)
                {
                    while (!minH2.empty())
                    {
                        int min1 = minH1.top(), min2 = minH2.top();
                        if (min1 == min2)
                            minH1.pop(), minH2.pop();
                        else
                            break;
                    }
                    maxH2.push(minH1.top());
                    minH1.pop();
                }
            }
        }
        if ((maxH1.size() - maxH2.size()) == 0)
            cout << "EMPTY\n";
        else
        {
            while (!maxH2.empty())
            {
                int max1 = maxH1.top(), max2 = maxH2.top();
                if (max1 == max2)
                    maxH1.pop(), maxH2.pop();
                else
                    break;
            }
            while (!minH2.empty())
            {
                int min1 = minH1.top(), min2 = minH2.top();
                if (min1 == min2)
                    minH1.pop(), minH2.pop();
                else
                    break;
            }
            cout << maxH1.top() << " " << minH1.top() << "\n";
        }
    }
    return 0;
}