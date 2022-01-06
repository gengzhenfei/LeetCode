#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class L098ValidateBinarySearchTree
{
private:
    /* data */
public:
    L098ValidateBinarySearchTree(/* args */);
    ~L098ValidateBinarySearchTree();

    bool isValidBST(TreeNode *root)
    {
        // return recursValidBST(root);
        return preOrder(root);
    }

    /**
     * 方法一 递归算法
     * 递归判断左右子树是否满足BST
     */
    bool recursValidBST(TreeNode *root, long long min = LLONG_MIN, long long max = LLONG_MAX)
    {
        bool left_tree = true;
        bool right_tree = true;
        // 判断左子树
        if (root->left != nullptr) {
            // 左子树节点大于等于当前节点or小于等于最小值 则不满足BST
            if (root->val <= root->left->val || min >= root->left->val)
                return false;
            else
                left_tree = recursValidBST(root->left, min, root->val);
        }
        // 判断右子树
        if (root->right != nullptr) {
            // 右子树节点小于等于当前节点or大于等于最大值 则不满足BST
            if (root->val >= root->right->val || max <= root->right->val)
                right_tree = false;
            else
                right_tree = recursValidBST(root->right, root->val, max);
        }
        return right_tree && left_tree;
    }

    /**
     * 队列中的树节点结构体，包含该数节点的取值范围，用于判断BST
     */
    struct TreeNodeInQueue {
        long long min;
        long long max;
        TreeNode *node;
        TreeNodeInQueue(long long min, long long max, TreeNode *node) : min(min), max(max), node(node) {}
    };

    /**
     * 方法2 借助队列对二叉树进行 层次遍历
     * 1. 将根节点入队；
     * 2. 从队列中出队一个节点，分别判断该节点的左右子树；
     * 3. 如果左子树不空，则判断左孩子节点是否满足BST，满足，则将左孩子节点入队，否则 return false;
     * 4. 如果右子树不空，判断右孩子节点是否满足BST，满足则将右孩子节点入队，否则 return false;
     * 5. 重复执行2，3，4，直到队列为空或提前return；
     */
    bool isValidBST_2(TreeNode *root)
    {
        long long min = LLONG_MIN, max = LLONG_MAX;
        queue<TreeNodeInQueue *> node_queue;
        // 将root节点重新封装struct之后入队
        TreeNodeInQueue *p = new TreeNodeInQueue(min, max, root);
        node_queue.push(p); // 入队
        // 将队列中节点依次出队处理，直到队列为空
        while (!node_queue.empty()) {
            p = node_queue.front();
            node_queue.pop();
            // 左子树
            if (p->node->left != nullptr) {
                if (p->node->left->val >= p->node->val || p->node->left->val <= p->min) {
                    return false;
                } else {
                    TreeNodeInQueue *q = new TreeNodeInQueue(p->min, p->node->val, p->node->left);
                    node_queue.push(q);
                }
            }
            // 右子树
            if (p->node->right != nullptr) {
                if (p->node->right->val >= p->max || p->node->right->val <= p->node->val) {
                    return false;
                } else {
                    TreeNodeInQueue *q = new TreeNodeInQueue(p->node->val, p->max, p->node->right);
                    node_queue.push(q);
                }
            }
        }

        return true;
    }

    /**
     * 方法3 先序遍历 递归算法
     */
    bool preOrder(TreeNode *root, long long min = LLONG_MIN, long long max = LLONG_MAX)
    {
        if (root == nullptr) return true; // 空节点，true
        if (root->val >= max || root->val <= min) return false; // 非空节点，取值超出 [min, max] 区间， false
        return preOrder(root->left, min, root->val) && preOrder(root->right, root->val, max);
    }

    /**
     * 二叉树的数组存储转为链式存储 用于测试
     */
    TreeNode *array2BTree(vector<string> list, int index = 0)
    {
        // "null" 表示空节点
        if (list[index] == "null") return nullptr;
        // 新建节点
        TreeNode *p = new TreeNode(std::stoi(list[index]));
        int left_n = 2 * index + 1;
        int right_n = 2 * index + 2;
        int v_list = list.size();
        // 左子树
        if (left_n >= v_list) {
            p->left = nullptr;
        } else {
            p->left = array2BTree(list, left_n);
        }
        // 右子树
        if (right_n >= v_list) {
            p->right = nullptr;
        } else {
            p->right = array2BTree(list, right_n);
        }

        return p;
    }
};

L098ValidateBinarySearchTree::L098ValidateBinarySearchTree(/* args */) {}

L098ValidateBinarySearchTree::~L098ValidateBinarySearchTree() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L098ValidateBinarySearchTree.cpp"
// using namespace std;

// int main()
// {
//     // vector<string> list{"3", "1", "5", "0", "2", "4", "6"};
//     // vector<string> list{"2", "1", "3"};
//     vector<string> list{"5", "1", "4", "null", "null", "3", "6"};
//     // vector<string> list{"-2147483648", "null", "2147483647"};
//     L098ValidateBinarySearchTree ValidateBinarySearchTree;
//     TreeNode *root = ValidateBinarySearchTree.array2BTree(list);
//     cout << "true=" << true << "  isValidBST " << ValidateBinarySearchTree.isValidBST(root) << endl;

//     return 0;
// }