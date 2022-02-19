// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L083RemoveDuplicatesFromSortedList.cpp"
using namespace std;

int main()
{
    vector<int> nums{1, 1, 1, 2, 2, 3};
    ListNode *head = Utils::vector2ListNode(nums);
    L083RemoveDuplicatesFromSortedList RemoveDuplicates;
    ListNode *res = RemoveDuplicates.deleteDuplicates(head);
    Utils::printLink(res);
    return 0;
}