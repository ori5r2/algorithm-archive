#include <bits/stdc++.h>
using namespace std;
#define MX 52

int N;
int hitterInfo[MX][10]; // 이닝, 타자
bool board[4];          // 주자
int order[10];
int score, ans;

void hit1()
{
    if (board[3])
        board[3] = false, score++;
    if (board[2])
        board[2] = false, board[3] = true;
    if (board[1])
        board[1] = false, board[2] = true;

    board[1] = true;
}

void hit2()
{
    if (board[3])
        board[3] = false, score++;
    if (board[2])
        board[2] = false, score++;
    if (board[1])
        board[1] = false, board[3] = true;
    board[2] = true;
}

void hit3()
{
    if (board[3])
        board[3] = false, score++;
    if (board[2])
        board[2] = false, score++;
    if (board[1])
        board[1] = false, score++;
    board[3] = true;
}

void homerun()
{
    if (board[3])
        board[3] = false, score++;
    if (board[2])
        board[2] = false, score++;
    if (board[1])
        board[1] = false, score++;
    score++;
}

void playGame()
{
    // 초기화
    int n = 1;
    int idx = 1;
    int out = 0;
    score = 0;
    for (int i = 0; i < 4; i++)
        board[i] = false;

    while (n <= N)
    {
        int hitter = order[idx];       // 타자
        int h = hitterInfo[n][hitter]; // n이닝에서 hitter의 결과
        idx++;                         // 다음 타자
        if (idx == 10)                 // 9번 타자 끝나면 다시 1번 타자부터 시작
            idx = 1;

        if (h == 0)
            out++;
        else if (h == 1)
            hit1();
        else if (h == 2)
            hit2();
        else if (h == 3)
            hit3();
        else if (h == 4)
            homerun();

        if (out == 3) // 3아웃 > 이닝 새로 시작
        {
            out = 0;
            for (int i = 0; i < 4; i++) // 이닝 시작할 때 주자가 없음
                board[i] = false;
            n++;
        }
    }
}

void permu()
{
    vector<int> v;
    for (int i = 2; i <= 9; i++)
        v.push_back(i);

    do
    {
        for (int i = 0; i < 3; i++)
            order[i + 1] = v[i];
        order[4] = 1;
        for (int i = 3; i < v.size(); i++)
            order[i + 2] = v[i];

        playGame();
        ans = max(ans, score);

    } while (next_permutation(v.begin(), v.end()));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 9; j++)
            cin >> hitterInfo[i][j];
    }
    permu();
    cout << ans;

    return 0;
}