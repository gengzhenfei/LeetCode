#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class L018FourSum
{
private:
    /* data */
public:
    L018FourSum(/* args */);
    ~L018FourSum();

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<int> v_nums = nums;
        int nums_len = nums.size();
        vector<vector<int>> result;
        // 先排序
        sort(v_nums.begin(), v_nums.end());
        // 数组长度小于4 那铁定没戏了
        if (nums_len < 4) return result;
        // 从头开始往后遍历
        for (int a = 0; a < nums_len; a++) {
            if (target >= 0 && v_nums[a] > target) return result; // 头元素大于target 那铁定没戏了
            if (a > 0 && v_nums[a] == v_nums[a - 1]) continue;
            for (int b = a + 1; b < nums_len; b++) {
                if (b - a > 1 && v_nums[b] == v_nums[b - 1]) continue;
                int i = b + 1, j = nums_len - 1;
                // 双指针 循环处理， i<j 则继续循环
                while (i < j) {
                    // !!! 好奇怪，这里明明设置long long，结果还是会溢出，why???
                    // LeetCode上报错 runtime error: signed integer overflow: 2000000000 + 1000000000 cannot be represented in type 'int'
                    // 在计算的时候就将参与计算的变量强制类型为long long，否则仍按int计算会溢出
                    // 另一种防溢出思路： a+b==target-i-j 因为最大为10^9, a+b最大也不过2*10^9 < INT_MAX
                    long long sum = (long long)v_nums[a] + (long long)v_nums[b] + (long long)v_nums[i] + (long long)v_nums[j];
                    // cout << sum << endl;
                    if (sum == target) {
                        // 三数值和等于target
                        vector<int> v{v_nums[a], v_nums[b], v_nums[i], v_nums[j]};
                        result.push_back(v);
                        // i 指针移动并跳过重复值
                        i++;
                        while (i < j && v_nums[i] == v_nums[i - 1]) { i++; }
                        // j 指针移动并跳过重复值
                        j--;
                        while (i < j && v_nums[j] == v_nums[j + 1]) { j--; }
                    } else if (sum > target) {
                        // j 指针移动并跳过重复值
                        j--;
                        while (i < j && v_nums[j] == v_nums[j + 1]) { j--; }
                    } else {
                        // i 指针移动并跳过重复值
                        i++;
                        while (i < j && v_nums[i] == v_nums[i - 1]) { i++; }
                    }
                }
            }
        }
        return result;
    }
};

L018FourSum::L018FourSum(/* args */) {}

L018FourSum::~L018FourSum() {}

// #include <iostream>
// #include "L018FourSum.cpp"
// using namespace std;

// int main()
// {
//     // vector<int> nums{1, 0, -1, 0, -2, 2};
//     // int target = 0;
//     // vector<int> nums{2, 2, 2, 2, 2};
//     // int target = 8;
//     // vector<int> nums{-3, -1, 0, 2, 4, 5};
//     // int target = 0;
//     // vector<int> nums{-2, -1, -1, 1, 1, 2, 2};
//     // int target = 0;
//     // vector<int> nums{-1, 0, 1, 2, -1, -4};
//     // int target = -1;
//     // vector<int> nums{1, -2, -5, -4, -3, 3, 3, 5};
//     // int target = -11;
//     // vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
//     vector<int> nums{0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000};
//     int target = 1000000000;
//     L018FourSum FourSum;
//     vector<vector<int>> result = FourSum.fourSum(nums, target);
//     for (auto i : result) {
//         for (auto j : i) cout << j << " ";
//         cout << endl;
//     }

//     return 0;
// }