#include <bits/stdc++.h>
using namespace std;

// fstream fout;

int ans;
int dice[11];
int arr[11];
int board[4][25];
int horseMap[4][25];

pair<int, int> horse[5];

void backTraking(int k)
{
    if (k == 10)
    {
        // 초기화
        int val = 0;
        for (int i = 1; i <= 4; i++)
            horse[i] = {0, 0};

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 25; j++)
                horseMap[i][j] = 0;

        // 반례: 1	4	2	1	3	3	2	4	2	4
        // 반례 답: int tempArr[] = {1, 1, 1, 1, 2, 2, 1, 2, 1, 2};

        // 말 선택
        for (int i = 0; i < 10; i++)
        {
            int idx = arr[i], mv = dice[i];
            int x = horse[idx].first, y = horse[idx].second;

            // 끝났는데 이동시킬려고 함
            if ((x == 0 && y >= 21) || (x == 1 && y >= 13) || (x == 2 && y >= 17) || (x == 3 && y >= 23))
                return;

            int nx, ny;
            if (x == 0 && y == 5)
                nx = 1, ny = y + mv;
            else if (x == 0 && y == 10)
                nx = 2, ny = y + mv;
            else if (x == 0 && y == 15)
                nx = 3, ny = y + mv;
            else
                nx = x, ny = y + mv;

            // 이동을 마치는 칸이 도착 칸
            if ((nx == 0 && ny >= 21) || (nx == 1 && ny >= 13) || (nx == 2 && ny >= 17) || (nx == 3 && ny >= 23))
            {
                horse[idx] = {nx, ny}; // ⭐️ outofBounds
                horseMap[x][y] = 0;
                continue;
            }

            // 이동하려는 칸에 이미 말이 있는 경우
            if (horseMap[nx][ny] > 0)
                return;

            // ⭐️ 겹치는 부분 체크!!
            if (nx == 0 && ny == 20)
            {
                if (horseMap[1][12] || horseMap[2][16] || horseMap[3][22])
                    return;
            }

            if (nx == 1 && ny >= 9)
            {
                if (horseMap[2][ny + 4] || horseMap[3][ny + 10])
                    return;
            }
            if (nx == 1 && ny == 12 && horseMap[0][20])
                return;

            if (nx == 2 && ny >= 13)
            {
                // if (horseMap[0][ny - 4] || horseMap[3][ny + 6])
                if (horseMap[1][ny - 4] || horseMap[3][ny + 6]) // ⭐️ 오타,,?
                    return;
            }
            if (nx == 2 && ny == 16 && horseMap[0][20])
                return;

            if (nx == 3 && ny >= 19)
            {
                if (horseMap[1][ny - 10] || horseMap[2][ny - 6])
                    return;
            }
            if (nx == 3 && ny == 22 && horseMap[0][20])
                return;

            // 이동!
            horseMap[nx][ny] = idx;
            horseMap[x][y] = 0;
            horse[idx] = {nx, ny};
            val += board[nx][ny];
        }

        ans = max(ans, val);

        return;
    }

    for (int i = 1; i <= 4; i++)
    {
        arr[k] = i;
        backTraking(k + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");
    for (int i = 0; i < 10; i++)
        cin >> dice[i];

    // 보드판 만들기
    for (int i = 1; i <= 20; i++)
        board[0][i] = 2 * i;

    board[1][6] = 13, board[1][7] = 16, board[1][8] = 19, board[1][9] = 25, board[1][10] = 30, board[1][11] = 35, board[1][12] = 40;
    board[2][11] = 22, board[2][12] = 24, board[2][13] = 25, board[2][14] = 30, board[2][15] = 35, board[2][16] = 40;
    board[3][16] = 28, board[3][17] = 27, board[3][18] = 26, board[3][19] = 25, board[3][20] = 30, board[3][21] = 35, board[3][22] = 40;

    backTraking(0);
    cout << ans;

    // fout.close();
    return 0;
}