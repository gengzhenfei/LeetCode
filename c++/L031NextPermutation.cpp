#include <vector>

using namespace std;

class L031NextPermutation
{
private:
    /* data */
public:
    L031NextPermutation(/* args */);
    ~L031NextPermutation();

    /**
     * LeetCode 测试用例跑不通
     * 通过测试用例： 154 / 265
     * 输入： [1,3,2]
     * 预期结果： [2,1,3]
     */
    void nextPermutation(vector<int> &nums)
    {
        int exchange = 0;
        int len = nums.size();
        // 冒泡排序思路，但只进行一次交换
        for (int i = len - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                exchange++;
                break;
            }
        }
        if (exchange > 0) return;
        // 冒泡排序一遍之后没有做任何排序，需要逆序
        int half_len = len / 2;
        for (int i = 0; i < half_len; i++) {
            int tmp = nums[i];
            nums[i] = nums[len - 1 - i];
            nums[len - 1 - i] = tmp;
        }
        return;
    }
};

L031NextPermutation::L031NextPermutation(/* args */) {}

L031NextPermutation::~L031NextPermutation() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L031NextPermutation.cpp"
// using namespace std;

// int main()
// {
//     vector<int> v{1, 3, 2};
//     L031NextPermutation NextPermutation;
//     NextPermutation.nextPermutation(v);
//     for (auto i : v) { cout << i << endl; }
//     return 0;
// }