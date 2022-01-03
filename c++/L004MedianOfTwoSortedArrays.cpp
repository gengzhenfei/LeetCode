#include <iostream>
#include <vector>
using namespace std;

class L004MedianOfTwoSortedArrays
{
private:
    /* data */
public:
    L004MedianOfTwoSortedArrays(/* args */);
    ~L004MedianOfTwoSortedArrays();

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 遍历两个数组 寻找到中位数
        int i = 0, j = 0;
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        // 中位数计数
        int count = (nums1_size + nums2_size) / 2;
        // 标记位，偶or奇
        int flag = (nums1_size + nums2_size) % 2;
        // 寻找两个中间的数
        int med1 = 0, med2 = 0;
        while (i < nums1_size && j < nums2_size && count >= 0) {
            if (nums1[i] > nums2[j]) {
                med1 = med2;
                med2 = nums2[j];
                j++;
            } else {
                med1 = med2;
                med2 = nums1[i];
                i++;
            }
            count--;
        }
        // 以下两个whilea最多执行一个
        while (i < nums1_size && count >= 0) {
            med1 = med2;
            med2 = nums1[i++];
            count--;
        }
        while (j < nums2_size && count >= 0) {
            med1 = med2;
            med2 = nums2[j++];
            count--;
        }
        // 找到中位数
        if (flag == 1)
            return (double)med2;
        else {
            return (double)(med1 + med2) / 2;
        }
    }
};

L004MedianOfTwoSortedArrays::L004MedianOfTwoSortedArrays(/* args */) {}

L004MedianOfTwoSortedArrays::~L004MedianOfTwoSortedArrays() {}

// #include <iostream>
// #include <string>
// #include "L004MedianOfTwoSortedArrays.cpp"
// using namespace std;

// int main()
// {
//     int nums1[] = {1, 2};
//     int nums1_len = end(nums1) - begin(nums1);     // 数组长度
//     vector<int> v_nums1(nums1, nums1 + nums1_len); // 数组复制到vector
//     int nums2[] = {2, 3};
//     int nums2_len = end(nums2) - begin(nums2);     // 数组长度
//     vector<int> v_nums2(nums2, nums2 + nums2_len); // 数组复制到vector
//     L004MedianOfTwoSortedArrays median;
//     cout << median.findMedianSortedArrays(v_nums1, v_nums2) << endl;

//     return 0;
// }