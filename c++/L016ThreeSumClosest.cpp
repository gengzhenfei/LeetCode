#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class L016ThreeSumClosest
{
private:
    /* data */
public:
    L016ThreeSumClosest(/* args */);
    ~L016ThreeSumClosest();

    int threeSumClosest(vector<int> &nums, int target)
    {
        vector<int> v_nums = nums;
        int nums_len = nums.size();
        int result;
        int closest = INT_MAX;
        // 先排序
        sort(v_nums.begin(), v_nums.end());
        // 从头开始往后遍历
        for (int k = 0; k < nums_len; k++) {
            if (k > 0 && v_nums[k] == v_nums[k - 1]) continue;
            // 双指针
            int i = k + 1, j = nums_len - 1;
            while (i < j) {
                int sum = v_nums[k] + v_nums[i] + v_nums[j];
                if (sum - target == 0) {
                    return target;
                } else if (sum - target > 0) {
                    // j 指针移动并跳过重复值
                    j--;
                    while (i < j && v_nums[j] == v_nums[j + 1]) { j--; }
                } else {
                    // i 指针移动并跳过重复值
                    i++;
                    while (i < j && v_nums[i] == v_nums[i - 1]) { i++; }
                }
                // 更新最接近的值
                if (abs(sum - target) < closest) {
                    result = sum;
                    closest = abs(sum - target);
                }
            }
        }
        return result;
    }
};

L016ThreeSumClosest::L016ThreeSumClosest(/* args */) {}

L016ThreeSumClosest::~L016ThreeSumClosest() {}

// #include <iostream>
// #include "L016ThreeSumClosest.cpp"
// using namespace std;

// int main()
// {
//     vector<int> list{0, 0, 0};
//     int target = 1;
//     L016ThreeSumClosest ThreeSumClosest;
//     cout << "ThreeSumClosest.threeSumClosest(list, target) " << ThreeSumClosest.threeSumClosest(list, target) << endl;

//     return 0;
// }