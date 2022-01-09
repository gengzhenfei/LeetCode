#include "Utils.cpp"

class L024SwapNodesInPairs
{
private:
    /* data */
public:
    L024SwapNodesInPairs(/* args */);
    ~L024SwapNodesInPairs();

    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        // 先处理前两个节点
        ListNode *p = head, *q = head->next, *pre;
        p->next = q->next;
        q->next = p;
        head = q;
        pre = p;
        p = p->next;
        while (p != nullptr) {
            if (p->next == nullptr) return head;
            q = p->next;
            pre->next = q;
            p->next = q->next;
            q->next = p;
            pre = p;
            p = p->next;
        }
        return head;
    }
};

L024SwapNodesInPairs::L024SwapNodesInPairs(/* args */) {}

L024SwapNodesInPairs::~L024SwapNodesInPairs() {}

// #include <iostream>
// #include "L024SwapNodesInPairs.cpp"
// using namespace std;

// int main()
// {
//     // 构造测试数据
//     vector<int> v{1};
//     ListNode *list = Utils::vector2ListNode(v);
//     L024SwapNodesInPairs SwapNodesInPairs;
//     ListNode *result = SwapNodesInPairs.swapPairs(list);
//     Utils::printLink(result);

//     return 0;
// }