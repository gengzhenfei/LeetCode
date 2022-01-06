#include <iostream>
#include <string>
#include <vector>
#include "L098ValidateBinarySearchTree.cpp"
#include "L098ValidateBST408.cpp"
using namespace std;

int main()
{
    // vector<string> list{"3", "1", "5", "0", "2", "4", "6"};
    // vector<string> list{"2", "1", "3"};
    vector<string> list{"5", "1", "4", "null", "null", "3", "6"};
    // vector<string> list{"-2147483648", "null", "2147483647"};
    L098ValidateBinarySearchTree ValidateBinarySearchTree;
    TreeNode *root = ValidateBinarySearchTree.array2BTree(list); // 二叉树的数组结构转为链式存储
    cout << "true=" << true << "  isValidBST " << ValidateBinarySearchTree.isValidBST(root) << endl;

    // 408题目测试 二叉树存储在数组中
    // vector<int> v_list{3, 1, 5, 0, 2, 4, 6};
    // vector<int> v_list{2, 1, 3};
    vector<int> v_list{5, 1, 4, -1, -1, 3, 6};
    int list_len = v_list.size();
    TreeList *t_list = new TreeList(v_list, list_len);
    L098ValidateBST408 ValidateBST408;
    cout << "true=" << true << "  isBST " << ValidateBST408.isBST(t_list) << endl;

    return 0;
}