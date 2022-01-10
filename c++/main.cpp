// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L029DivideTwoIntegers.cpp"
using namespace std;

int main()
{
    int dividend = 2147483647;
    int divisor = 3;
    L029DivideTwoIntegers DivideTwoIntegers;
    int val = DivideTwoIntegers.divide(dividend, divisor);
    cout << "dividend: " << dividend << "\n~|dividend|+1: " << ~abs(dividend) + 1 << endl;
    cout << "val: " << val << endl;
    return 0;
}