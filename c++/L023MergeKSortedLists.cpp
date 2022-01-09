#include "Utils.cpp"

class L023MergeKSortedLists
{
private:
    /* data */
public:
    L023MergeKSortedLists(/* args */);
    ~L023MergeKSortedLists();

    /**
     * 两两合并，知道最后就剩一个链表 类似归并排序
     */
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> tmp;
        int v_len = lists.size();
        if (v_len == 0) return nullptr; // 等于0 返回null
        while (v_len > 1) {
            // cout << "v_len " << v_len << endl;
            int i = 0;
            ListNode *l1 = nullptr;
            ListNode *l2 = nullptr;
            while (i < v_len) {
                l1 = lists[i++];
                if (i < v_len) {
                    l2 = lists[i++];
                    // cout << "mergeTwoLists(l1, l2)" << endl;
                    // Utils::printLink(mergeTwoLists(l1, l2));
                    tmp.push_back(mergeTwoLists(l1, l2));
                } else {
                    tmp.push_back(l1);
                }
            }
            // cout << "tmp len " << tmp.size() << endl;
            lists = tmp;
            tmp.clear(); // 清空临时容器
            v_len = lists.size();
        }

        return lists[0];
    }

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

L023MergeKSortedLists::L023MergeKSortedLists(/* args */) {}

L023MergeKSortedLists::~L023MergeKSortedLists() {}

// #include <iostream>
// #include "L023MergeKSortedLists.cpp"
// using namespace std;

// int main()
// {
//     // 构造测试数据
//     vector<vector<int>> v{{1, 4, 5}, {1, 3, 4}};
//     vector<ListNode *> lists{};
//     for (auto i : v) { lists.push_back(Utils::vector2ListNode(i)); }
//     L023MergeKSortedLists MergeKSortedLists;
//     ListNode *result = MergeKSortedLists.mergeKLists(lists);
//     Utils::printLink(result);

//     return 0;
// }