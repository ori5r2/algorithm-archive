#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *head = NULL;

// 앞에 노드 추가
void insertStart(int new_data)
{
    // 새로운 노드 만들기
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->next = head;

    // head를 새로운 노드로 바꾸기
    head = newNode;
}

// 앞에 노드 삭제
void deleteStart()
{
    if (head == NULL)
        return;

    Node *removed = head;
    head = removed->next;

    free(removed); // 메모리 할당 해제
}

// 맨 뒤에 노드 추가
void insertEnd(int new_data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        Node *last = head;
        while (last->next != NULL)
            last = last->next;

        last->next = newNode;
    }
}

// 맨 뒤에 노드 삭제
void deleteEnd()
{
    if (head == NULL)
        return;

    Node *last = head;
    if (last->next == NULL)
    {
        Node *removed = last;
        head = NULL;
        free(removed);

        return;
    }

    while (last->next->next != NULL)
        last = last->next;

    Node *removed = last->next;
    last->next = NULL;
    free(removed);
}

// 특정 노드 뒤에 노드 추가
void insertAfter(Node *prev, int new_data)
{
    // 새로운 노드 만들기
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->next = prev->next;

    prev->next = newNode;
}

// 특정 노드 뒤에 삭제
void deleteAfter(Node *prev)
{
    Node *removed = prev->next;
    prev->next = removed->next;

    free(removed);
}

// 특정 노드 탐색
Node *search(int data)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == data)
            return p;
        else
            p = p->next;
    }

    return NULL;
}

// 리스트 출력
void printList()
{
    Node *last = head;
    if (last == NULL)
        return;

    while (last != NULL)
    {
        cout << last->data << " ";
        last = last->next;
    }
    cout << endl;
}

int main(void)
{
    for (int i = 1; i <= 5; i++)
        insertStart(i);
    printList(); // 5 4 3 2 1

    for (int i = 1; i <= 3; i++)
        deleteStart();
    printList(); // 2 1

    for (int i = 6; i <= 10; i++)
        insertEnd(i);
    printList(); // 2 1 6 7 8 9 10

    for (int i = 1; i <= 3; i++)
        deleteEnd();
    printList(); // 2 1 6 7

    insertAfter(search(6), 8);
    printList(); // 2 1 6 8 7

    deleteAfter(search(2));
    printList(); // 2 6 8 7
}
