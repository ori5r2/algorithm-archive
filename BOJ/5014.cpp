// #5014. 스타트 링크
// BFS: 1차원
#include <bits/stdc++.h>
using namespace std;
#define MX 1000002

int F, S, G, U, D; // F: 건물 층 수, S: 강호 위치, G: 스타트링크 위치
int board[MX];

void BFS()
{
    queue<int> q;
    q.push(S);
    board[S] = 0;
    int dx[] = {U, -1 * D};

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int d = 0; d < 2; d++)
        {
            int x = front + dx[d];

            if (x <= 0 || x > F)
                continue;

            if (board[x] != -1)
                continue;

            q.push(x);
            board[x] = board[front] + 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //

    memset(board, -1, sizeof(board));
    cin >> F >> S >> G >> U >> D;

    BFS();

    if (board[G] == -1)
        cout << "use the stairs";
    else
        cout << board[G];

    return 0;
}