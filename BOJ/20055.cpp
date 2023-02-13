#include <bits/stdc++.h>
using namespace std;
#define MX 102

int A[2 * MX];
int isRobot[2 * MX];
int N, K;

int getIdx(int k, int r)
{
    int ret = (k - r) % (2 * N);
    if (ret <= 0)
        ret += (2 * N);
    return ret;
}

void printArr(int a[MX * 2], int r)
{
    int k = getIdx(1, r);
    for (int i = 1; i <= 2 * N; i++)
    {
        if (k == 2 * N + 1)
            k = 1;
        cout << a[k++] << " ";
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> K;

    for (int i = 1; i <= 2 * N; i++)
        cin >> A[i];

    int num = 1, isZero = 0, div = 2 * N;
    int rotate = 0;
    vector<int> robot;

    while (1)
    {
        // 1. 한 칸 회전
        rotate++;

        // 2. 로봇이 있으면!
        for (int i = N; i > 0; i--)
        {
            int now = getIdx(i, rotate);

            if (isRobot[now]) // 만약 로봇이 N에 있다면 내리기
            {
                if (i == N)
                    isRobot[now] = false;
                else
                {
                    // i에 로봇이 있다면 i+1에 로봇이 있는지 확인
                    int next = getIdx(i + 1, rotate);
                    if (!isRobot[next] && A[next] >= 1)
                    {
                        isRobot[now] = false;
                        A[next] -= 1;
                        if (A[next] == 0)
                            isZero++;

                        if (i + 1 != N)
                            isRobot[next] = true;
                    }
                }
            }
        }

        // // 2. 로봇이 있으면! //

        // for (int i = 0; i < robot.size(); i++) // 시간 초과
        // { // vector에 있는 로봇을 삭제하지 못해서 로봇이 생길때마다 탐색하는 시간이 길어짐

        //     int idx_robot = robot[i];
        //     if (idx_robot == -1)
        //         continue;

        //     // 만약 로봇이 N에 있다면 삭제 내리기
        //     int isN = (idx_robot + rotate) % div;
        //     if (isN <= 0)
        //         isN += div;
        //     if (isN == N)
        //     {
        //         robot[i] = -1;
        //         isRobot[idx_robot] = false;
        //         continue;
        //     }

        //     // 이동할 수 있는지 확인
        //     int next_robot = (idx_robot + 1) % div;
        //     if (next_robot <= 0)
        //         next_robot += div;

        //     if (!isRobot[next_robot] && A[next_robot] >= 1)
        //     {
        //         isRobot[idx_robot] = false;

        //         A[next_robot] -= 1;
        //         if (A[next_robot] == 0)
        //             isZero++;

        //         int pos = (next_robot + rotate) % div;
        //         if (pos <= 0)
        //             pos += div;

        //         if (pos == N)
        //             robot[i] = -1;
        //         else
        //         {
        //             robot[i] = next_robot;
        //             isRobot[next_robot] = true;
        //         }
        //     }
        // }

        // 3. 1번칸의 내구도가 0이 아니라면 로봇 올리기
        int idx1 = getIdx(1, rotate);

        if (A[idx1] != 0)
        {
            A[idx1] -= 1;
            if (A[idx1] == 0)
                isZero++;

            isRobot[idx1] = true;
        }

        // 4. 0의 칸 개수가 K개 이상이라면 종료
        if (isZero >= K)
            break;
        num++;
    }

    cout << num;

    return 0;
}