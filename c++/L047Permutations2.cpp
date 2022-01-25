#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class L047Permutations2
{
private:
    /* data */
public:
    L047Permutations2(/* args */);
    ~L047Permutations2();

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 排序 以便去重
        // dfs(nums, result, vector<int>(), vector<int>(nums.size(), 0));
        perm(result, nums, 0, nums.size() - 1);

        return result;
    }

    /**
     * 通过标记
     */
    void dfs(vector<int> &nums, vector<vector<int>> &result, vector<int> res, vector<int> mark)
    {
        if (res.size() == nums.size()) { // 结束条件
            result.push_back(res);
            return;
        }
        for (int j = 0; j < nums.size(); j++) {
            if (j != 0 && nums[j] == nums[j - 1] && mark[j - 1] != 0) continue; // 跳过重复元素
            if (mark[j] == 0) {
                res.push_back(nums[j]);
                mark[j] = 1;
                dfs(nums, result, res, mark);
                res.pop_back(); // 恢复 以便回溯
                mark[j] = 0; // 恢复 以便回溯
            }
        }
    }

    /**
     * 通过交换
     * ??? nums参数为引用传递，去重代码失效，why?
     */
    void perm(vector<vector<int>> &result, vector<int> nums, int left, int right)
    {
        // cout << "left: " << left << " right: " << right << endl;
        // printVector(nums);
        if (left == right) {
            result.push_back(nums);
            return;
        }
        for (int i = left; i <= right; i++) {
            if (i != left && nums[i] == nums[left]) continue; // 去重
            // cout << "left: " << left << " i: " << i << endl;
            swap(nums[left], nums[i]);
            perm(result, nums, left + 1, right);
            // swap(nums[i], nums[left]); // 回溯。nums参数为引用传递，故需要回溯，如果值传递，则此行代码可省略
        }
        return;
    }

    void printVector(vector<int> v)
    {
        cout << "[";
        for (int i : v) { cout << " " << i; }
        cout << " ]" << endl;
    }
};

L047Permutations2::L047Permutations2(/* args */) {}

L047Permutations2::~L047Permutations2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L047Permutations2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{2, 2, 1, 1};
//     L047Permutations2 Permutations2;
//     vector<vector<int>> result = Permutations2.permuteUnique(nums);
//     for (vector<int> v : result) {
//         cout << "[";
//         for (int i : v) { cout << " " << i; }
//         cout << " ]" << endl;
//     }
//     return 0;
// }