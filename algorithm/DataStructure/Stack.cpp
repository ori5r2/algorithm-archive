#include <bits/stdc++.h>
using namespace std;
#define MX_SIZE 10

int sp = -1; // 스택 포인터
int stck[MX_SIZE];

bool isEmpty() { return sp == -1 ? true : false; }

bool isFull() { return sp == MX_SIZE - 1 ? true : false; }

void push(int data)
{
    if (isFull())
    {
        cout << "stack is full\n";
        return;
    }

    stck[++sp] = data;
}

void pop()
{
    if (isEmpty())
    {
        cout << "stack is empty\n";
        return;
    }

    sp--;
}

int top()
{
    return stck[sp];
}

int main(void)
{
    pop();
    for (int i = 1; i <= 11; i++)
        push(i);
}