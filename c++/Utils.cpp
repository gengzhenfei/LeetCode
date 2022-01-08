#include <vector>
#include <string>
#include <iostream>
#include "UtilsStruct.cpp"

using namespace std;

class Utils
{
private:
public:
    Utils(/* args */);
    ~Utils();
    /* 二叉树的数组存储结构转链式存储 */
    static TreeNode *array2BTree(vector<string> list, int index = 0);
    /* vector int 数组转单链表 */
    static ListNode *vector2ListNode(vector<int> v);
    /* 数组转单链表 */
    static ListNode *array2Link(int arr[], int len);
    /* 打印单链表 */
    static void printLink(ListNode *head);
};

Utils::Utils(/* args */) {}

Utils::~Utils() {}
/**
 * 二叉树的数组存储转为链式存储
 */
TreeNode *Utils::array2BTree(vector<string> list, int index)
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

// 数组转链表 用于构造测试用例
ListNode *Utils::array2Link(int arr[], int len)
{
    if (len == 0) { return nullptr; }
    ListNode *l1, *p1;
    l1 = p1 = new ListNode(arr[0]);
    for (int i = 1; i < len; i++) {
        p1->next = new ListNode(arr[i]);
        p1 = p1->next;
    }
    return l1;
}

// 打印链表 用于测试打印链表
void Utils::printLink(ListNode *head)
{
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
}

/**
 * vector int 数组转单链表
 */
ListNode *Utils::vector2ListNode(vector<int> v)
{
    int v_len = v.size();
    if (v_len == 0) { return nullptr; }
    ListNode *head = new ListNode(v[0]); // 头节点初始化
    ListNode *p = head;
    for (int i = 1; i < v_len; i++) {
        p->next = new ListNode(v[i]);
        p = p->next;
    }

    return head;
}