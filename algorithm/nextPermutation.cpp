#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void permu()
{
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }

        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

void comb(int n, int k) // nCk
{
    vector<int> tempVector;

    for (int i = 0; i < n - k; i++)
        tempVector.push_back(0);

    for (int i = n - k; i < n; i++)
        tempVector.push_back(1);

    // sort(tempVector.begin(), tempVector.end());
    do
    {
        for (int i = 0; i < tempVector.size(); i++)
        {
            if (tempVector[i] == 1)
            { // 실제값 출력
                cout << v[i] << " ";
            }
        }
        cout << endl;

    } while (next_permutation(tempVector.begin(), tempVector.end()));
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        v.push_back(i + 1); // 1, 2, 3, 4
    }

    // sort(v.begin(), v.end());

    // permu();
    comb(4, 2);

    return 0;
}
