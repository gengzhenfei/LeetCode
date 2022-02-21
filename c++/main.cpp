// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L088MergeSortedArray.cpp"
using namespace std;

int main()
{
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3, n = 3;
    L088MergeSortedArray MergeSortedArray;
    MergeSortedArray.merge2(nums1, m, nums2, n);
    for (int i : nums1) cout << i << endl;
    return 0;
}