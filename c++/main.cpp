// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L040CombinationSum2.cpp"
using namespace std;

int main()
{
    vector<int> candidates{3, 1, 3, 5, 1, 1};
    int target = 8;
    L040CombinationSum2 CombinationSum2;
    vector<vector<int>> result = CombinationSum2.combinationSum2(candidates, target);
    for (auto r : result) { CombinationSum2.printVector(r); }
    return 0;
}