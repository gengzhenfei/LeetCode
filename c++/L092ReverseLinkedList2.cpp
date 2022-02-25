#include "Utils.cpp"

class L092ReverseLinkedList2
{
private:
    /* data */
public:
    L092ReverseLinkedList2(/* args */);
    ~L092ReverseLinkedList2();

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left >= right || head == nullptr || head->next == nullptr) return head;
        ListNode *pre = head, *p = head, *preq = head, *q = head->next, *r = head->next->next;
        int cnt = 1;
        while (cnt < left) {
            pre = p;
            p = p->next;
            preq = p;
            q = p->next;
            cnt++;
        }
        while (cnt < right) {
            r = q->next;
            q->next = preq;
            preq = q;
            q = r;
            r = r == nullptr ? nullptr : r->next;
            cnt++;
        }
        if (left == 1) {
            head = preq;
            p->next = q;
        } else {
            pre->next = preq;
            p->next = q;
        }

        return head;
    }
};

L092ReverseLinkedList2::L092ReverseLinkedList2(/* args */) {}

L092ReverseLinkedList2::~L092ReverseLinkedList2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L092ReverseLinkedList2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> list{1, 2, 3, 4, 5};
//     int left = 4, right = 5;
//     ListNode *head = Utils::vector2ListNode(list);
//     L092ReverseLinkedList2 ReverseLinkedList2;
//     ListNode *res = ReverseLinkedList2.reverseBetween(head, left, right);
//     Utils::printLink(res);
//     return 0;
// }