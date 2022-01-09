#include <iostream>
#include "L025ReverseNodesInKGroup.cpp"
using namespace std;

int main()
{
    // 构造测试数据
    vector<int> v{1, 2, 3, 4, 5};
    int k = 2;
    ListNode *list = Utils::vector2ListNode(v);
    L025ReverseNodesInKGroup ReverseNodesInKGrou;
    ListNode *result = ReverseNodesInKGrou.reverseKGroup(list, k);
    Utils::printLink(result);

    return 0;
}