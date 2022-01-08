#include <vector>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class L019RemoveNthNodeFromEndOfList
{
private:
    /* data */
public:
    L019RemoveNthNodeFromEndOfList(/* args */);
    ~L019RemoveNthNodeFromEndOfList();

    /**
     * 能尝试使用一趟扫描实现吗？当然能，空间换取时间
     * LeetCode 执行结果
     * 执行用时：4 ms, 在所有 C++ 提交中击败了76.31%的用户
     * 内存消耗：10.4 MB, 在所有 C++ 提交中击败了57.93%的用户
     * 通过测试用例：208 / 208
     */
    // ListNode *removeNthFromEnd(ListNode *head, int n)
    // {
    //     vector<ListNode *> v_node; // 链表的每个节点都存放到数组中
    //     ListNode *p = head;
    //     while (p != nullptr) {
    //         v_node.push_back(p);
    //         p = p->next;
    //     }
    //     int v_len = v_node.size();
    //     if (v_len - n == 0) { // 删除头节点
    //         p = head;
    //         head = head->next;
    //         // delete p; // ？？？不能用delete释放空间吗？why
    //     } else if (v_len - n > 0) { // 删除非头节点
    //         p = v_node[v_len - n];
    //         ListNode *pre = v_node[v_len - n - 1];
    //         pre->next = pre->next->next;
    //         // delete p; // ？？？不能用delete释放空间吗？why
    //     }

    //     return head;
    // }

    /**
     * 两趟遍历
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head, *pre = head;
        int len = 0; // 统计链表长度
        for (; p != nullptr; len++) { p = p->next; }
        // 删除头节点
        if (n == len) {
            head = head->next;
        } else {
            // 寻找被删除节点的前一个节点
            for (int i = 0; i < len - n - 1; i++) { pre = pre->next; }
            // 删除非头节点
            pre->next = pre->next->next;
        }
        return head;
    }

    /**
     * 数组转单链表
     */
    ListNode *array2ListNode(vector<int> v)
    {
        int v_len = v.size();
        if (v_len == 0) { return nullptr; }
        ListNode *head = new ListNode(v[0]); // 头节点初始化
        ListNode *p = head;
        for (int i = 1; i < v_len; i++) {
            p->next = new ListNode(v[i]);
            p = p->next;
        }

        return head;
    }
};

L019RemoveNthNodeFromEndOfList::L019RemoveNthNodeFromEndOfList(/* args */) {}

L019RemoveNthNodeFromEndOfList::~L019RemoveNthNodeFromEndOfList() {}

// #include <iostream>
// #include "L019RemoveNthNodeFromEndOfList.cpp"
// using namespace std;

// int main()
// {
//     vector<int> v{1, 2, 3, 4, 5};
//     int n = 2;
//     L019RemoveNthNodeFromEndOfList RemoveNthNodeFromEndOfList;
//     ListNode *head = RemoveNthNodeFromEndOfList.array2ListNode(v);
//     head = RemoveNthNodeFromEndOfList.removeNthFromEnd(head, n);
//     // 打印链表
//     ListNode *p = head;
//     while (p != nullptr) {
//         cout << p->val << endl;
//         p = p->next;
//     }

//     return 0;
// }