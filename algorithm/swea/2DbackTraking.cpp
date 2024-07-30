#include <bits/stdc++.h>
using namespace std;

fstream fout;
int arr[5];
int board[3][3];
bool visited[3][3];
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void backTraking(int k)
{
    if (k == 5)
    {
        bool isPrint = true;
        // check
        memset(visited, 0, sizeof(visited));
        q.push({arr[0] / 3, arr[0] % 3});
        visited[arr[0] / 3][arr[0] % 3] = 1;

        while (!q.empty())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3)
                    continue;

                if (visited[ny][nx])
                    continue;

                if (board[ny][nx])
                {
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            if (!visited[arr[i] / 3][arr[i] % 3])
            {
                isPrint = false;
                break;
            }
        }

        // print
        if (isPrint)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    fout << board[i][j] << " ";
                fout << endl;
            }
            fout << endl;
        }

        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (k >= 1)
            {
                if (i * 3 + j <= arr[k - 1])
                    continue;
            }

            arr[k] = i * 3 + j;
            board[i][j] = 1;
            backTraking(k + 1);
            board[i][j] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fout.open("output.txt");

    backTraking(0);

    fout.close();
    return 0;
}