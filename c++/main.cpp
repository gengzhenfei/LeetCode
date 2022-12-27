// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "W5306PreAndInOrderBuildBTree.cpp"
#include "W5303BTreePostOrder.cpp"
using namespace std;

int main()
{
    int pre[] = {1, 2, 3};
    int in[] = {1, 3, 2};
    int len = sizeof(pre) / sizeof(pre[0]);
    W5306PreAndInOrderBuildBTree PreAndInOrderBuildBTree;
    TreeNode *root = PreAndInOrderBuildBTree.buildBTreeFromPreAndInOrder(pre, in, len);
    // 借助后序遍历 检测一下二叉树是否正确
    W5303BTreePostOrder BtreePostOrder;
    vector<int> result = BtreePostOrder.postOrder(root);
    cout << "[";
    for (auto i : result) cout << " " << i;
    cout << " ]" << endl;
    return 0;
}