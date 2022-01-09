#include "Utils.cpp"

class L025ReverseNodesInKGroup
{
private:
    /* data */
public:
    L025ReverseNodesInKGroup(/* args */);
    ~L025ReverseNodesInKGroup();

    /**
     * 使用vector缓存k个链表节点
     * LeetCode 执行结果：
     * 执行用时：8 ms, 在所有 C++ 提交中击败了98.37%的用户
     * 内存消耗：11.4 MB, 在所有 C++ 提交中击败了9.21%的用户
     * 通过测试用例：62 / 62
     *
     * 使用内置数组缓存k个链表节点
     * LeetCode 执行结果：
     * 执行用时：12 ms, 在所有 C++ 提交中击败了88.39%的用户
     * 内存消耗：11.2 MB, 在所有 C++ 提交中击败了62.06%的用户
     * 通过测试用例：62 / 62
     */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k <= 1 || head == nullptr || head->next == nullptr) return head;
        // vector<ListNode *> v; // 使用vector容器
        ListNode *v[k]; // 使用内置数组
        ListNode *p = head, *pre;

        // step1. 处理前k个节点翻转
        int i = 0;
        for (; i < k; i++) {
            if (p != nullptr) // 非空节点 存入容器
                // v.push_back(p);
                v[i] = p;
            else // 空节点，则说明不够k个，直接返回
                return head;
            p = p->next;
        }
        head = v[i - 1]; // head设置为第k个节点
        v[0]->next = v[k - 1]->next; // 第一个节点next指向第k个节点的next
        for (i = 1; i < k; i++) v[i]->next = v[i - 1]; // 翻转前k个节点
        pre = v[0];
        p = pre->next; // p指向下一轮k个节点的第一个节点
        // v.clear(); // 容器清空

        // step2. 处理后续节点翻转，每组k个，不足k个则不进行翻转
        while (p != nullptr) {
            for (i = 0; i < k; i++) {
                if (p != nullptr) // 非空节点 存入容器
                    // v.push_back(p);
                    v[i] = p;
                else // 空节点，则说明不够k个，直接返回
                    return head;
                p = p->next;
            }
            pre->next = v[k - 1]; // 前一组里第k个节点next指向这一组的第k个元素
            v[0]->next = v[k - 1]->next; // 第一个节点next指向第k个节点的next
            for (i = 1; i < k; i++) v[i]->next = v[i - 1]; // 翻转前k个节点
            pre = v[0];
            p = pre->next; // p指向下一轮k个节点的第一个节点
            // v.clear(); // 容器清空
        }
        return head;
    }
};

L025ReverseNodesInKGroup::L025ReverseNodesInKGroup(/* args */) {}

L025ReverseNodesInKGroup::~L025ReverseNodesInKGroup() {}

// #include <iostream>
// #include "L025ReverseNodesInKGroup.cpp"
// using namespace std;

// int main()
// {
//     // 构造测试数据
//     vector<int> v{1, 2, 3, 4, 5};
//     int k = 2;
//     ListNode *list = Utils::vector2ListNode(v);
//     L025ReverseNodesInKGroup ReverseNodesInKGrou;
//     ListNode *result = ReverseNodesInKGrou.reverseKGroup(list, k);
//     Utils::printLink(result);

//     return 0;
// }