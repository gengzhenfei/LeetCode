// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L050PowxN.cpp"
using namespace std;

int main()
{
    double x = 2;
    int n = -2;
    L050PowxN PowxN;
    double res = PowxN.myPow(x, n);
    cout << res << endl;
    return 0;
}