#include "Utils.cpp"
#include <queue>

class W5304BTreeDownUpLevelOrder
{
private:
    /* data */
public:
    W5304BTreeDownUpLevelOrder(/* args */);
    ~W5304BTreeDownUpLevelOrder();

    /**
     * 算法思路：
     * 对二叉树的自下而上从右到左的顺序遍历，相当于对二叉树的层序遍历结果的逆序
     * 因此，借助一个队列和一个栈对二叉树进行层序遍历
     */
    vector<int> downUpLevelOrder(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr) return res;
        vector<int> st;
        queue<TreeNode *> node_queue;
        TreeNode *p = root;
        node_queue.push(p);
        while (!node_queue.empty()) { // 队列中节点依次出队并将非空孩子节点入队
            p = node_queue.front();
            node_queue.pop();
            st.push_back(p->val); // 节点访问并入栈
            if (p->left != nullptr) node_queue.push(p->left);
            if (p->right != nullptr) node_queue.push(p->right);
        }
        while (!st.empty()) { // 依次出栈 即可实现 自下而上 从右到左
            res.push_back(st.back());
            st.pop_back();
        }

        return res;
    }
};

W5304BTreeDownUpLevelOrder::W5304BTreeDownUpLevelOrder(/* args */) {}

W5304BTreeDownUpLevelOrder::~W5304BTreeDownUpLevelOrder() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "W5304BTreeDownUpLevelOrder.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"1", "2", "3", "null", "4", "null", "5", "null", "null", "6"};
//     TreeNode *root = Utils::array2BTree(list);
//     W5304BTreeDownUpLevelOrder BTreeDownUpLevelOrder;
//     vector<int> result = BTreeDownUpLevelOrder.downUpLevelOrder(root);
//     cout << "[";
//     for (auto i : result) cout << " " << i;
//     cout << " ]" << endl;
//     return 0;
// }