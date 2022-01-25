#include <vector>
using namespace std;

class L046Permutations
{
private:
    /* data */
public:
    L046Permutations(/* args */);
    ~L046Permutations();

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        // dfs(nums, result, vector<int>(), vector<int>(nums.size(), 0));
        perm(nums, result, 0, nums.size() - 1);

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
     */
    void perm(vector<int> &nums, vector<vector<int>> &result, int left, int right)
    {
        // cout << "left: " << left << " right: " << right << endl;
        // printVector(nums);
        if (left == right) {
            result.push_back(nums);
            return;
        }
        for (int i = left; i <= right; i++) {
            // cout << "left: " << left << " i: " << i << endl;
            swap(nums[left], nums[i]);
            perm(nums, result, left + 1, right);
            swap(nums[i], nums[left]); // 回溯。nums参数为引用传递，故需要回溯，如果值传递，则此行代码可省略
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

L046Permutations::L046Permutations(/* args */) {}

L046Permutations::~L046Permutations() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L046Permutations.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{0, 1};
//     L046Permutations Permutations;
//     vector<vector<int>> result = Permutations.permute(nums);
//     for (vector<int> v : result) {
//         cout << "[";
//         for (int i : v) { cout << " " << i; }
//         cout << " ]" << endl;
//     }
//     return 0;
// }