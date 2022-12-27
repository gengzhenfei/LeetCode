#include "Utils.cpp"

class W5306PreAndInOrderBuildBTree
{
private:
    /* data */
public:
    W5306PreAndInOrderBuildBTree(/* args */);
    ~W5306PreAndInOrderBuildBTree();

    TreeNode *buildBTreeFromPreAndInOrder(int pre[], int in[], int len)
    {
        if (len == 0) return nullptr;
        TreeNode *root = new TreeNode(pre[0]);
        int index = indexOf(in, 0, len - 1, pre[0]);
        buildBTree(root, TAG_LEFT, pre, 1, index, in, 0, index - 1);
        buildBTree(root, TAG_RIGHT, pre, index + 1, len - 1, in, index + 1, len - 1);

        return root;
    }

    // 常量
    static const int TAG_LEFT = 0;
    static const int TAG_RIGHT = 1;

    /**
     * 根据先序遍历和中序遍历序列生成二叉树
     * 思路：
     * 类似二分法，递归执行，每次递归缩小范围
     * @param TreeNode* root
     * @param int tag 标记当前子树属于父节点的左or右孩子 0左 1右
     * @param int pre[] 先序遍历序列
     * @param int p1 先序开始索引
     * @param int p2 先序结束索引
     * @param int in[] 后序遍历序列
     * @param int i1 后序开始索引
     * @param int i2 后序结束索引
     */
    void buildBTree(TreeNode *root, int tag, int pre[], int p1, int p2, int in[], int i1, int i2)
    {
        if (p1 <= p2 && p2 - p1 == i2 - i1) { // pre 和 in 序列长度相等且长度大于0
            TreeNode *node = new TreeNode(pre[p1]); // 新建节点
            tag == TAG_LEFT ? root->left = node : root->right = node;
            int index = indexOf(in, i1, i2, pre[p1]); // 该子树根节点在中序中索引
            buildBTree(node, TAG_LEFT, pre, p1 + 1, p1 + index - i1, in, i1, index - 1);
            buildBTree(node, TAG_RIGHT, pre, p1 + index - i1 + 1, p2, in, index + 1, i2);
        } else {
            tag == TAG_LEFT ? root->left = nullptr : root->right = nullptr;
        }
    }

    int indexOf(int arr[], int a1, int a2, int val)
    {
        for (int i = a1; i <= a2; i++) {
            if (arr[i] == val) return i;
        }
        return -1;
    }
};

W5306PreAndInOrderBuildBTree::W5306PreAndInOrderBuildBTree(/* args */) {}

W5306PreAndInOrderBuildBTree::~W5306PreAndInOrderBuildBTree() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "W5306PreAndInOrderBuildBTree.cpp"
// #include "W5303BTreePostOrder.cpp"
// using namespace std;

// int main()
// {
//     int pre[] = {1, 2, 3};
//     int in[] = {1, 3, 2};
//     int len = sizeof(pre) / sizeof(pre[0]);
//     W5306PreAndInOrderBuildBTree PreAndInOrderBuildBTree;
//     TreeNode *root = PreAndInOrderBuildBTree.buildBTreeFromPreAndInOrder(pre, in, len);
//     // 借助后序遍历 检测一下二叉树是否正确
//     W5303BTreePostOrder BtreePostOrder;
//     vector<int> result = BtreePostOrder.postOrder(root);
//     cout << "[";
//     for (auto i : result) cout << " " << i;
//     cout << " ]" << endl;
//     return 0;
// }