#include "Utils.cpp"

class W5305BTreeHeight
{
private:
    /* data */
public:
    W5305BTreeHeight(/* args */);
    ~W5305BTreeHeight();

    int height(TreeNode *root)
    {
        int h = 0;
        // 递归算法
        // anyOrder(root, h, 1);
        // 非递归算法
        postOrder(root, h);

        return h;
    }

    /**
     * 递归算法
     * @param TreeNode *root
     * @param int &h 当前已访问子树最大高度
     * @param int deep 当前节点高度
     */
    void anyOrder(TreeNode *root, int &h, int deep = 1)
    {
        if (root == nullptr) return;
        h = max(h, deep);
        anyOrder(root->left, h, deep + 1);
        anyOrder(root->right, h, deep + 1);
    }

    /**
     * 非递归算法
     * 借助后序遍历非递归算法，当访问叶子节点的时候，栈中元素个数即为树高。
     * 取所有叶子节点的高度中最大值即为树高
     */
    void postOrder(TreeNode *root, int &h)
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
                    h = max(h, st.size()); // 更新树高
                    pre = p; // 更新当前节点为前一个被访问的节点
                    st.pop_back(); // 栈顶节点出栈
                }
            }
        }
    }

    int max(int a, int b)
    {
        return (a < b) ? b : a;
    }
};

W5305BTreeHeight::W5305BTreeHeight(/* args */) {}

W5305BTreeHeight::~W5305BTreeHeight() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "W5305BTreeHeight.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"1", "2", "3", "null", "4", "5", "6", "null", "null", "null", "null", "null", "null", "7"};
//     TreeNode *root = Utils::array2BTree(list);
//     W5305BTreeHeight BTreeHeight;
//     int result = BTreeHeight.height(root);
//     cout << result << endl;
//     return 0;
// }