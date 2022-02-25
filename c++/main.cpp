// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L092ReverseLinkedList2.cpp"
using namespace std;

int main()
{
    vector<int> list{1, 2, 3, 4, 5};
    int left = 4, right = 5;
    ListNode *head = Utils::vector2ListNode(list);
    L092ReverseLinkedList2 ReverseLinkedList2;
    ListNode *res = ReverseLinkedList2.reverseBetween(head, left, right);
    Utils::printLink(res);
    return 0;
}