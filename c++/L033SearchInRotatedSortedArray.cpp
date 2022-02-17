#include <vector>
#include <iostream>

using namespace std;

class L033SearchInRotatedSortedArray
{
private:
    /* data */
public:
    L033SearchInRotatedSortedArray(/* args */);
    ~L033SearchInRotatedSortedArray();

    int search(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        int res = -1;
        recurse(nums, target, res, s, e);
        // res = search2(nums, target);

        return res;
    }

    int search2(vector<int> &nums, int target)
    {
        int nums_len = nums.size();
        int start = 0, end = nums_len - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            // cout << "start:" << start << " end:" << end << " mid:" << mid << endl;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > nums[start]) { // nums[mid]左侧为升序
                if (mid != end && (nums[start] > target || nums[mid] < target)) {
                    // 注意 mid != end 否则mid+1>end 越界
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else { // nums[mid] 右侧为升序
                if (mid != start && (nums[mid] > target || nums[end] < target)) {
                    // 注意 mid != start 否则mid+1<start 越界
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // cout << "start:" << start << " end:" << end << " mid:" << mid << endl;
        }
        return -1;
    }

    /**
     * 递归的方式
     */
    void recurse(vector<int> &nums, int &target, int &res, int s, int e)
    {
        if (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                res = m;
                return;
            }
            recurse(nums, target, res, s, m - 1);
            recurse(nums, target, res, m + 1, e);
        }
        return;
    }
};

L033SearchInRotatedSortedArray::L033SearchInRotatedSortedArray(/* args */) {}

L033SearchInRotatedSortedArray::~L033SearchInRotatedSortedArray() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L033SearchInRotatedSortedArray.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{3, 1};
//     int target = 1;
//     L033SearchInRotatedSortedArray SearchInRotatedSortedArray;
//     int result = SearchInRotatedSortedArray.search(nums, target);
//     cout << result << endl;
//     return 0;
// }