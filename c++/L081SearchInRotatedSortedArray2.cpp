#include <vector>
using namespace std;

class L081SearchInRotatedSortedArray2
{
private:
    /* data */
public:
    L081SearchInRotatedSortedArray2(/* args */);
    ~L081SearchInRotatedSortedArray2();

    bool search(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        bool res = false;
        recurse(nums, target, res, s, e);

        return res;
    }

    void recurse(vector<int> &nums, int &target, bool &res, int s, int e)
    {
        if (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                res = true;
                return;
            }
            if (nums[s] < nums[e]) { // s到e序列为递增序列
                if (nums[m] > target) {
                    recurse(nums, target, res, s, m - 1);
                } else {
                    recurse(nums, target, res, m + 1, e);
                }
            } else {
                recurse(nums, target, res, s, m - 1);
                recurse(nums, target, res, m + 1, e);
            }
        }
        return;
    }
};

L081SearchInRotatedSortedArray2::L081SearchInRotatedSortedArray2(/* args */) {}

L081SearchInRotatedSortedArray2::~L081SearchInRotatedSortedArray2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L081SearchInRotatedSortedArray2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{2, 5, 6, 0, 0, 1, 2};
//     int target = 3;
//     L081SearchInRotatedSortedArray2 SearchInRotatedSortedArray2;
//     bool res = SearchInRotatedSortedArray2.search(nums, target);
//     cout << "true:" << true << " " << res << endl;
//     return 0;
// }