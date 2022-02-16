// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L080RemoveDuplicatesFromSortedArray2.cpp"
using namespace std;

int main()
{
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    L080RemoveDuplicatesFromSortedArray2 RemoveDuplicates;
    int res = RemoveDuplicates.removeDuplicates(nums);
    cout << res << endl;
    return 0;
}