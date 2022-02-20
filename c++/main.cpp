// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L086PartitionList.cpp"
using namespace std;

int main()
{
    vector<int> nums{1, 4, 3, 2, 5, 2};
    int x = 3;
    ListNode *head = Utils::vector2ListNode(nums);
    L086PartitionList PartitionList;
    ListNode *res = PartitionList.partition(head, x);
    Utils::printLink(res);
    return 0;
}