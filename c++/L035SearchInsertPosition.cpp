#include <vector>
using namespace std;

class L035SearchInsertPosition
{
private:
    /* data */
public:
    L035SearchInsertPosition(/* args */);
    ~L035SearchInsertPosition();

    /**
     * 二分查找
     */
    int searchInsert(vector<int> &nums, int target)
    {
        int nums_len = nums.size();
        int start = 0, end = nums_len - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            // cout << "start:" << start << " end:" << end << " mid:" << mid << endl;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end + 1;
    }
};

L035SearchInsertPosition::L035SearchInsertPosition(/* args */) {}

L035SearchInsertPosition::~L035SearchInsertPosition() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L035SearchInsertPosition.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{1, 3, 5, 6};
//     int target = 0;
//     L035SearchInsertPosition SearchInsertPosition;
//     int result = SearchInsertPosition.searchInsert(nums, target);
//     cout << result << endl;
//     return 0;
// }