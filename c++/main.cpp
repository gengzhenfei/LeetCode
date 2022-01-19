// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L039CombinationSum.cpp"
using namespace std;

int main()
{
    vector<int> candidates{2, 3, 5};
    int target = 8;
    L039CombinationSum CombinationSum;
    vector<vector<int>> result = CombinationSum.combinationSum(candidates, target);
    for (auto r : result) {
        cout << "[";
        for (auto i : r) cout << " " << i;
        cout << " ]" << endl;
    }
    return 0;
}