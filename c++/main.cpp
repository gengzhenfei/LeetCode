// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L057InsertInterval.cpp"
using namespace std;

int main()
{
    vector<vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval{4, 8};
    // vector<vector<int>> intervals{{1, 3}, {6, 9}};
    // vector<int> newInterval{2, 5};
    // vector<vector<int>> intervals{};
    // vector<int> newInterval{5, 7};
    // vector<vector<int>> intervals{{1, 5}};
    // vector<int> newInterval{1, 7};
    L057InsertInterval InsertInterval;
    vector<vector<int>> result = InsertInterval.insert(intervals, newInterval);
    for (auto v : result) {
        for (int i : v) cout << " " << i;
        cout << endl;
    }
    return 0;
}