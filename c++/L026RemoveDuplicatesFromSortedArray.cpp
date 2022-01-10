#include <vector>
using namespace std;

class L026RemoveDuplicatesFromSortedArray
{
private:
    /* data */
public:
    L026RemoveDuplicatesFromSortedArray(/* args */);
    ~L026RemoveDuplicatesFromSortedArray();

    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        int dup = 0; // 移除重复数
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) {
                dup++;
            } else if (dup != 0) {
                nums[i - dup] = nums[i];
            }
        }
        return len - dup;
    }
};

L026RemoveDuplicatesFromSortedArray::L026RemoveDuplicatesFromSortedArray(/* args */) {}

L026RemoveDuplicatesFromSortedArray::~L026RemoveDuplicatesFromSortedArray() {}

// #include <iostream>
// #include "L026RemoveDuplicatesFromSortedArray.cpp"
// using namespace std;

// int main()
// {
//     // 构造测试数据
//     vector<int> v{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//     L026RemoveDuplicatesFromSortedArray RemoveDuplicatesFromSortedArray;
//     int result = RemoveDuplicatesFromSortedArray.removeDuplicates(v);
//     cout << result << endl;
//     for (auto i : v) cout << i << endl;

//     return 0;
// }