// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L075SortColors.cpp"
using namespace std;

int main()
{
    vector<int> nums{2, 0, 1};
    L075SortColors SortColors;
    SortColors.sortColors(nums);
    for (int i : nums) { cout << i << endl; }
    return 0;
}