#include <vector>

using namespace std;

class L053MaximumSubarray
{
private:
    /* data */
public:
    L053MaximumSubarray(/* args */);
    ~L053MaximumSubarray();

    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0) return 0;
        // int res = subArraySum(nums);
        int res = maxSum(nums, 0, nums.size() - 1);

        return res;
    }

    int subArraySum(vector<int> &nums)
    {
        int res = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum > 0) { //之前元素之和大于0 则可继续加
                sum += nums[i];
            } else { // 之前元素之和小于等于0 则重置sum为当前元素
                sum = nums[i];
            }
            res = max(res, sum); // 取最大
        }
        return res;
    }

    /**
     * 分治算法
     */
    int maxSum(vector<int> &nums, int l, int r)
    {
        if (l == r) return nums[l]; // 递归结束条件
        int m = (l + r) / 2;
        int max_sum = max(maxSum(nums, l, m), maxSum(nums, m + 1, r));

        int left_max_sum = nums[m];
        int total = 0;
        for (int i = m; i >= l; i--) { left_max_sum = max(left_max_sum, total += nums[i]); }

        int right_max_sum = nums[m + 1];
        total = 0;
        for (int i = m + 1; i <= r; i++) { right_max_sum = max(right_max_sum, total += nums[i]); }

        return max(max_sum, left_max_sum + right_max_sum);
    }
};

L053MaximumSubarray::L053MaximumSubarray(/* args */) {}

L053MaximumSubarray::~L053MaximumSubarray() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L053MaximumSubarray.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{5, 4, -1, 7, 8};
//     L053MaximumSubarray MaximumSubarray;
//     int sum = MaximumSubarray.maxSubArray(nums);
//     cout << sum << endl;
//     return 0;
// }