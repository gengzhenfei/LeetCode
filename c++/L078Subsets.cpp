#include <vector>
using namespace std;

class L078Subsets
{
private:
    /* data */
public:
    L078Subsets(/* args */);
    ~L078Subsets();

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sub;
        vector<vector<int>> res;
        res.push_back(vector<int>()); // 空子集
        for (int k = 1; k <= n; k++) { backtrace(n, k, nums, sub, res, 0); }

        return res;
    }

    void backtrace(int &n, int &k, vector<int> &nums, vector<int> &sub, vector<vector<int>> &res, int last)
    {
        if (sub.size() == k) {
            res.push_back(sub);
            return;
        }
        for (int i = last; i < n; i++) {
            sub.push_back(nums[i]);
            backtrace(n, k, nums, sub, res, i + 1);
            sub.pop_back(); // 还原
        }
        return;
    }
};

L078Subsets::L078Subsets(/* args */) {}

L078Subsets::~L078Subsets() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L078Subsets.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{1, 2, 3};
//     L078Subsets Subsets;
//     vector<vector<int>> res = Subsets.subsets(nums);
//     for (auto v : res) {
//         cout << "[ ";
//         for (int i : v) { cout << i << " "; }
//         cout << "]" << endl;
//     }
//     return 0;
// }