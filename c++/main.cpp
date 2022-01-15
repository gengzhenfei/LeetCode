// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L035SearchInsertPosition.cpp"
using namespace std;

int main()
{
    vector<int> nums{1, 3, 5, 6};
    int target = 0;
    L035SearchInsertPosition SearchInsertPosition;
    int result = SearchInsertPosition.searchInsert(nums, target);
    cout << result << endl;
    return 0;
}