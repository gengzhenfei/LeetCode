#include "Utils.cpp"
using namespace std;

class L082RemoveDuplicatesFromSortedList2
{
private:
    /* data */
public:
    L082RemoveDuplicatesFromSortedList2(/* args */);
    ~L082RemoveDuplicatesFromSortedList2();

    ListNode *deleteDuplicates(ListNode *head)
    {
        while (head != nullptr) { // head非空 寻找不重复的数字作为头节点
            ListNode *p = head, *q = head;
            while (q->next != nullptr && q->val == q->next->val) { q = q->next; }
            if (p == q) { // 不重复
                break;
            } else { // p q 之间的数字为同一个
                head = q->next;
            }
        }
        if (head == nullptr) return head;
        ListNode *pre = head, *p = head->next, *q = head->next;
        while (q != nullptr) {
            while (q->next != nullptr && q->val == q->next->val) { q = q->next; }
            if (p == q) { // 不重复数字
                pre = p;
                p = p->next;
                q = q->next;
            } else { // p q 之间为重复数字
                pre->next = q->next; // 删除重复数字的节点
                if (pre == nullptr) {
                    break;
                } else {
                    p = pre->next;
                    q = pre->next;
                }
            }
        }

        return head;
    }
};

L082RemoveDuplicatesFromSortedList2::L082RemoveDuplicatesFromSortedList2(/* args */) {}

L082RemoveDuplicatesFromSortedList2::~L082RemoveDuplicatesFromSortedList2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L082RemoveDuplicatesFromSortedList2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{1, 1, 1, 2, 2, 3};
//     ListNode *head = Utils::vector2ListNode(nums);
//     L082RemoveDuplicatesFromSortedList2 RemoveDuplicates;
//     ListNode *res = RemoveDuplicates.deleteDuplicates(head);
//     Utils::printLink(res);
//     return 0;
// }