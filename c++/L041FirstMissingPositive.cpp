#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class L041FirstMissingPositive
{
private:
    /* data */
public:
    L041FirstMissingPositive(/* args */);
    ~L041FirstMissingPositive();

    /**
     * 最烂的方法：先排序，再遍历查找
     * 不符合题意“时间复杂度O(n)”
     */
    // int firstMissingPositive(vector<int> &nums)
    // {
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] > 0) {
    //             if (nums[i] != 1) { // 第一个正数不等于1
    //                 return 1;
    //             } else {
    //                 int offset = i - nums[i];
    //                 for (; i < nums.size() && i - nums[i] == offset; i++) {
    //                     // 跳过重复的数字
    //                     for (; i < nums.size() - 1 && nums[i] == nums[i + 1]; i++) { offset++; }
    //                 }
    //                 return i - offset;
    //             }
    //         }
    //     }
    //     return 1;
    // }

    /**
     * 原地交换 构建本地哈希数组
     */
    int firstMissingPositive(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) { swap(nums[i], nums[nums[i] - 1]); }
        }
        // for (auto i : nums) cout << i << endl;
        int index = 0;
        for (; index < len && nums[index] == index + 1; index++) {}
        return index + 1;
    }

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

L041FirstMissingPositive::L041FirstMissingPositive(/* args */) {}

L041FirstMissingPositive::~L041FirstMissingPositive() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L041FirstMissingPositive.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{0, 2, 2, 1, 1};
//     L041FirstMissingPositive FirstMissingPositive;
//     int result = FirstMissingPositive.firstMissingPositive(nums);
//     cout << result << endl;
//     return 0;
// }