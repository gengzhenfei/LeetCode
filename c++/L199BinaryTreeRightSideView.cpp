#include "Utils.cpp"
#include <queue>
using namespace std;

class L199BinaryTreeRightSideView
{
private:
    /* data */
public:
    L199BinaryTreeRightSideView(/* args */);
    ~L199BinaryTreeRightSideView();

    /**
     * 二叉树的层次遍历
     */
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> q;
        if (root != nullptr) {
            q.push(root);
            while (!q.empty()) {
                int len = q.size();
                TreeNode *root = nullptr;
                for (int i = 0; i < len; i++) {
                    root = q.front();
                    q.pop();
                    if (root->left != nullptr) q.push(root->left);
                    if (root->right != nullptr) q.push(root->right);
                }
                res.push_back(root->val); // 层次的最后一个节点
            }
        }

        return res;
    }
};

L199BinaryTreeRightSideView::L199BinaryTreeRightSideView(/* args */) {}

L199BinaryTreeRightSideView::~L199BinaryTreeRightSideView() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L199BinaryTreeRightSideView.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"1", "2", "3", "null", "5", "null", "4"};
//     TreeNode *root = Utils::array2BTree(list);
//     L199BinaryTreeRightSideView BinaryTreeRightSideView;
//     vector<int> res = BinaryTreeRightSideView.rightSideView(root);
//     for (auto v : res) { cout << v << endl; }
//     return 0;
// }