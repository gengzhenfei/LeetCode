#include <vector>
#include <algorithm>
using namespace std;

class L039CombinationSum
{
private:
    /* data */
public:
    L039CombinationSum(/* args */);
    ~L039CombinationSum();

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // 排序
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates, path, result, target, 0, 0);

        return result;
    }

    /**
     * 深度优先搜索 注意回溯时恢复状态
     * @param vector<int> c 候选列表
     * @param vector<int> path 已搜索路径
     * @param vector<vector<int>> result 符合条件的结果
     * @param int target 目标值
     * @param int sum 当前已搜索路径的元素和
     * @param int index 当前索引
     */
    void dfs(vector<int> &c, vector<int> &path, vector<vector<int>> &result, int target, int sum, int index)
    {
        if (sum == target) { // 递归结束条件
            result.push_back(path);
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = index; i < c.size(); i++) {
            if (c[i] + sum <= target) { // 目标范围内，可继续
                path.push_back(c[i]);
                dfs(c, path, result, target, sum + c[i], index);
                path.pop_back(); // 回溯 恢复到上层状态
                index++;
            } else { // 已超出范围，对有序列表，后续元素也一定超出范围，可提前结束
                break;
            }
        }
    }
};

L039CombinationSum::L039CombinationSum(/* args */) {}

L039CombinationSum::~L039CombinationSum() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L039CombinationSum.cpp"
// using namespace std;

// int main()
// {
//     vector<int> candidates{2, 3, 5};
//     int target = 8;
//     L039CombinationSum CombinationSum;
//     vector<vector<int>> result = CombinationSum.combinationSum(candidates, target);
//     for (auto r : result) {
//         cout << "[";
//         for (auto i : r) cout << " " << i;
//         cout << " ]" << endl;
//     }
//     return 0;
// }