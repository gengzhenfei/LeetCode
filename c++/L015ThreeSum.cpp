#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class L015ThreeSum
{
private:
    /* data */
public:
    L015ThreeSum(/* args */);
    ~L015ThreeSum();

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> v_nums = nums;
        int nums_len = nums.size();
        vector<vector<int>> result;
        // 先排序
        sort(v_nums.begin(), v_nums.end());
        // 数组长度小于3 或 最大元素小于0 那铁定没戏了
        if (nums_len < 3 || v_nums[nums_len - 1] < 0) return result;
        // 从头开始往后遍历
        for (int k = 0; k < nums_len; k++) {
            if (v_nums[k] > 0) return result; // 头元素大于0 那铁定没戏了
            if (k > 0 && v_nums[k] == v_nums[k - 1]) continue;
            // 双指针
            int i = k + 1, j = nums_len - 1;
            while (i < j) {
                int sum = v_nums[k] + v_nums[i] + v_nums[j];
                if (sum == 0) {
                    // 三数值和等于0
                    vector<int> v{v_nums[k], v_nums[i], v_nums[j]};
                    result.push_back(v);
                    // i 指针移动并跳过重复值
                    i++;
                    while (i < j && v_nums[i] == v_nums[i - 1]) { i++; }
                    // j 指针移动并跳过重复值
                    j--;
                    while (i < j && v_nums[j] == v_nums[j + 1]) { j--; }
                } else if (sum > 0) {
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
        return result;
    }
};

L015ThreeSum::L015ThreeSum(/* args */) {}

L015ThreeSum::~L015ThreeSum() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L015ThreeSum.cpp"
// using namespace std;

// int main()
// {
//     // vector<int> list{-1, 0, 1, 2, -1, -4};
//     // vector<int> list{-1, 0};
//     // vector<int> list{1, -1, -1, 0};
//     vector<int> list{-2, 0, 0, 2, 2};
//     L015ThreeSum ThreeSum;
//     vector<vector<int>> result = ThreeSum.threeSum(list);
//     cout << "result.size() " << result.size() << endl;
//     for (int i = 0; i < result.size(); i++) {
//         cout << "i=" << i << " ";
//         for (auto j : result[i]) cout << j << " ";
//         cout << endl;
//     }

//     return 0;
// }