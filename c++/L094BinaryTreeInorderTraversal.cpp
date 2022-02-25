#include "Utils.cpp"

class L094BinaryTreeInorderTraversal
{
private:
    /* data */
public:
    L094BinaryTreeInorderTraversal(/* args */);
    ~L094BinaryTreeInorderTraversal();

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        // recurse(root, res);
        nonRecurse(root, res);

        return res;
    }

    /**
     * 递归
     */
    void recurse(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr) return;
        recurse(root->left, res); // 左子树
        res.push_back(root->val); // 访问
        recurse(root->right, res); // 右子树
    }

    /**
     * 非递归
     */
    void nonRecurse(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr) return;
        vector<TreeNode *> st; // 栈
        TreeNode *p = root;
        st.push_back(p);
        p = p->left;
        while (!st.empty() || p != nullptr) { // 栈非空or指针节点不空
            if (p != nullptr) {
                cout << "p:" << p->val << endl;
                st.push_back(p);
                p = p->left;
            } else {
                cout << "st.back:" << st.back()->val << endl;
                res.push_back(st.back()->val); // 访问栈顶节点
                p = st.back()->right; // 栈顶节点的右子树
                st.pop_back(); // 栈顶元素出栈
            }
        }

        return;
    }
};

L094BinaryTreeInorderTraversal::L094BinaryTreeInorderTraversal(/* args */) {}

L094BinaryTreeInorderTraversal::~L094BinaryTreeInorderTraversal() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L094BinaryTreeInorderTraversal.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"1", "null", "2"};
//     TreeNode *root = Utils::array2BTree(list);
//     L094BinaryTreeInorderTraversal BinaryTreeInorderTraversal;
//     vector<int> res = BinaryTreeInorderTraversal.inorderTraversal(root);
//     for (int i : res) cout << i << endl;
//     return 0;
// }