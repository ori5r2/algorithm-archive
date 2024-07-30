#include <bits/stdc++.h>
using namespace std;

struct TRIE
{
    bool finish; // 문자열이 끝난 지점에서 Finish = true로 체크
    TRIE *Node[26];

    // 생성자
    TRIE()
    {
        finish = false;
        for (int i = 0; i < 26; i++)
            Node[i] = NULL;
    }

    // 트라이에 문자열 삽입
    void insert(char *str)
    {
        if (*str == NULL)
        {
            finish = true;
            return;
        }

        int cur = *str - 'A';
        if (Node[cur] == NULL)
            Node[cur] = new TRIE();

        Node[cur]->insert(str + 1);
    }

    // 트라이에서 문자열 찾기
    bool find(char *str)
    {
        if (*str == NULL)
        {
            if (finish == true)
                return true;
            return false;
        }

        int cur = *str - 'A';
        if (Node[cur] == NULL)
            return false;

        return Node[cur]->find(str + 1);
    }
};

int main(void)
{
    TRIE *root = new TRIE();
    char *str1 = "ABC";
    char *str2 = "ABD";

    root->insert(str1);
    root->insert(str2);
}