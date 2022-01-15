#include <vector>
#include <iostream>
using namespace std;

class L034FindFirstAndLastPositionOfElementInSortedArray
{
private:
    /* data */
public:
    L034FindFirstAndLastPositionOfElementInSortedArray(/* args */);
    ~L034FindFirstAndLastPositionOfElementInSortedArray();

    /**
     * 二分查找
     */
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int nums_len = nums.size();
        int start = 0, end = nums_len - 1;
        vector<int> result{-1, -1};
        while (start <= end) {
            int mid = (start + end) / 2;
            // cout << "start:" << start << " end:" << end << " mid:" << mid << endl;
            if (nums[mid] == target) {
                int i = mid - 1, j = mid + 1;
                for (; i >= start && nums[i] == target; i--) {};
                for (; j <= end && nums[j] == target; j++) {};
                result.clear();
                result.push_back(i + 1);
                result.push_back(j - 1);
                return result;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};

L034FindFirstAndLastPositionOfElementInSortedArray::L034FindFirstAndLastPositionOfElementInSortedArray(/* args */) {}

L034FindFirstAndLastPositionOfElementInSortedArray::~L034FindFirstAndLastPositionOfElementInSortedArray() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L034FindFirstAndLastPositionOfElementInSortedArray.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{5, 7, 7, 8, 8, 10};
//     int target = 6;
//     L034FindFirstAndLastPositionOfElementInSortedArray FindFirstAndLastPosition;
//     vector<int> result = FindFirstAndLastPosition.searchRange(nums, target);
//     for (auto i : result) cout << i << endl;
//     return 0;
// }