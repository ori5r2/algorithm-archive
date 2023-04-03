#include <bits/stdc++.h>
using namespace std;

// fstream fout;
int init[5][5];
int board[5][5];
bool visited[5][5];
queue<pair<int, int>> q;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int ans = 0;
int arr[7];

// void printBoard()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 5; j++)
//             fout << board[i][j] << " ";
//         fout << endl;
//     }
//     fout << endl;
// }

void backTraking(int k)
{
    if (k == 7)
    {
        bool isPrint = true;
        // check
        memset(visited, 0, sizeof(visited));
        q.push({arr[0] / 5, arr[0] % 5});
        visited[arr[0] / 5][arr[0] % 5] = 1;

        while (!q.empty())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
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

        int val = 0;
        for (int i = 0; i < 7; i++)
        {
            if (!visited[arr[i] / 5][arr[i] % 5])
            {
                isPrint = false;
            }
            else
            {
                if (init[arr[i] / 5][arr[i] % 5] == 1)
                    val++;
            }
        }

        if (isPrint)
        {
            // printBoard();
            if (val >= 4)
                ans++;
        }

        return;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (k >= 1)
            {
                if (i * 5 + j <= arr[k - 1])
                    continue;
            }

            arr[k] = i * 5 + j;
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

    // freopen("input.txt", "r", stdin);
    //  fout.open("output.txt");

    string str;
    for (int i = 0; i < 5; i++)
    {
        cin >> str;
        for (int j = 0; j < 5; j++)
        {
            if (str[j] == 'S')
                init[i][j] = 1;
            else
                init[i][j] = 2;
        }
    }

    backTraking(0);
    cout << ans;

    // fout.close();
    return 0;
}