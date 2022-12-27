#include "Utils.cpp"
class L099RecoverBinarySearchTree
{
private:
    /* data */
public:
    L099RecoverBinarySearchTree(/* args */);
    ~L099RecoverBinarySearchTree();

    void recoverTree(TreeNode *root)
    {
        bool recover = false;
        findAndRecover(root, recover);
    }

    void findAndRecover(TreeNode *root, bool recover)
    {
        if (recover || root == nullptr) return;
        if (root->left != nullptr) { // 左子树不为空
            if (root->val < root->left->val) { // 情况一 root < left
                swap(root->val, root->left->val);
                recover = true;
                return;
            } else {
                if (root->left->right != nullptr && root->val < root->left->right->val) {
                    // 情况三 root < left->right
                    swap(root->val, root->left->right->val);
                    recover = true;
                    return;
                }
            }
        }
        if (root->right != nullptr) { // 右子树不为空
            if (root->val > root->right->val) { // 情况二 root>right
                swap(root->val, root->right->val);
                recover = true;
                return;
            } else {
                if (root->right->left != nullptr && root->val > root->right->left->val) {
                    // 情况四 root > right->left
                    swap(root->val, root->right->left->val);
                    recover = true;
                    return;
                }
            }
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
};

L099RecoverBinarySearchTree::L099RecoverBinarySearchTree(/* args */) {}

L099RecoverBinarySearchTree::~L099RecoverBinarySearchTree() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L099RecoverBinarySearchTree.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"1", "3", "null", "null", "2"};
//     TreeNode *root = Utils::array2BTree(list);
//     L099RecoverBinarySearchTree RecoverBinarySearchTree;
//     RecoverBinarySearchTree.recoverTree(root);

//     return 0;
// }