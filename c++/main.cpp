#include <iostream>
#include "L023MergeKSortedLists.cpp"
using namespace std;

int main()
{
    // 构造测试数据
    vector<vector<int>> v{{1, 4, 5}, {1, 3, 4}};
    vector<ListNode *> lists{};
    for (auto i : v) { lists.push_back(Utils::vector2ListNode(i)); }
    L023MergeKSortedLists MergeKSortedLists;
    ListNode *result = MergeKSortedLists.mergeKLists(lists);
    Utils::printLink(result);

    return 0;
}