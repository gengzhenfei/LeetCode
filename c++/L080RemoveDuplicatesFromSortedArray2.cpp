#include <vector>
using namespace std;

class L080RemoveDuplicatesFromSortedArray2
{
private:
    /* data */
public:
    L080RemoveDuplicatesFromSortedArray2(/* args */);
    ~L080RemoveDuplicatesFromSortedArray2();

    int removeDuplicates(vector<int> &nums)
    {
        int dup = 1;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i - 1] == nums[i]) {
                dup++;
            } else {
                dup = 1;
            }
            if (dup > 2) {
                nums.erase(nums.begin() + i);
                dup--;
            } else {
                i++;
            }
        }
        return nums.size();
    }
};

L080RemoveDuplicatesFromSortedArray2::L080RemoveDuplicatesFromSortedArray2(/* args */) {}

L080RemoveDuplicatesFromSortedArray2::~L080RemoveDuplicatesFromSortedArray2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L080RemoveDuplicatesFromSortedArray2.cpp"
// using namespace std;

// int main()
// {
//     vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
//     L080RemoveDuplicatesFromSortedArray2 RemoveDuplicates;
//     int res = RemoveDuplicates.removeDuplicates(nums);
//     cout << res << endl;
//     return 0;
// }