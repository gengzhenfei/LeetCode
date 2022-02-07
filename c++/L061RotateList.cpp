#include "Utils.cpp"

class L061RotateList
{
private:
    /* data */
public:
    L061RotateList(/* args */);
    ~L061RotateList();

    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = 0; // 链表长度
        ListNode *p = head, *pre = head;
        while (p != nullptr) { // 计算链表长度
            len++;
            p = p->next;
        }
        if (len == 0) return head; // 特殊情况
        int pos = len - (k % len); // 旋转链表的位置
        p = head;
        while (pos > 0) { // 从头节点开始向后遍历 直到旋转链表位置
            pre = p;
            p = p->next;
            pos--;
        }
        if (p != nullptr) { // 后续节点非空 则做旋转处理
            pre->next = nullptr;
            ListNode *h = head; // 记下原先头节点
            head = p; // 新的头节点
            while (p != nullptr) {
                pre = p;
                p = p->next;
            }
            pre->next = h;
        }
        return head;
    }
};

L061RotateList::L061RotateList(/* args */) {}

L061RotateList::~L061RotateList() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L061RotateList.cpp"
// using namespace std;

// int main()
// {
//     vector<int> list{};
//     int k = 0;
//     ListNode *head = Utils::vector2ListNode(list);
//     L061RotateList RotateList;
//     ListNode *node = RotateList.rotateRight(head, k);
//     Utils::printLink(node);
//     return 0;
// }