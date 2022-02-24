#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class L090Subsets2
{
private:
    /* data */
public:
    L090Subsets2(/* args */);
    ~L090Subsets2();

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> sub;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false); // 标记元素是否被访问
        // 回溯方法2
        // backtrace2(nums, used, sub, res, 0);
        // 回溯方法1
        for (int k = 0; k <= nums.size(); k++) { backtrace(k, nums, used, sub, res, 0); }
        return res;
    }

    /**
     * 回溯方法1
     */
    void backtrace(int &k, vector<int> &nums, vector<bool> &used, vector<int> sub, vector<vector<int>> &res, int last)
    {
        if (sub.size() == k) {
            res.push_back(sub);
            return;
        }
        for (int i = last; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                // 去重 与前一个元素相等并且前一个元素未被访问(此时，i与i-1在树的同一层)
                continue;
            }
            sub.push_back(nums[i]);
            used[i] = true;
            backtrace(k, nums, used, sub, res, i + 1);
            used[i] = false;
            sub.pop_back();
        }
    }

    /**
     * 回溯方法2
     */
    void backtrace2(vector<int> &nums, vector<bool> &used, vector<int> sub, vector<vector<int>> &res, int last)
    {
        res.push_back(sub);
        for (int i = last; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                // 去重 与前一个元素相等并且前一个元素未被访问(此时，i与i-1在树的同一层)
                continue;
            }
            sub.push_back(nums[i]);
            used[i] = true;
            backtrace2(nums, used, sub, res, i + 1);
            used[i] = false;
            sub.pop_back();
        }
    }
};

L090Subsets2::L090Subsets2(/* args */) {}

L090Subsets2::~L090Subsets2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L090Subsets2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{2, 1, 2};
//     L090Subsets2 Subsets2;
//     vector<vector<int>> res = Subsets2.subsetsWithDup(nums);
//     for (vector<int> v : res) {
//         cout << "[ ";
//         for (int i : v) cout << i << " ";
//         cout << "]" << endl;
//     }
//     return 0;
// }