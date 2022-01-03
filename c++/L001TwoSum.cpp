#include <vector>
#include <algorithm>
using namespace std;

class L001TwoSum
{
private:
    /* data */
public:
    L001TwoSum(/* args */);
    ~L001TwoSum();

    // 方法1
    // vector<int> twoSum(vector<int> &nums, int target)
    // {
    //     vector<int> result;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j < nums.size(); j++) {
    //             if (target == nums[i] + nums[j]) {
    //                 result.push_back(i);
    //                 result.push_back(j);
    //                 return result;
    //             }
    //         }
    //     }
    //     return result;
    // }

    // 方法2
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> copy_nums(nums.begin(), nums.end()); // 复制
        vector<int> result;
        // 排序
        sort(copy_nums.begin(), copy_nums.end());
        int i = 0;
        int j = copy_nums.size() - 1;
        // 遍历
        while (i < j) {
            int tmp = copy_nums[i] + copy_nums[j];
            if (tmp == target) {
                // 之和等于目标，查找这两个元素在原始数组里的索引
                return findFromVector(nums, copy_nums[i], copy_nums[j]);
            } else if (tmp > target) {
                // 之和大于目标，则高位索引-1
                j--;
            } else {
                // 之和小于目标，则低位索引+1
                i++;
            }
        }
        return result;
    }
    // 从vector中查找两个元素的索引
    vector<int> findFromVector(vector<int> v, int e1, int e2)
    {
        vector<int> result;
        auto index1 = v.begin();
        auto index2 = v.begin();
        if (e1 == e2) {
            index1 = find(v.begin(), v.end(), e1);
            index2 = find(index1 + 1, v.end(), e2);
        } else {
            index1 = find(v.begin(), v.end(), e1);
            index2 = find(v.begin(), v.end(), e2);
        }
        result.push_back(index1 - v.begin());
        result.push_back(index2 - v.begin());
        return result;
    }
};

L001TwoSum::L001TwoSum(/* args */) {}

L001TwoSum::~L001TwoSum() {}

// main.cpp
// 调试时将下列代码放入main.cpp文件

// #include <iostream>
// #include "L001TwoSum.cpp"
// using namespace std;
// int main()
// {
//     // 001 two sum
//     int nums[] = {1, 2, 3, 3, 9};
//     int nums_len = end(nums) - begin(nums);    // 数组长度
//     vector<int> v_nums(nums, nums + nums_len); // 数组复制到vector
//     int target = 6;
//     // 类实例
//     L001TwoSum TwoSum;
//     vector<int> result = TwoSum.twoSum(v_nums, target);
//     cout << "result size = " << result.size() << endl;
//     for (auto i : result) { cout << i << endl; }
// }