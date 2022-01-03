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

class L002AddTwoNumbers
{
private:
    /* data */
public:
    L002AddTwoNumbers(/* args */);
    ~L002AddTwoNumbers();

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int addFlag = 0;
        ListNode *p1 = l1, *p2 = l2, *p3, *l3;
        // 头节点，处理最低位
        l3 = p3 = new ListNode(addFlag);
        if (p1 != nullptr) {
            p3->val += p1->val;
            p1 = p1->next;
        }
        if (p2 != nullptr) {
            p3->val += p2->val;
            p2 = p2->next;
        }
        // 判断两位之和是否有进位
        if (p3->val / 10 > 0) {
            addFlag = p3->val / 10;
            p3->val = p3->val % 10;
        }
        // 循环处理后续位相加
        while (p1 != nullptr || p2 != nullptr) {
            p3->next = new ListNode(addFlag);
            p3 = p3->next;
            if (p1 != nullptr) {
                p3->val += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                p3->val += p2->val;
                p2 = p2->next;
            }
            // 判断两位之和是否有进位
            addFlag = p3->val / 10;
            if (addFlag > 0) p3->val = p3->val % 10;
        }
        // 最高位有进位
        if (addFlag != 0) p3->next = new ListNode(addFlag);

        return l3;
    }

    // 数组转链表 用于构造测试用例
    ListNode *array2Link(int arr[], int len)
    {
        ListNode *l1, *p1;
        l1 = p1 = new ListNode();
        p1->val = arr[0];
        for (int i = 1; i < len; i++) {
            p1->next = new ListNode();
            p1 = p1->next;
            p1->val = arr[i];
        }
        return l1;
    }

    // 打印链表 用于测试打印链表
    void printLink(ListNode *head)
    {
        while (head != nullptr) {
            cout << head->val << endl;
            head = head->next;
        }
    }
};

L002AddTwoNumbers::L002AddTwoNumbers(/* args */) {}

L002AddTwoNumbers::~L002AddTwoNumbers() {}

// main.cpp
// 调试时将下列代码放入main.cpp文件

// #include <iostream>
// #include "L002AddTwoNumbers.cpp"
// using namespace std;
// int main()
// {
//     // 002 add two numbers
//     // 测试数组
//     int arr1[] = {2, 4, 3};
//     int arr2[] = {5, 6, 4};
//     // int arr1[] = {9, 9, 9, 9, 9, 9, 9};
//     // int arr2[] = {9, 9, 9, 9};
//     L002AddTwoNumbers AddTwoNumbers;
//     // 数组转为链表
//     ListNode *l1 = AddTwoNumbers.array2Link(arr1, sizeof(arr1) / sizeof(arr1[0]));
//     ListNode *l2 = AddTwoNumbers.array2Link(arr2, sizeof(arr2) / sizeof(arr2[0]));
//     // 相加
//     ListNode *l3 = AddTwoNumbers.addTwoNumbers(l1, l2);
//     AddTwoNumbers.printLink(l3);

//     return 0;
// }