#include <bits/stdc++.h>
using namespace std;

// fstream fout;

int N, t, x, y, score, ans;

int redBoard[4][4]; // 행 열
int greenBoard[6][4];
int blueBoard[4][6];

// void printBoard()
// {
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//             fout << redBoard[i][j] << " ";
//         for (int j = 0; j < 6; j++)
//             fout << blueBoard[i][j] << " ";
//         fout << endl;
//     }
//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = 0; j < 4; j++)
//             fout << greenBoard[i][j] << " ";
//         fout << endl;
//     }
//     fout << endl;
// }

void putBlue()
{
    int idx1 = 6, idx2 = 6;
    for (int j = 5; j >= 0; j--)
    {
        if (blueBoard[x][j])
            idx1 = j;
        if (blueBoard[x + 1][j])
            idx2 = j;
    }

    if (t == 1)
        blueBoard[x][idx1 - 1] = 1;
    else if (t == 2)
        blueBoard[x][idx1 - 1] = 1, blueBoard[x][idx1 - 2] = 1;
    else if (t == 3)
    {
        int idx = min(idx1, idx2);
        blueBoard[x][idx - 1] = 1, blueBoard[x + 1][idx - 1] = 1;
    }
}

void putGreen()
{
    int idx1 = 6, idx2 = 6;
    for (int i = 5; i >= 0; i--)
    {
        if (greenBoard[i][y])
            idx1 = i;
        if (greenBoard[i][y + 1])
            idx2 = i;
    }

    if (t == 1)
        greenBoard[idx1 - 1][y] = 1;
    else if (t == 2)
    {
        int idx = min(idx1, idx2);
        greenBoard[idx - 1][y] = 1, greenBoard[idx - 1][y + 1] = 1;
    }
    else if (t == 3)
        greenBoard[idx1 - 1][y] = 1, greenBoard[idx1 - 2][y] = 1;
}

void deleteBlue()
{
    queue<int> q;
    for (int j = 5; j >= 0; j--)
    {
        bool isDelete = true;
        for (int i = 0; i < 4; i++) // 한 줄 검사
        {
            if (!blueBoard[i][j])
                isDelete = false;
        }
        // 지우기
        if (isDelete)
        {
            score += 1;
            int s = q.size();
            q.push(j + s);
            for (int i = 0; i < 4; i++)
                blueBoard[i][j] = 0;
        }
    }
    // 칸 내리기
    while (!q.empty())
    {
        for (int j = q.front() - 1; j >= 0; j--)
        {
            for (int i = 0; i < 4; i++)
                blueBoard[i][j + 1] = blueBoard[i][j];
        }
        for (int i = 0; i < 4; i++)
            blueBoard[i][0] = 0;
        q.pop();
    }
}

void specialBlue()
{
    int idx = 0;
    for (int j = 0; j <= 1; j++)
    {
        for (int i = 0; i < 4; i++)
            if (blueBoard[i][j])
            {
                idx++;
                break;
            }
    }

    while (idx > 0)
    {
        for (int j = 4; j >= 0; j--)
        {
            for (int i = 0; i < 4; i++)
                blueBoard[i][j + 1] = blueBoard[i][j];
        }
        for (int i = 0; i < 4; i++)
            blueBoard[i][0] = 0;
        idx--;
    }
}

void deleteGreen()
{
    queue<int> q;
    for (int i = 5; i >= 0; i--)
    {
        bool isDelete = true;
        // 한 줄 검사
        for (int j = 0; j < 4; j++)
        {
            if (!greenBoard[i][j])
                isDelete = false;
        }
        // 지우기
        if (isDelete)
        {
            score += 1;
            int s = q.size();
            q.push(i + s);
            for (int j = 0; j < 4; j++)
                greenBoard[i][j] = 0;
        }
    }
    // 지운 칸 내리기
    while (!q.empty())
    {
        for (int i = q.front() - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
                greenBoard[i + 1][j] = greenBoard[i][j];
        }
        for (int j = 0; j < 4; j++)
            greenBoard[0][j] = 0;
        q.pop();
    }
}

void specialGreen()
{
    int idx = 0;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j < 4; j++)
            if (greenBoard[i][j])
            {
                idx++;
                break;
            }
    }

    while (idx > 0)
    {
        for (int i = 4; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
                greenBoard[i + 1][j] = greenBoard[i][j];
        }
        for (int j = 0; j < 4; j++)
            greenBoard[0][j] = 0;
        idx--;
    }
}

void cntBlock()
{
    // blue
    for (int j = 5; j >= 0; j--)
    {
        for (int i = 0; i < 4; i++)
            if (blueBoard[i][j])
                ans++;
    }
    // green
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
            if (greenBoard[i][j])
                ans++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    cin >> N;

    for (int n = 0; n < N; n++)
    {
        cin >> t >> x >> y;
        putBlue();
        putGreen();

        deleteBlue();
        deleteGreen();

        specialBlue();
        specialGreen();
    }
    cntBlock();
    cout << score << "\n";
    cout << ans;

    // fout.close();
    return 0;
}