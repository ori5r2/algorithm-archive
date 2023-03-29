#include <bits/stdc++.h>
using namespace std;

// fstream fout;
string str;
int board[3][3];
int cnt[3];
int row[3];
// 반례
// XOXOXOXO.
// end

// void printBoard()
// {
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//             fout << board[i][j] << " ";
//         fout << endl;
//     }
//     fout << endl;
// }

void check()
{
    // 세로 체크
    for (int j = 0; j < 3; j++)
    {
        bool suc = true;
        int num = board[0][j];
        for (int i = 1; i < 3; i++)
        {
            if (num != board[i][j])
                suc = false;
        }
        if (suc)
            row[num]++;
    }
    // 가로 체크
    for (int i = 0; i < 3; i++)
    {
        bool suc = true;
        int num = board[i][0];
        for (int j = 1; j < 3; j++)
        {
            if (num != board[i][j])
                suc = false;
        }
        if (suc)
            row[num]++;
    }
    // 대각선 체크 '/'
    bool suc = true;
    int num = board[0][0];
    for (int n : {board[1][1], board[2][2]})
        if (n != num)
            suc = false;
    if (suc)
        row[num]++;
    // 대각선 체크 '\'
    suc = true;
    num = board[0][2];
    for (int n : {board[1][1], board[2][0]})
        if (n != num)
            suc = false;
    if (suc)
        row[num]++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // fout.open("output.txt");

    while (1)
    {
        cin >> str;
        if (str == "end")
            break;

        // 초기화
        memset(cnt, 0, sizeof(cnt));
        memset(row, 0, sizeof(row));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (str[i * 3 + j] == 'X')
                {
                    board[i][j] = 1;
                    cnt[1]++;
                }
                else if (str[i * 3 + j] == 'O')
                {
                    board[i][j] = 2;
                    cnt[2]++;
                }
                else if (str[i * 3 + j] == '.')
                {
                    board[i][j] = 0;
                    cnt[0]++;
                }
            }
        }

        if (cnt[1] - cnt[2] == 0 || cnt[1] - cnt[2] == 1)
        {
            check();
            if (cnt[0] == 0)
            {
                if (row[1] <= row[2])
                {
                    if (row[1] == 0 && row[2] == 0)
                        cout << "valid\n";
                    else
                        cout << "invalid\n";
                }
                else
                    cout << "valid\n";
            }
            else
            {
                // ⭐️ X가 이기면 X가 개수가 한개 많아야함
                if (row[1] == 1 && row[2] == 0 && cnt[1] - cnt[2] == 1)
                    cout << "valid\n";
                // ⭐️ O가 이기면 O, X의 개수 같아야함
                else if (row[2] == 1 && row[1] == 0 && cnt[1] == cnt[2])
                    cout << "valid\n";
                // ⭐️ 그 외 모두 invalid
                // 줄이 한개 이상 생기려면 최소 X가 5개 필요 == 모든 칸 채워야 함
                else
                    cout << "invalid\n";
            }
        }
        else
        {
            cout << "invalid\n";
        }
        // printBoard();
        // fout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
        // fout << row[0] << " " << row[1] << " " << row[2] << endl;
        // fout << endl;
    }

    // fout.close();
    return 0;
}