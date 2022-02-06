#include <iostream>
#include <vector>
using namespace std;

class L057InsertInterval
{
private:
    /* data */
public:
    L057InsertInterval(/* args */);
    ~L057InsertInterval();

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int len = intervals.size();
        if (len == 0) {
            intervals.push_back(newInterval);
            return intervals;
        };
        vector<vector<int>> res;
        vector<vector<int>>::iterator it = intervals.begin();
        // 插入合适的位置
        int i = -1;
        while (i < len - 1 && intervals[++i][0] < newInterval[0]) { it++; }
        intervals.insert(it, newInterval);
        // 进行合并
        len = intervals.size();
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
};

L057InsertInterval::L057InsertInterval(/* args */) {}

L057InsertInterval::~L057InsertInterval() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L057InsertInterval.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
//     vector<int> newInterval{4, 8};
//     // vector<vector<int>> intervals{{1, 3}, {6, 9}};
//     // vector<int> newInterval{2, 5};
//     // vector<vector<int>> intervals{};
//     // vector<int> newInterval{5, 7};
//     // vector<vector<int>> intervals{{1, 5}};
//     // vector<int> newInterval{1, 7};
//     L057InsertInterval InsertInterval;
//     vector<vector<int>> result = InsertInterval.insert(intervals, newInterval);
//     for (auto v : result) {
//         for (int i : v) cout << " " << i;
//         cout << endl;
//     }
//     return 0;
// }