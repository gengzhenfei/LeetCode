// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L033SearchInRotatedSortedArray.cpp"
using namespace std;

int main()
{
    vector<int> nums{3, 1};
    int target = 1;
    L033SearchInRotatedSortedArray SearchInRotatedSortedArray;
    int result = SearchInRotatedSortedArray.search(nums, target);
    cout << result << endl;
    return 0;
}