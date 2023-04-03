#include <bits/stdc++.h>
using namespace std;
#define MX 55

// fstream fout;

int N, M;
int d, s;
int board[MX][MX];
vector<int> v;
vector<int> gV;
int ans[4];

// 위1 아래2 왼3 오4
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, -1, 1, 0, 0};

// void printBoard()
// {
//     for (int i = 1; i <= N; i++)
//     {
//         for (int j = 1; j <= N; j++)
//             fout << board[i][j] << " ";
//         fout << endl;
//     }
//     fout << endl;
// }

// void printVector()
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         fout << v[i] << " ";
//         if ((i + 1) % N == 0)
//             fout << endl;
//     }
//     fout << endl
//          << endl;
// }

void boardTovec()
{
    v.clear();
    int y = (N + 1) / 2, x = (N + 1) / 2;
    for (int t = 0; t < N / 2; t++)
    {
        // 왼 1 아 2t+1 오 2t 위 2t 왼 2t
        // 방향 갯수
        pair<int, int> p[] = {{3, 1}, {2, 2 * t + 1}, {4, 2 * t + 2}, {1, 2 * t + 2}, {3, 2 * t + 2}};
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < p[i].second; j++)
            {
                y = y + dy[p[i].first], x = x + dx[p[i].first];
                if (board[y][x])
                    v.push_back(board[y][x]);
            }
        }
    }
}

// 구슬 던지기
// di 방향으로 거리가 si 이하인 모든칸에 있는 구슬 파괴
void brk()
{
    int y = (N + 1) / 2, x = (N + 1) / 2; // 상어 위치
    for (int i = 0; i < s; i++)
    {
        y = y + dy[d], x = x + dx[d];
        board[y][x] = 0;
    }
}

// 구슬 폭발
// 4개 이상 연속하는 구슬
// 더 이상 폭발하는 구슬이 없을때까지 반복
bool explosion()
{
    int cnt = 0, ball = 0, idx = 0;
    bool suc = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            if (ball == v[i]) // 같은 숫자일 때
                cnt++;
            else // 다른 숫자일 때
            {
                if (cnt >= 4)
                {
                    suc = true;
                    ans[ball] += cnt;
                    for (int j = idx; j < i; j++)
                        v[j] = 0;
                }

                cnt = 1, ball = v[i], idx = i;
            }
        }
    }
    // 마지막 확인
    if (cnt >= 4)
    {
        suc = true;
        ans[ball] += cnt; // ⭐️
        for (int j = idx; j < v.size(); j++)
            v[j] = 0;
    }

    return suc;
}

// 구슬 A, B로 바꿈
// A: 구슬 개수, B: 구슬 번호
void groupV()
{
    gV.clear();
    int cnt = 0, ball = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            if (v[i] == ball)
                cnt++;
            else
            {
                if (cnt)
                    gV.push_back(cnt), gV.push_back(ball);

                cnt = 1, ball = v[i];
            }
        }
    }
    if (cnt)
        gV.push_back(cnt), gV.push_back(ball);
}

// vector을 board로 바꾸기
void vecToboard()
{
    int y = (N + 1) / 2, x = (N + 1) / 2;

    int idx = 0;
    for (int t = 0; t < N / 2; t++)
    {
        // 왼 1 아 2t+1 오 2t 위 2t 왼 2t
        // 방향 갯수
        pair<int, int> p[] = {{3, 1}, {2, 2 * t + 1}, {4, 2 * t + 2}, {1, 2 * t + 2}, {3, 2 * t + 2}};
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < p[i].second; j++)
            {
                y = y + dy[p[i].first], x = x + dx[p[i].first];
                if (idx >= gV.size())
                    board[y][x] = 0;
                else
                    board[y][x] = gV[idx++];
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    for (int i = 0; i < M; i++)
    {
        cin >> d >> s;
        brk();
        boardTovec();
        while (1)
        {
            if (!explosion())
                break;
        }
        groupV();
        vecToboard();
    }

    cout << ans[1] + 2 * ans[2] + 3 * ans[3];

    // fout.close();
    return 0;
}