#include <iostream>
#include "L024SwapNodesInPairs.cpp"
using namespace std;

int main()
{
    // 构造测试数据
    vector<int> v{1};
    ListNode *list = Utils::vector2ListNode(v);
    L024SwapNodesInPairs SwapNodesInPairs;
    ListNode *result = SwapNodesInPairs.swapPairs(list);
    Utils::printLink(result);

    return 0;
}