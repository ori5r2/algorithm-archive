#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* 배열 회전하기 */
// 1. 기본적이 회전 알고리즘
void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = temp;
}
void leftRotate1(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

// 2. 저글링 알고리즘
int gcd(int a, int b) // a>b
{
    if (a < b)
        swap(a, b);

    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void leftRotate2(int arr[], int n, int d)
{
    for (int i = 0; i < gcd(d, n); i++)
    {
        int temp = arr[i];
        int j = i;
        while (1)
        {
            int k = j + d;
            if (k >= n)
                k -= n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

// 3. 역전 알고리즘 구현
// 회전 시키는 수만큼 구간 나눔 > 각각의 구간 역전 > 합침 > 합친 배열 reverse
void reverseArr(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++, end--;
    }
}
void leftRotate3(int arr[], int d, int n)
{
    reverseArr(arr, 0, d - 1);
    reverseArr(arr, d, n - 1);
    reverseArr(arr, 0, n - 1);
}

/* 배열의 특정 최대 합 구하기 */
// 지정된 배열에서 하나씩 회전을 해서 i*arr[i]의 합이 가장 컸을 때 값을 출력하는 문제
// R_j - R_(j-1) = arrSum - n*arr[n-j] -> R_j = R_(j-1) + arrSum - n*arr[n-j]
int maxVal(int arr[], int n)
{
    int arrSum = 0; // arr[i]의 전체 합
    int curSum = 0; // i*arr[i]의 전체 합

    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
        curSum += (i * arr[i]);
    }

    int maxSum = curSum;
    for (int j = 1; j < n; j++)
    {
        curSum = curSum + arrSum - n * arr[n - j];
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

/* 특정 배열을 arr[i]=i로 재배열 하기 */
// 주어진 배열에서 arr[i]=i이 가능한 것만 재배열 시키고 arr[i]=i가 없으면 -1로 채움

void fix(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // arr[i] 가 -1이 아니고, i도 아닐 때
        if (arr[i] != -1 && arr[i] != i)
        {
            int x = arr[i];

            while (arr[x] != -1 && arr[x] != x)
            {
                int y = arr[x];
                arr[x] = x;

                x = y;
            }

            arr[x] = x;
            if (arr[i] != i)
                arr[i] = -1;
        }
    }
}

int main(void)
{
    // 배열 선언
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    // 배열 크기 구하기
    int n = sizeof(arr) / sizeof(arr[0]);

    /* 배열 회전하기 */
    // 1. 기본적인 회전 알고리즘
    leftRotate1(arr, n, 2);
    // 2. 저글링 알고리즘
    leftRotate2(arr, n, 2);
    // 3. 역전 알고리즘
    leftRotate3(arr, n, 2);

    /* 배열 특정 최대 합 구하기 */
    int ret = maxVal(arr, n);

    /* 특정 배열을 arr[i]=i로 재배열 하기 */
    fix(arr, n);
}