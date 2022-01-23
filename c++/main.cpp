// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L045JumpGame2.cpp"
using namespace std;

int main()
{
    vector<int> nums{4, 1, 1, 3, 1, 1, 1};
    L045JumpGame2 JumpGame2;
    int result = JumpGame2.jump(nums);
    cout << result << endl;
    return 0;
}