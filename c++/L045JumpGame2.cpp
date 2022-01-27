#include <vector>
#include <iostream>

using namespace std;

class L045JumpGame2
{
private:
    /* data */
public:
    L045JumpGame2(/* args */);
    ~L045JumpGame2();

    int jump(vector<int> &nums)
    {
        int j = nums.size() - 1;
        traceback(nums, 0, j, 0);

        return j;
    }

    /**
     * 所有情况都跑一遍 nums数组太长会巨花时间
     */
    // void traceback(vector<int> &nums, int n, int &j, int cj)
    // {
    //     cout << "n: " << n << " j: " << j << " cj: " << cj << endl;
    //     if (n == nums.size() - 1) {
    //         j = min(j, cj);
    //         return;
    //     } else if (n >= nums.size() || cj >= j) {
    //         return;
    //     }
    //     for (int i = 1; i <= nums[n]; i++) { traceback(nums, n + i, j, cj + 1); }
    //     return;
    // }

    /**
     * 贪心算法，每一跳寻找当前最远可跳的距离
     * @param nums 最大跳跃数组
     * @param n 当前位置
     * @param j 最小跳跃次数
     * @param cj 当前跳跃次数
     */
    void traceback(vector<int> &nums, int n, int &j, int cj)
    {
        int len = nums.size();
        // cout << "n: " << n << " j: " << j << " cj: " << cj << endl;
        if (n == len - 1) {
            j = min(j, cj);
            return;
        } else if (n >= len || cj >= j) {
            return;
        }
        int i = 1, mi = n + 1;
        int m = nums[n + 1] + n + 1; // 最远可到达位置
        for (; i <= nums[n]; i++) {
            // cout << "i: " << i << " mi: " << mi << " m: " << m << endl;
            if (n + i >= len - 1) {
                traceback(nums, len - 1, j, cj + 1);
                return;
            } else if (nums[n + i] + n + i >= m) { // 寻找最大可跳跃
                m = nums[n + i] + n + i;
                mi = n + i;
            }
            // cout << "i: " << i << " mi: " << mi << " m: " << m << endl;
        }
        traceback(nums, mi, j, cj + 1);
        return;
    }
};

L045JumpGame2::L045JumpGame2(/* args */) {}

L045JumpGame2::~L045JumpGame2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L045JumpGame2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{4, 1, 1, 3, 1, 1, 1};
//     L045JumpGame2 JumpGame2;
//     int result = JumpGame2.jump(nums);
//     cout << result << endl;
//     return 0;
// }