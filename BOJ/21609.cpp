#include <bits/stdc++.h>
using namespace std;
#define MX 25

// fstream fout;
int N, M;
int board[MX][MX];
bool visited[MX][MX];
bool tmp[MX][MX];

bool isBlock;
int ans;

// 오 아 왼 위
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// void printBoard()
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             if (board[i][j] < 0)
//                 fout << board[i][j] << " ";
//             else
//                 fout << "+" << board[i][j] << " ";
//         }
//         fout << endl;
//     }
//     fout << endl;
// }

// 블록 그룹 >=2
// 일반 블록(1~M) 적어도 하나 있어야 하며, 모두 같은 색
// 검은색 블록(-1) 포함 x
// 무지개 블록(0) 상관 없음
// 기준 블록: 무지개 블록 아니 블록 중 행의 번호가 가장 작은 블록, 열의 번호가 가장 작은 블록
void findBlock()
{
    // 초기화
    isBlock = false;
    int maxSize = 0, maxRainbow = 0;
    pair<int, int> p = {-1, -1};
    memset(visited, false, sizeof(visited));

    // 크기가 가장 큰 블록 그룹 찾는다.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == -1 || board[i][j] == 0 || board[i][j] == -2)
                continue;

            if (visited[i][j])
                continue;

            queue<pair<int, int>> q;
            memset(tmp, false, sizeof(tmp));

            q.push({i, j});
            int size = 1, rainbow = 0;
            int color = board[i][j];
            tmp[i][j] = true;

            while (!q.empty())
            {
                int y = q.front().first, x = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                        continue;

                    if (tmp[ny][nx])
                        continue;

                    if (board[ny][nx] == -1 || board[ny][nx] == -2)
                        continue;

                    else if (board[ny][nx] == 0) // 무지개
                    {
                        size += 1;
                        rainbow += 1;
                        q.push({ny, nx});
                        tmp[ny][nx] = true;
                    }
                    else if (board[ny][nx] == color)
                    {
                        size += 1;
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                        tmp[ny][nx] = true;
                    }
                }
            }

            if (size >= 2)
            {
                // fout << i << " " << j << " " << size << " " << rainbow << endl;
                isBlock = true;
                // 크기가 가장 큰 블록 그룹
                // 무기개 블록 수가 가장 많은 블록
                // 행이 가장 큰 것
                // 열이 가장 큰 것
                if (size > maxSize) // ⭐️ 업데이트 모두 다 해줘야함ㅠㅠㅠㅠㅠ(rainbo안 해줘서 틀림)
                    maxSize = size, p = {i, j}, maxRainbow = rainbow;
                else if (size == maxSize)
                {
                    if (rainbow > maxRainbow)
                        maxRainbow = rainbow, p = {i, j};
                    else if (rainbow == maxRainbow)
                    {
                        p = max(p, {i, j});
                    }
                }
            }
        }
    }

    if (!isBlock)
        return;

    // fout << p.first << " " << p.second << " " << maxSize << " " << maxRainbow << endl;
    // 블록 그룹의모든 블록 제거
    queue<pair<int, int>> deleteQ;
    deleteQ.push(p);
    memset(tmp, false, sizeof(tmp));

    tmp[p.first][p.second] = true;
    int color = board[p.first][p.second];
    board[p.first][p.second] = -2;

    while (!deleteQ.empty())
    {
        int y = deleteQ.front().first, x = deleteQ.front().second;
        deleteQ.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d], nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if (tmp[ny][nx])
                continue;

            if (board[ny][nx] == -1 || board[ny][nx] == -2)
                continue;

            if (board[ny][nx] == 0 || board[ny][nx] == color)
            {
                board[ny][nx] = -2;
                deleteQ.push({ny, nx});
            }
        }
    }

    // B^2 획득
    ans += (maxSize * maxSize);
}

void gravity()
{
    for (int j = 0; j < N; j++)
    {
        bool isEmpty = false;
        int idx = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            if (board[i][j] == -2)
            {
                if (!isEmpty)
                {
                    isEmpty = true;
                    idx = i;
                }
            }
            else if (board[i][j] == -1)
            {
                isEmpty = false;
            }
            else
            {
                if (isEmpty)
                {
                    board[idx][j] = board[i][j];
                    board[i][j] = -2;
                    isEmpty = true;

                    // 다음 빈칸으로
                    while (idx >= 0)
                    {
                        idx--;
                        if (board[idx][j] == -2)
                            break;
                    }
                }
            }
        }
    }
}

// 반시계 방향으로 회전
void rotate()
{
    for (int t = 0; t < N / 2; t++)
    {
        int y = t, x = t;

        // 줍기
        queue<int> q;
        for (int d : {0, 1, 2, 3})
        {
            for (int i = 0; i < (N - (2 * t + 1)); i++)
            {
                q.push(board[y][x]);
                y = y + dy[d], x = x + dx[d];
            }
        }

        // 넣기
        y = (N - 1) - t, x = t;
        for (int d : {3, 0, 1, 2})
        {
            for (int i = 0; i < (N - (2 * t + 1)); i++)
            {
                board[y][x] = q.front();
                q.pop();
                y = y + dy[d], x = x + dx[d];
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
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    while (1)
    {
        findBlock();
        if (!isBlock)
            break;

        gravity();
        rotate();
        gravity();
        // printBoard();
    }
    cout << ans;

    // fout.close();
    return 0;
}