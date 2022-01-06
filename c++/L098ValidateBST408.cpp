#include <vector>
#include <climits>
using namespace std;

// 2022年考研计算机408专业课真题：
// 二叉树节点的结构如下：
// typedef struct {
//     int data[MaxSize];
//     int num;
// } Sqlist;
// 用数组保存二叉树，每个节点保存正整数，空节点的值为-1，设计一个高效的算法，判断二叉树为二叉搜索树。

struct TreeList {
    vector<int> data; // 此处为了方便使用vector容器
    int num;
    TreeList() : data(), num() {}
    TreeList(vector<int> data, int num) : data(data), num(num) {}
};

class L098ValidateBST408
{
private:
    /* data */
public:
    L098ValidateBST408(/* args */);
    ~L098ValidateBST408();

    bool isBST(TreeList *list)
    {
        // 方法1
        // inOrder(list, 0);
        // return T;

        // 方法2
        return preOrder(list);
    }

    /**
     * 方法1 王道提供的答案解析， 中序递归
     * 我感觉这个思路有点问题，运行下来的结果也不正确
     */
    bool T = true;
    int k = 0;
    void inOrder(TreeList *list, int i = 0)
    {
        if (i >= list->num || list->data[i] == -1) return;
        inOrder(list, i * 2 + 1); // 左子树
        if (k > list->data[i * 2 + 1]) {
            T = false;
            return;
        }
        k = list->data[i * 2 + 2];
        inOrder(list, i * 2 + 2);
    }

    /**
     * 方法2 先序遍历，递归算法
     * 二叉树的非空节点为正整数，空节点为-1占位，故取值范围 0～INT_MAX
     */
    bool preOrder(TreeList *list, int i = 0, int min = 0, int max = INT_MAX)
    {
        if (i >= list->num || list->data[i] == -1) return true; // 空节点
        if (list->data[i] < min || list->data[i] > max) return false; // 超出范围 不符合BST
        bool left = preOrder(list, i * 2 + 1, min, list->data[i]); // 左子树
        bool right = preOrder(list, i * 2 + 2, list->data[i], max); // 右子树
        return left && right;
    }
};

L098ValidateBST408::L098ValidateBST408(/* args */) {}

L098ValidateBST408::~L098ValidateBST408() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L098ValidateBinarySearchTree.cpp"
// #include "L098ValidateBST408.cpp"
// using namespace std;

// int main()
// {
//     // vector<string> list{"3", "1", "5", "0", "2", "4", "6"};
//     // vector<string> list{"2", "1", "3"};
//     vector<string> list{"5", "1", "4", "null", "null", "3", "6"};
//     // vector<string> list{"-2147483648", "null", "2147483647"};
//     L098ValidateBinarySearchTree ValidateBinarySearchTree;
//     TreeNode *root = ValidateBinarySearchTree.array2BTree(list); // 二叉树的数组结构转为链式存储
//     cout << "true=" << true << "  isValidBST " << ValidateBinarySearchTree.isValidBST(root) << endl;

//     // 408题目测试 二叉树存储在数组中
//     // vector<int> v_list{3, 1, 5, 0, 2, 4, 6};
//     // vector<int> v_list{2, 1, 3};
//     vector<int> v_list{5, 1, 4, -1, -1, 3, 6};
//     int list_len = v_list.size();
//     TreeList *t_list = new TreeList(v_list, list_len);
//     L098ValidateBST408 ValidateBST408;
//     cout << "true=" << true << "  isBST " << ValidateBST408.isBST(t_list) << endl;

//     return 0;
// }