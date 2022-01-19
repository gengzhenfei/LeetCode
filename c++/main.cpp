// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L041FirstMissingPositive.cpp"
using namespace std;

int main()
{
    vector<int> nums{0, 2, 2, 1, 1};
    L041FirstMissingPositive FirstMissingPositive;
    int result = FirstMissingPositive.firstMissingPositive(nums);
    cout << result << endl;
    return 0;
}