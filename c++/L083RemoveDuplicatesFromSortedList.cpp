#include "Utils.cpp"
using namespace std;

class L083RemoveDuplicatesFromSortedList
{
private:
    /* data */
public:
    L083RemoveDuplicatesFromSortedList(/* args */);
    ~L083RemoveDuplicatesFromSortedList();

    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr) return head;
        ListNode *p = head, *q = head->next;
        while (q != nullptr) {
            if (p->val == q->val) {
                p->next = q->next;
            } else {
                p = q;
            }
            q = q->next;
        }

        return head;
    }
};

L083RemoveDuplicatesFromSortedList::L083RemoveDuplicatesFromSortedList(/* args */) {}

L083RemoveDuplicatesFromSortedList::~L083RemoveDuplicatesFromSortedList() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L083RemoveDuplicatesFromSortedList.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{1, 1, 1, 2, 2, 3};
//     ListNode *head = Utils::vector2ListNode(nums);
//     L083RemoveDuplicatesFromSortedList RemoveDuplicates;
//     ListNode *res = RemoveDuplicates.deleteDuplicates(head);
//     Utils::printLink(res);
//     return 0;
// }