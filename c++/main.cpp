// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L053MaximumSubarray.cpp"
using namespace std;

int main()
{
    vector<int> nums{5, 4, -1, 7, 8};
    L053MaximumSubarray MaximumSubarray;
    int sum = MaximumSubarray.maxSubArray(nums);
    cout << sum << endl;
    return 0;
}