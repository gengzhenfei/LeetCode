// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L056MergeIntervals.cpp"
using namespace std;

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    L056MergeIntervals MergeIntervals;
    vector<vector<int>> result = MergeIntervals.merge(intervals);
    for (auto v : result) {
        for (int i : v) cout << " " << i;
        cout << endl;
    }
    return 0;
}