#include <bits/stdc++.h>
using namespace std;

// unsigned long long 보다 큰 정수를 저장할때 사용

string add(string num1, string num2)
{
    string ret = "";
    int sum = 0;
    int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
    int size = max(num1.size(), num2.size());

    int i = 0;
    while (1)
    {
        if (sum == 0 && size <= i)
            break;

        if (idx1 >= i)
            sum += num1[idx1 - i] - '0';

        if (idx2 >= i)
            sum += num2[idx2 - i] - '0';

        string num = "";
        num += sum % 10 + '0';
        ret = num + ret;
        sum /= 10;

        // cout << ret << " ";
        // cout << sum << endl;
        i++;
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << add("909", "1");

    return 0;
}