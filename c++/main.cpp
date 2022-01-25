// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L199BinaryTreeRightSideView.cpp"
using namespace std;

int main()
{
    vector<string> list{"1", "2", "3", "null", "5", "null", "4"};
    TreeNode *root = Utils::array2BTree(list);
    L199BinaryTreeRightSideView BinaryTreeRightSideView;
    vector<int> res = BinaryTreeRightSideView.rightSideView(root);
    for (auto v : res) { cout << v << endl; }
    return 0;
}