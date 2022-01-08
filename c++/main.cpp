#include <iostream>
#include "L021MergeTwoSortedLists.cpp"
using namespace std;

int main()
{
    vector<int> v1{1, 2, 4};
    vector<int> v2{1, 3, 4};
    ListNode *list1 = Utils::vector2ListNode(v1);
    ListNode *list2 = Utils::vector2ListNode(v2);
    L021MergeTwoSortedLists MergeTwoSortedLists;
    ListNode *result = MergeTwoSortedLists.mergeTwoLists(list1, list2);
    Utils::printLink(result);

    return 0;
}