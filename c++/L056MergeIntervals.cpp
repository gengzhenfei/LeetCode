#include <iostream>
#include <vector>
using namespace std;

class L056MergeIntervals
{
private:
    /* data */
public:
    L056MergeIntervals(/* args */);
    ~L056MergeIntervals();

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int len = intervals.size();
        if (len <= 1) return intervals; // 特殊情况
        vector<vector<int>> res;
        // step1. 根据左区间大小排序
        quickSort(intervals, 0, len - 1);
        // step2. 进行合并
        for (int i = 0; i < len - 1; i++) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                int left = intervals[i][0];
                int right = intervals[i][1] >= intervals[i + 1][1] ? intervals[i][1] : intervals[i + 1][1];
                intervals[i] = intervals[i + 1] = vector<int>{left, right};
            } else {
                res.push_back(intervals[i]);
            }
            // cout << "i:" << i << " " << intervals[i][0] << " " << intervals[i][1] << endl;
        }
        res.push_back(intervals[len - 1]);

        return res;
    }

    /**
     * 快速排序 按照左区间
     */
    void quickSort(vector<vector<int>> &intervals, int left, int right)
    {
        if (left >= right) return; // 结束条件
        int pivot = left, l = left, r = right;
        vector<int> pivot_val = intervals[pivot];
        while (left < right) {
            for (; left < right && intervals[right][0] >= pivot_val[0]; right--) {}
            intervals[left] = intervals[right];
            for (; left < right && intervals[left][0] <= pivot_val[0]; left++) {}
            intervals[right] = intervals[left];
        }
        intervals[left] = pivot_val;
        quickSort(intervals, l, left - 1);
        quickSort(intervals, left + 1, r);
    }
};

L056MergeIntervals::L056MergeIntervals(/* args */) {}

L056MergeIntervals::~L056MergeIntervals() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L056MergeIntervals.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
//     L056MergeIntervals MergeIntervals;
//     vector<vector<int>> result = MergeIntervals.merge(intervals);
//     for (auto v : result) {
//         for (int i : v) cout << " " << i;
//         cout << endl;
//     }
//     return 0;
// }