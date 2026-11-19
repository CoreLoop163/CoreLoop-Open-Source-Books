#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;

struct ListNode {
    ElemType data;
    struct ListNode* next_node;
};

typedef struct ListNode* LinkList;

// 删除所有值为 e 的节点
bool DeleteValue(LinkList L, int e) {

}

// 构建链表
LinkList CreateList(int arr[], int n) {
    // 创建头结点
    LinkList L = (LinkList)malloc(sizeof(ListNode));
    L->next_node = NULL;

    ListNode* tail = L;

    for (int i = 0; i < n; i++) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->data = arr[i];
        node->next_node = NULL;

        tail->next_node = node;
        tail = node;
    }

    return L;
}

// 输出链表
void PrintList(LinkList L) {
    ListNode* cur = L->next_node;

    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next_node;
    }
    cout << endl;
}

// 释放整个链表
void DestroyList(LinkList L) {
    ListNode* cur = L;

    while (cur != NULL) {
        ListNode* temp = cur;
        cur = cur->next_node;
        free(temp);
    }
}

int main() {
    int arr[] = { 3, 1, 2, 3, 3, 4, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 构建链表
    LinkList L = CreateList(arr, n);

    cout << "删除前：";
    PrintList(L);

    // 删除所有值为 3 的节点
    bool result = DeleteValue(L, 3);

    cout << "删除后：";
    PrintList(L);

    cout << "是否删除成功：" << (result ? "是" : "否") << endl;

    // 释放链表
    DestroyList(L);

    return 0;
}
