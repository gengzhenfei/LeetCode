#include "Utils.cpp"

class W5303BTreePostOrder
{
private:
    /* data */
public:
    W5303BTreePostOrder(/* args */);
    ~W5303BTreePostOrder();

    vector<int> postOrder(TreeNode *root)
    {
        vector<int> res;
        // 递归算法
        // recursion(root, res);
        // 非递归算法
        nonRecursion(root, res);

        return res;
    }

    /**
     * 递归算法
     */
    void recursion(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr) return;
        recursion(root->left, res); // 左子树
        recursion(root->right, res); // 右子树
        res.push_back(root->val); // 访问
    }

    /**
     * 非递归算法
     * 二叉树的后序遍历非递归算法思路与中序遍历非递归算法思路相似
     * 区别在于，栈顶节点的处理不同：
     * 中序遍历时，栈顶元素出栈并访问，接着对栈顶节点右孩子访问；
     * 后序遍历时，若栈顶节点右孩子为null或前一个访问的节点是其右孩子，则出栈并访问该节点；
     * 否则接着对右孩子访问。
     * 因此，后序遍历非递归算法借助pre指针指向前一个访问的节点。
     */
    void nonRecursion(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr) return;
        TreeNode *pre = nullptr, *p = root;
        vector<TreeNode *> st; // 栈
        st.push_back(p);
        p = p->left;
        while (!st.empty()) {
            while (p != nullptr) { // 左节点入栈 直到左节点为null
                st.push_back(p);
                p = p->left;
            }
            while (!st.empty()) {
                p = st.back(); // 栈顶元素
                if (p->right != nullptr && pre != p->right) { // 右节点未被访问
                    p = p->right;
                    break;
                } else { // 右节点未空或已被访问
                    pre = p; // 更新当前节点为前一个被访问的节点
                    st.pop_back(); // 栈顶节点出栈
                    res.push_back(p->val); // 输出当前节点
                }
            }
        }
    }
};

W5303BTreePostOrder::W5303BTreePostOrder(/* args */) {}

W5303BTreePostOrder::~W5303BTreePostOrder() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "W5303BTreePostOrder.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"1", "null", "2", "3"};
//     TreeNode *root = Utils::array2BTree(list);
//     W5303BTreePostOrder BtreePostOrder;
//     vector<int> result = BtreePostOrder.postOrder(root);
//     cout << "[";
//     for (auto i : result) cout << " " << i;
//     cout << " ]" << endl;
//     return 0;
// }