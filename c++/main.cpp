#include <iostream>
#include "L019RemoveNthNodeFromEndOfList.cpp"
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    int n = 2;
    L019RemoveNthNodeFromEndOfList RemoveNthNodeFromEndOfList;
    ListNode *head = RemoveNthNodeFromEndOfList.array2ListNode(v);
    head = RemoveNthNodeFromEndOfList.removeNthFromEnd(head, n);
    // 打印链表
    ListNode *p = head;
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}