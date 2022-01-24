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
        dfs(nums, result, vector<int>(), vector<int>(nums.size(), 0));

        return result;
    }

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