#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

class L029DivideTwoIntegers
{
private:
    /* data */
public:
    L029DivideTwoIntegers(/* args */);
    ~L029DivideTwoIntegers();

    int divide(int dividend, int divisor)
    {
        if (divisor == dividend) { return 1; } // 相等，相除结果为1
        if (divisor == INT_MIN) { return 0; } // 除数为最小int，则相除结果为0
        if (dividend == 0) { return 0; } // 被除数为0，则结果为0
        bool minus = false; // 结果正负标记
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) { minus = true; }
        int val = 0;
        if (dividend == INT_MIN) { // 被除数为最小int
            if (divisor == -1) { return INT_MAX; }
            if (divisor == 1) { return INT_MIN; }
            if (divisor < 0) {
                dividend -= divisor;
                val++;
            } else {
                dividend += divisor;
                val++;
            }
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        // 方法1. 使用位运算
        for (int i = 31; i >= 0; i--) {
            if ((dividend >> i) >= divisor) {
                val += (1 << i);
                dividend -= (divisor << i);
            }
        }
        // 方法2. 使用普通的减法运算-LeetCode 16/992个通过测试用例 超出时间限制!!!!!
        // while (dividend >= divisor) {
        //     dividend -= divisor;
        //     val++;
        // }

        // 结果为负，则将结果取反
        if (minus) { return ~val + 1; }
        return val;
    }
};

L029DivideTwoIntegers::L029DivideTwoIntegers(/* args */) {}

L029DivideTwoIntegers::~L029DivideTwoIntegers() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L029DivideTwoIntegers.cpp"
// using namespace std;

// int main()
// {
//     int dividend = 2147483647;
//     int divisor = 3;
//     L029DivideTwoIntegers DivideTwoIntegers;
//     int val = DivideTwoIntegers.divide(dividend, divisor);
//     cout << "dividend: " << dividend << "\n~|dividend|+1: " << ~abs(dividend) + 1 << endl;
//     cout << "val: " << val << endl;
//     return 0;
// }