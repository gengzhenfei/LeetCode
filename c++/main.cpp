// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L070ClimbingStairs.cpp"
using namespace std;

int main()
{
    int x = 45;
    L070ClimbingStairs ClimbingStairs;
    int res = ClimbingStairs.climbStairs(x);
    cout << res << endl;
    return 0;
}