#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1 = "Hello world";

    stringstream ss(str1);
    string tmp;

    while (getline(ss, tmp, ' '))
    {
        cout << tmp << endl;
    }

    return 0;
}