// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L034FindFirstAndLastPositionOfElementInSortedArray.cpp"
using namespace std;

int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 6;
    L034FindFirstAndLastPositionOfElementInSortedArray FindFirstAndLastPosition;
    vector<int> result = FindFirstAndLastPosition.searchRange(nums, target);
    for (auto i : result) cout << i << endl;
    return 0;
}