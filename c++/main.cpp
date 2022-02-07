// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L061RotateList.cpp"
using namespace std;

int main()
{
    vector<int> list{0, 1, 2};
    int k = 4;
    ListNode *head = Utils::vector2ListNode(list);
    L061RotateList RotateList;
    ListNode *node = RotateList.rotateRight(head, k);
    Utils::printLink(node);
    return 0;
}