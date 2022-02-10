// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L069Sqrtx.cpp"
using namespace std;

int main()
{
    int x = 6;
    L069Sqrtx Sqrtx;
    int res = Sqrtx.mySqrt(x);
    cout << res << endl;
    return 0;
}