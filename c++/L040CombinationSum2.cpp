#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class L040CombinationSum2
{
private:
    /* data */
public:
    L040CombinationSum2(/* args */);
    ~L040CombinationSum2();

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // 排序
        vector<vector<int>> result;
        vector<int> path;
        // printVector(candidates);
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
            // cout << "For " << endl;
            // cout << "i " << i << " c[i] " << c[i] << " index " << index << " sum " << sum << endl;
            // printVector(path);
            if (c[i] + sum <= target) { // 目标范围内，可继续
                path.push_back(c[i]);
                dfs(c, path, result, target, sum + c[i], ++index);
                path.pop_back(); // 回溯 恢复到上层状态
            } else { // 已超出范围，对有序列表，后续元素也一定超出范围，可提前结束
                break;
            }
            // 跳过重复元素
            for (; i + 1 < c.size() && c[i] == c[i + 1]; i++) { index++; }
        }
    }

    void printVector(vector<int> v)
    {
        cout << "[";
        for (auto i : v) cout << " " << i;
        cout << " ]" << endl;
    }
};

L040CombinationSum2::L040CombinationSum2(/* args */) {}

L040CombinationSum2::~L040CombinationSum2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L040CombinationSum2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> candidates{3, 1, 3, 5, 1, 1};
//     int target = 8;
//     L040CombinationSum2 CombinationSum2;
//     vector<vector<int>> result = CombinationSum2.combinationSum2(candidates, target);
//     for (auto r : result) { CombinationSum2.printVector(r); }
//     return 0;
// }