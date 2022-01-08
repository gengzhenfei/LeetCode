#include "Utils.cpp"

class L021MergeTwoSortedLists
{
private:
    /* data */
public:
    L021MergeTwoSortedLists(/* args */);
    ~L021MergeTwoSortedLists();

    /**
     * 新建链表节点 空间复杂度O(m+n)
     * LeetCode 执行结果
     *  执行用时：8 ms, 在所有 C++ 提交中击败了63.07%的用户
     *  内存消耗：14.6 MB, 在所有 C++ 提交中击败了6.51%的用户
     *  通过测试用例：208 / 208
     */
    // ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    // {
    //     ListNode *head, *p;
    //     if (list1 == nullptr) return list2;
    //     if (list2 == nullptr) return list1;
    //     if (list1->val < list2->val) {
    //         head = p = new ListNode(list1->val);
    //         list1 = list1->next;
    //     } else {
    //         head = p = new ListNode(list2->val);
    //         list2 = list2->next;
    //     }
    //     while (list1 != nullptr && list2 != nullptr) {
    //         if (list1->val < list2->val) {
    //             p->next = new ListNode(list1->val);
    //             p = p->next;
    //             list1 = list1->next;
    //         } else {
    //             p->next = new ListNode(list2->val);
    //             p = p->next;
    //             list2 = list2->next;
    //         }
    //     }
    //     // 以下两个 while 只会执行一个
    //     while (list1 != nullptr) {
    //         p->next = new ListNode(list1->val);
    //         p = p->next;
    //         list1 = list1->next;
    //     }
    //     while (list2 != nullptr) {
    //         p->next = new ListNode(list2->val);
    //         p = p->next;
    //         list2 = list2->next;
    //     }

    //     return head;
    // }

    /**
     * 直接修改原链表 空间复杂度为O(1)
     * LeetCode 执行结果
     *  执行用时：8 ms, 在所有 C++ 提交中击败了63.07%的用户
     *  内存消耗：14.3 MB, 在所有 C++ 提交中击败了90.40%的用户
     *  通过测试用例：208 / 208
     */
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head, *p;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val < list2->val) {
            head = p = list1;
            list1 = list1->next;
        } else {
            head = p = list2;
            list2 = list2->next;
        }
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        // 以下两个 if 只会执行一个
        if (list1 != nullptr) { p->next = list1; }
        if (list2 != nullptr) { p->next = list2; }

        return head;
    }
};

L021MergeTwoSortedLists::L021MergeTwoSortedLists(/* args */) {}

L021MergeTwoSortedLists::~L021MergeTwoSortedLists() {}

// #include <iostream>
// #include "L021MergeTwoSortedLists.cpp"
// using namespace std;

// int main()
// {
//     vector<int> v1{1, 2, 4};
//     vector<int> v2{1, 3, 4};
//     ListNode *list1 = Utils::vector2ListNode(v1);
//     ListNode *list2 = Utils::vector2ListNode(v2);
//     L021MergeTwoSortedLists MergeTwoSortedLists;
//     ListNode *result = MergeTwoSortedLists.mergeTwoLists(list1, list2);
//     Utils::printLink(result);

//     return 0;
// }