// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L042TrappingRainWater.cpp"
using namespace std;

int main()
{
    // vector<int> height{4, 2, 0, 3, 2, 5};
    vector<int> height{5, 4, 1, 2};
    L042TrappingRainWater TrappingRainWater;
    int result = TrappingRainWater.trap(height);
    cout << result << endl;
    return 0;
}