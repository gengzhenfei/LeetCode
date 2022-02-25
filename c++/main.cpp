// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L094BinaryTreeInorderTraversal.cpp"
using namespace std;

int main()
{
    vector<string> list{"1", "null", "2"};
    TreeNode *root = Utils::array2BTree(list);
    L094BinaryTreeInorderTraversal BinaryTreeInorderTraversal;
    vector<int> res = BinaryTreeInorderTraversal.inorderTraversal(root);
    for (int i : res) cout << i << endl;
    return 0;
}